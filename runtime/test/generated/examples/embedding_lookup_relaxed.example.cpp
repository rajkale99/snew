// clang-format off
// Generated file (from: embedding_lookup_relaxed.mod.py). Do not edit
std::vector<MixedTypedExample>& get_examples() {
static std::vector<MixedTypedExample> examples = {
// Begin of an example
{
.operands = {
//Input(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {{1, {0.0f, 0.01f, 0.02f, 0.03f, 0.1f, 0.11f, 0.12000000000000001f, 0.13f, 1.0f, 1.01f, 1.02f, 1.03f, 1.1f, 1.11f, 1.12f, 1.1300000000000001f, 2.0f, 2.01f, 2.02f, 2.03f, 2.1f, 2.11f, 2.12f, 2.13f}}},
  // int -> INT32 map
  {{0, {1, 0, 2}}},
  // int -> QUANT8_ASYMM map
  {},
  // int -> QUANT16_SYMM map
  {},
  // int -> FLOAT16 map
  {},
  // int -> BOOL8 map
  {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  {},
},
//Output(s)
{ // See tools/test_generator/include/TestHarness.h:MixedTyped
  // int -> FLOAT32 map
  {{0, {1.0f, 1.01f, 1.02f, 1.03f, 1.1f, 1.11f, 1.12f, 1.13f, 0.0f, 0.01f, 0.02f, 0.03f, 0.1f, 0.11f, 0.12f, 0.13f, 2.0f, 2.01f, 2.02f, 2.03f, 2.1f, 2.11f, 2.12f, 2.13f}}},
  // int -> INT32 map
  {},
  // int -> QUANT8_ASYMM map
  {},
  // int -> QUANT16_SYMM map
  {},
  // int -> FLOAT16 map
  {},
  // int -> BOOL8 map
  {},
  // int -> QUANT8_SYMM_PER_CHANNEL map
  {},
}
},
}, // End of an example
};
return examples;
};

