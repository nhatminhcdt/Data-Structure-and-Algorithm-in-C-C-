/***
* include
*/
#include <gtest/gtest.h>

/**
 * DUT & MODEL
*/
#include "../medium_algorithms.h"
#include "gtest_test_template.h"

using namespace gtest_test_template;


/**
 * Align namespace to DUT
*/
namespace medium_algorithms {

/**
 * Test data
 */
// Create input and output linked lists
// Case 1
ListNode* l0_0 = new ListNode(2, new ListNode(4, new ListNode(3)));
ListNode* l0_1 = new ListNode(5, new ListNode(6, new ListNode(4)));
ListNode* l0_2 = new ListNode(7, new ListNode(0, new ListNode(8)));
TwoInputOneOutput<ListNode*, ListNode*, ListNode*> test_AddTwoNumbers_data_1 = {l0_0, l0_1, l0_2};
// Case 2
ListNode* l1_0 = new ListNode(0);
ListNode* l1_1 = new ListNode(0);
ListNode* l1_2 = new ListNode(0);
TwoInputOneOutput<ListNode*, ListNode*, ListNode*> test_AddTwoNumbers_data_2 = {l1_0, l1_1, l1_2};
// Case 3
ListNode* l2_0 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
ListNode* l2_1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
ListNode* l2_2 = new ListNode(8, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1))))))));
TwoInputOneOutput<ListNode*, ListNode*, ListNode*> test_AddTwoNumbers_data_3 = {l2_0, l2_1, l2_2};
// Case 4
ListNode* l3_0 = new ListNode(2, new ListNode(4, new ListNode(9)));
ListNode* l3_1 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));
ListNode* l3_2 = new ListNode(7, new ListNode(0, new ListNode(4, new ListNode(0, new ListNode(1)))));
TwoInputOneOutput<ListNode*, ListNode*, ListNode*> test_AddTwoNumbers_data_4 = {l3_0, l3_1, l3_2};

std::map<const std::string, TwoInputOneOutput<ListNode*, ListNode*, ListNode*>> test_AddTwoNumbers_data = {
  {"AddTwoNumbers_1", test_AddTwoNumbers_data_1},
  {"AddTwoNumbers_2", test_AddTwoNumbers_data_2},
  {"AddTwoNumbers_3", test_AddTwoNumbers_data_3},
  {"AddTwoNumbers_4", test_AddTwoNumbers_data_4},
};

/**
 * Test cases
*/
class GtestMediumAlgorithms : public ::testing::Test {
 protected:
  MediumAlgorithms target_;
  virtual void SetUp() {};
  virtual void TearDown() {};
};


/**
 * Test cases with parameter
 */
template <typename Param>
class GtestMediumAlgorithmsParamBase : public ::testing::WithParamInterface<Param> {};


/**
 * Test AddTwoNumbersS2 cases with parameter
 */
class GtestMediumAlgorithmsParamBase_AddTwoNumberS2 : public GtestMediumAlgorithms,
                                                      public GtestMediumAlgorithmsParamBase<std::pair<const std::string, TwoInputOneOutput<ListNode*, ListNode*, ListNode*>>> {};

TEST_P(GtestMediumAlgorithmsParamBase_AddTwoNumberS2, AddTwoNumbersS2) {
  TwoInputOneOutput<ListNode*, ListNode*, ListNode*> input = GetParam().second;
  ListNode* output = target_.AddTwoNumbersS2(input.input1, input.input2);
  // Compare all values of expected output and actual sum
  while (output != nullptr) {
    EXPECT_EQ(output->val, input.output->val);
    output = output->next;
    input.output = input.output->next;
  }
}

INSTANTIATE_TEST_SUITE_P(GtestMediumAlgorithmsParamBase_AddTwoNumberS2, GtestMediumAlgorithmsParamBase_AddTwoNumberS2,
  ::testing::ValuesIn(test_AddTwoNumbers_data),
  [](const ::testing::TestParamInfo<GtestMediumAlgorithmsParamBase_AddTwoNumberS2::ParamType>& info) {
    return info.param.first;
  }
);

}  // namespace easy_algorithms