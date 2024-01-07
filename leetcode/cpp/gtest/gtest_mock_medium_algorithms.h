#ifndef LEETCODE_CPP_GTEST_MOCK_MEDIUM_ALGORITHMS_H_
#define LEETCODE_CPP_GTEST_MOCK_MEDIUM_ALGORITHMS_H_

/**
 * include
 */
#include "../medium_algorithms.h"
#include "gmock/gmock.h"

/**
 * Align namespace to DUT
 */
namespace medium_algorithms {

/**
 * Mock class
 */
class GtestMockMediumAlgorithms : MediumAlgorithms {
  public:
    MOCK_METHOD(bool, init, (), (override));
  };
  
}  // namespace medium_algorithms

#endif // LEETCODE_CPP_GTEST_MOCK_MEDIUM_ALGORITHMS_H_