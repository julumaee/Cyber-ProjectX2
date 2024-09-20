#include <assert.h>
#include "../src/calculator.h"
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <cstdint>
#include <cstddef>
#include <string>

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
  FuzzedDataProvider fuzzed_data(data, size);
  float number1 = fuzzed_data.ConsumeIntegral<int32_t>();
  float number2 = fuzzed_data.ConsumeIntegral<int32_t>();
  char operation = fuzzed_data.PickValueInArray({'+', '-', '*', '/', '='});

  calculator(number1, operation, number2);
}
