// Generated from unidirectional_sequence_lstm_layer_norm_cifg_peephole.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"

namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole {

void CreateModel(Model *model);
bool is_ignored(int);
std::vector<::test_helper::MixedTypedExample>& get_examples();

TEST_F(GeneratedTests, unidirectional_sequence_lstm_layer_norm_cifg_peephole) {
    execute(CreateModel,
            is_ignored,
            get_examples());
}

} // namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole
TEST_AVAILABLE_SINCE(V1_2, unidirectional_sequence_lstm_layer_norm_cifg_peephole, generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole::CreateModel)

namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole {

void CreateModel_relaxed(Model *model);
bool is_ignored_relaxed(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_relaxed();

TEST_F(GeneratedTests, unidirectional_sequence_lstm_layer_norm_cifg_peephole_relaxed) {
    execute(CreateModel_relaxed,
            is_ignored_relaxed,
            get_examples_relaxed());
}

} // namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole

namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole {

void CreateModel_float16(Model *model);
bool is_ignored_float16(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_float16();

TEST_F(GeneratedTests, unidirectional_sequence_lstm_layer_norm_cifg_peephole_float16) {
    execute(CreateModel_float16,
            is_ignored_float16,
            get_examples_float16());
}

} // namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole
TEST_AVAILABLE_SINCE(V1_2, unidirectional_sequence_lstm_layer_norm_cifg_peephole_float16, generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole::CreateModel_float16)

namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole {

void CreateModel_dynamic_output_shape(Model *model);
bool is_ignored_dynamic_output_shape(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape();

TEST_F(DynamicOutputShapeTest, unidirectional_sequence_lstm_layer_norm_cifg_peephole_dynamic_output_shape) {
    execute(CreateModel_dynamic_output_shape,
            is_ignored_dynamic_output_shape,
            get_examples_dynamic_output_shape());
}

} // namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole

namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole {

void CreateModel_dynamic_output_shape_relaxed(Model *model);
bool is_ignored_dynamic_output_shape_relaxed(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_relaxed();

TEST_F(DynamicOutputShapeTest, unidirectional_sequence_lstm_layer_norm_cifg_peephole_dynamic_output_shape_relaxed) {
    execute(CreateModel_dynamic_output_shape_relaxed,
            is_ignored_dynamic_output_shape_relaxed,
            get_examples_dynamic_output_shape_relaxed());
}

} // namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole

namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole {

void CreateModel_dynamic_output_shape_float16(Model *model);
bool is_ignored_dynamic_output_shape_float16(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_dynamic_output_shape_float16();

TEST_F(DynamicOutputShapeTest, unidirectional_sequence_lstm_layer_norm_cifg_peephole_dynamic_output_shape_float16) {
    execute(CreateModel_dynamic_output_shape_float16,
            is_ignored_dynamic_output_shape_float16,
            get_examples_dynamic_output_shape_float16());
}

} // namespace generated_tests::unidirectional_sequence_lstm_layer_norm_cifg_peephole

