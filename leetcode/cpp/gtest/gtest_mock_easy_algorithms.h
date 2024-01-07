#ifndef LEETCODE_CPP_GTEST_MOCK_EASY_ALGORITHMS_H_
#define LEETCODE_CPP_GTEST_MOCK_EASY_ALGORITHMS_H_

/**
 * include
 */
#include "../easy_algorithms.h"
#include "gmock/gmock.h"

/**
 * Align namespace to DUT
 */
namespace easy_algorithms {

/**
 * Mock class
 */
class GtestMockEasyAlgorithms : EasyAlgorithms {
  public:
    MOCK_METHOD(bool, init, (), (override));
  };
  
}  // namespace easy_algorithms

#endif // LEETCODE_CPP_GTEST_MOCK_EASY_ALGORITHMS_H_