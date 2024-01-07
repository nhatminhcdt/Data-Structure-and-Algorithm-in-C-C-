/***
* include
*/
#include <gtest/gtest.h>

/**
 * DUT & MODEL
*/
#include "../easy_algorithms.h"
#include "gtest_test_template.h"

using namespace gtest_test_template;


/**
 * Align namespace to DUT
*/
namespace easy_algorithms {

/**
 * Test data
 */
std::map<const std::string, TwoInputOneOutput<std::vector<int>, int, std::vector<int>>> test_TwoSumS1_data = {
  {"TwoSumS1_data_1", {{1, 2, 6, 5, 3}, 3, {1, 0}}},
  {"TwoSumS1_data_2", {{1, 2, 6, 5, 3}, 8, {2, 1}}},
  {"TwoSumS1_data_3", {{1, 2, 6, 5, 3}, 11, {3, 2}}},
  {"TwoSumS1_data_4", {{1, 2, 6, 5, 3}, 9, {4, 2}}},
  {"TwoSumS1_data_5", {{1, 2, 6, 5, 3}, 7, {2, 0}}},
  {"TwoSumS1_data_6", {{1, 2, 6, 5, 3}, 6, {3, 0}}},
  {"TwoSumS1_data_7", {{1, 2, 6, 5, 3}, 5, {4, 1}}},
  {"TwoSumS1_data_8", {{1, 2, 6, 5, 3}, 4, {4, 0}}},
  {"TwoSumS1_data_9", {{1, 2, 6, 5, 3}, 2, {}}},
  {"TwoSumS1_data_10", {{1, 2, 6, 5, 3}, 1, {}}},
  {"TwoSumS1_data_11", {{1, 2, 6, 5, 3}, 0, {}}},
  {"TwoSumS1_data_12", {{1, 2, 6, 5, 3}, -1, {}}},
  {"TwoSumS1_data_13", {{1, 2, 6, 5, 3}, -2, {}}},
  {"TwoSumS1_data_14", {{1, 2, 6, 5, 3}, 20, {}}},
};


std::map<const std::string, TwoInputOneOutput<int, int, int>> test_AddTwoIntegersS2235_data = {
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
 * Test TwoSumS1 cases with parameter
 */
class GtestEasyAlgorithms_TwoSumS1 : public GtestEasyAlgorithms,
                                      public GtestEasyAlgorithmsParamBase<std::pair<const std::string, TwoInputOneOutput<std::vector<int>, int, std::vector<int>>>> {};

TEST_P(GtestEasyAlgorithms_TwoSumS1, TwoSumS1) {
  TwoInputOneOutput<std::vector<int>, int, std::vector<int>> input = GetParam().second;
  EXPECT_EQ(target_.TwoSumS1(input.input1, input.input2), input.output);
}

INSTANTIATE_TEST_SUITE_P(GtestEasyAlgorithms_TwoSumS1, GtestEasyAlgorithms_TwoSumS1,
  ::testing::ValuesIn(test_TwoSumS1_data),
  [](const ::testing::TestParamInfo<GtestEasyAlgorithms_TwoSumS1::ParamType>& info) {
    return info.param.first;
  }
);


/**
 * Test AddTwoIntegersS2235 cases with parameter
 */
class GtestEasyAlgorithms_AddTwoIntegersS2235 : public GtestEasyAlgorithms,
                                                public GtestEasyAlgorithmsParamBase<std::pair<const std::string, TwoInputOneOutput<int, int, int>>> {};

TEST_P(GtestEasyAlgorithms_AddTwoIntegersS2235, AddTwoIntegersS2235) {
  TwoInputOneOutput<int, int, int> input = GetParam().second;
  EXPECT_EQ(target_.AddTwoIntegersS2235(input.input1, input.input2), input.output);
}

INSTANTIATE_TEST_SUITE_P(GtestEasyAlgorithms_AddTwoIntegersS2235, GtestEasyAlgorithms_AddTwoIntegersS2235,
  ::testing::ValuesIn(test_AddTwoIntegersS2235_data),
  [](const ::testing::TestParamInfo<GtestEasyAlgorithms_AddTwoIntegersS2235::ParamType>& info) {
    return info.param.first;
  }
);

}  // namespace easy_algorithms