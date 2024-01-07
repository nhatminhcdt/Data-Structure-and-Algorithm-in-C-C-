#ifndef LEETCODE_CPP_GTEST_TEST_TEMPLATE_H_
#define LEETCODE_CPP_GTEST_TEST_TEMPLATE_H_

/**
 * Test template namespace
 */
namespace gtest_test_template {

/**
 * Test data structure
 */
template <class T1, class T2, class T3>
struct TwoInputOneOutput {
  T1 input1;
  T2 input2;
  T3 output;
};
  
}  // namespace gtest_test_template

#endif // LEETCODE_CPP_GTEST_TEST_TEMPLATE_H_