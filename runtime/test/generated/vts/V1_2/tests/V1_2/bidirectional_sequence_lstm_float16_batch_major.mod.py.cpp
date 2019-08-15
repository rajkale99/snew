// Generated from bidirectional_sequence_lstm_float16_batch_major.mod.py
// DO NOT EDIT
// clang-format off
#include "GeneratedTests.h"

namespace generated_tests::bidirectional_sequence_lstm_float16_batch_major {

std::vector<::test_helper::MixedTypedExample>& get_examples_blackbox();

} // namespace generated_tests::bidirectional_sequence_lstm_float16_batch_major

namespace android::hardware::neuralnetworks::V1_2::generated_tests::bidirectional_sequence_lstm_float16_batch_major {

Model createTestModel();
bool is_ignored(int);

TEST_F(NeuralnetworksHidlTest, bidirectional_sequence_lstm_float16_batch_major_blackbox) {
  Execute(device,
          createTestModel,
          is_ignored,
          ::generated_tests::bidirectional_sequence_lstm_float16_batch_major::get_examples_blackbox());
}

TEST_F(ValidationTest, bidirectional_sequence_lstm_float16_batch_major_blackbox) {
  const Model model = createTestModel();
  const std::vector<Request> requests = createRequests(::generated_tests::bidirectional_sequence_lstm_float16_batch_major::get_examples_blackbox());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::bidirectional_sequence_lstm_float16_batch_major

namespace generated_tests::bidirectional_sequence_lstm_float16_batch_major {

std::vector<::test_helper::MixedTypedExample>& get_examples_blackbox_dynamic_output_shape();

} // namespace generated_tests::bidirectional_sequence_lstm_float16_batch_major

namespace android::hardware::neuralnetworks::V1_2::generated_tests::bidirectional_sequence_lstm_float16_batch_major {

Model createTestModel_dynamic_output_shape();
bool is_ignored_dynamic_output_shape(int);

TEST_F(DynamicOutputShapeTest, bidirectional_sequence_lstm_float16_batch_major_blackbox_dynamic_output_shape) {
  Execute(device,
          createTestModel_dynamic_output_shape,
          is_ignored_dynamic_output_shape,
          ::generated_tests::bidirectional_sequence_lstm_float16_batch_major::get_examples_blackbox_dynamic_output_shape(), true);
}

TEST_F(ValidationTest, bidirectional_sequence_lstm_float16_batch_major_blackbox_dynamic_output_shape) {
  const Model model = createTestModel_dynamic_output_shape();
  const std::vector<Request> requests = createRequests(::generated_tests::bidirectional_sequence_lstm_float16_batch_major::get_examples_blackbox_dynamic_output_shape());
  validateEverything(model, requests);
}

} // namespace android::hardware::neuralnetworks::V1_2::generated_tests::bidirectional_sequence_lstm_float16_batch_major

