/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Uncomment the following line to generate DOT graphs.
//
// #define GRAPH GRAPH

#include "GeneratedUtils.h"

#include "Bridge.h"
#include "TestHarness.h"

#include <gtest/gtest.h>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <thread>

namespace generated_tests {
using namespace android::nn::wrapper;
using namespace test_helper;

void graphDump([[maybe_unused]] const char* name, [[maybe_unused]] const Model& model) {
#ifdef GRAPH
    ::android::nn::bridge_tests::graphDump(
         name,
         reinterpret_cast<const ::android::nn::ModelBuilder*>(model.getHandle()));
#endif
}

template <typename T>
static void print(std::ostream& os, const MixedTyped& test) {
    // dump T-typed inputs
    for_each<T>(test, [&os](int idx, const std::vector<T>& f) {
        os << "    aliased_output" << idx << ": [";
        for (size_t i = 0; i < f.size(); ++i) {
            os << (i == 0 ? "" : ", ") << +f[i];
        }
        os << "],\n";
    });
}

static void printAll(std::ostream& os, const MixedTyped& test) {
    print<float>(os, test);
    print<int32_t>(os, test);
    print<uint8_t>(os, test);
}


// Test driver for those generated from ml/nn/runtime/test/spec
void executeOnce(std::function<void(Model*)> createModel,
                  std::function<bool(int)> isIgnored,
                  std::vector<MixedTypedExample>& examples,
                  std::string dumpFile) {
    Model model;
    createModel(&model);
    model.finish();
    graphDump("", model);
    bool dumpToFile = !dumpFile.empty();

    std::ofstream s;
    if (dumpToFile) {
        s.open(dumpFile, std::ofstream::trunc);
        ASSERT_TRUE(s.is_open());
    }

    int exampleNo = 0;
    Compilation compilation(&model);
    compilation.finish();

    // If in relaxed mode, set the error range to be 5ULP of FP16.
    float fpRange = !model.isRelaxed() ? 1e-5f : 5.0f * 0.0009765625f;
    for (auto& example : examples) {
        SCOPED_TRACE(exampleNo);
        // TODO: We leave it as a copy here.
        // Should verify if the input gets modified by the test later.
        MixedTyped inputs = example.first;
        const MixedTyped& golden = example.second;

        Execution execution(&compilation);

        // Set all inputs
        for_all(inputs, [&execution](int idx, const void* p, size_t s) {
            const void* buffer = s == 0 ? nullptr : p;
            ASSERT_EQ(Result::NO_ERROR, execution.setInput(idx, buffer, s));
        });

        MixedTyped test;
        // Go through all typed outputs
        resize_accordingly(golden, test);
        for_all(test, [&execution](int idx, void* p, size_t s) {
            void* buffer = s == 0 ? nullptr : p;
            ASSERT_EQ(Result::NO_ERROR, execution.setOutput(idx, buffer, s));
        });

        Result r = execution.compute();
        ASSERT_EQ(Result::NO_ERROR, r);

        // Dump all outputs for the slicing tool
        if (dumpToFile) {
            s << "output" << exampleNo << " = {\n";
            printAll(s, test);
            // all outputs are done
            s << "}\n";
        }

        // Filter out don't cares
        MixedTyped filteredGolden = filter(golden, isIgnored);
        MixedTyped filteredTest = filter(test, isIgnored);
        // We want "close-enough" results for float

        compare(filteredGolden, filteredTest, fpRange);
        exampleNo++;
    }
}

void executeMultithreaded(std::function<void(Model*)> createModel,
                          std::function<bool(int)> isIgnored,
                          std::vector<MixedTypedExample>& examples,
                          std::string dumpFile) {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(std::thread([&]() {
            executeOnce(createModel, isIgnored, examples, dumpFile);
        }));
    }
    std::for_each(threads.begin(), threads.end(), [](std::thread& t) {
        t.join();
    });
}

void execute(std::function<void(Model*)> createModel,
             std::function<bool(int)> isIgnored,
             std::vector<MixedTypedExample>& examples,
             std::string dumpFile) {
#ifndef NNTEST_MULTITHREADED
    executeOnce(createModel, isIgnored, examples, dumpFile);
#else  // defined(NNTEST_MULTITHREADED)
    executeMultithreaded(createModel, isIgnored, examples, dumpFile);
#endif  // !defined(NNTEST_MULTITHREADED)
}

}  // namespace generated_tests
