/**
 * @file easy_algorithms.h
 * @brief Contains the easy algorithms from LeetCode.
 * @ref https://leetcode.com/problemset/?page=1&difficulty=EASY
 */

#ifndef LEETCODE_CPP_EASY_ALGORITHMS_H_
#define LEETCODE_CPP_EASY_ALGORITHMS_H_

namespace easy_algorithms {

/**
 * @brief EasyAlgorithms class.
 */
class EasyAlgorithms {
 public:
  /**
   * @brief Constructor
  */
  EasyAlgorithms();
  /**
   * @brief Destructor
  */
  virtual ~EasyAlgorithms();

  /**
   * @brief init
   * @return true if init successfully, otherwise false.
   */
  virtual bool init();

  /**
   * @brief Solution for the problem 2235_Add_Two_Integers.
   * @note Constraints: -100 <= num1, num2 <= 100
   * @example
   * int result = addIntegers(12, 5);
   * // Result: 17
   * int result = addIntegers(-10, 4);
   * // Result: -6
   * 
	 * @brief 		Adds two integers.
	 * @param[in] num1 The first integer.
	 * @param[in] num2 The second integer.
	 * @return 		The sum of num1 and num2.
	 */
	int AddTwoIntegersS2235(int num1, int num2);
};

}  // namespace easy_algorithms

#endif // LEETCODE_CPP_EASY_ALGORITHMS_H_