/***
* include
*/
#include <gtest/gtest.h>

/**
 * DUT & MODEL
*/
#include "../easy_algorithms.h"

/**
 * Align namespace to DUT
*/
namespace easy_algorithms { 

/**
 * Test data structure
 */
struct TwoInputOneOutput {
  int input1;
  int input2;
  int output;
};

/**
 * Test cases
*/
class GtestEasyAlgorithms : public ::testing::Test {
 protected:
  EasyAlgorithms target_;
  virtual void SetUp() {};
  virtual void TearDown() {};
};

/**
 * Test cases with parameter
 */
template <typename Param>
class GtestEasyAlgorithmsParamBase : public ::testing::WithParamInterface<Param> {};

/**
 * Test data
 */
std::map<const std::string, TwoInputOneOutput> test_AddTwoIntegersS2235_data = {
  {"AddTwoIntegersS2235_data_1", {12, 5, 17}},
  {"AddTwoIntegersS2235_data_2", {-10, 4, -6}},
  {"AddTwoIntegersS2235_data_3", {0, 0, 0}},
  {"AddTwoIntegersS2235_data_4", {0, 1, 1}},
  {"AddTwoIntegersS2235_data_5", {1, 0, 1}},
  {"AddTwoIntegersS2235_data_6", {1, 1, 2}},
  {"AddTwoIntegersS2235_data_7", {1, -1, 0}},
  {"AddTwoIntegersS2235_data_8", {-1, 1, 0}},
  {"AddTwoIntegersS2235_data_9", {-1, -1, -2}},
  {"AddTwoIntegersS2235_data_10", {100, 100, 200}},
  {"AddTwoIntegersS2235_data_11", {-100, -100, -200}},
};

/**
 * Test cases with parameter
 */
class GtestEasyAlgorithms_AddTwoIntegersS2235 : public GtestEasyAlgorithms,
                                                public GtestEasyAlgorithmsParamBase<std::pair<const std::string, TwoInputOneOutput>> {};

TEST_P(GtestEasyAlgorithms_AddTwoIntegersS2235, AddTwoIntegersS2235) {
  TwoInputOneOutput input = GetParam().second;
  EXPECT_EQ(target_.AddTwoIntegersS2235(input.input1, input.input2), input.output);
}

INSTANTIATE_TEST_SUITE_P(GtestEasyAlgorithms_AddTwoIntegersS2235, GtestEasyAlgorithms_AddTwoIntegersS2235,
  ::testing::ValuesIn(test_AddTwoIntegersS2235_data),
  [](const ::testing::TestParamInfo<GtestEasyAlgorithms_AddTwoIntegersS2235::ParamType>& info) {
    return info.param.first;
  }
);

}  // namespace easy_algorithms