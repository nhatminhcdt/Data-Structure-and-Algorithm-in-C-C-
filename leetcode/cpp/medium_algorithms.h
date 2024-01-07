/**
 * @file medium_algorithms.h
 * @brief Contains the medium algorithms from LeetCode.
 * @ref https://leetcode.com/problemset/?page=1&difficulty=MEDIUM
 */

#ifndef LEETCODE_CPP_MEDIUM_ALGORITHMS_H_
#define LEETCODE_CPP_MEDIUM_ALGORITHMS_H_

using namespace std; 


namespace medium_algorithms {
/**
 * @brief ListNode class.
 */
class ListNode {
 public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, medium_algorithms::ListNode *next) : val(x), next(next) {}  
};


/**
 * @brief MediumAlgorithms class.
 */
class MediumAlgorithms {
 public:
  /**
   * @brief Constructor
  */
  MediumAlgorithms();
  /**
   * @brief Destructor
  */
  virtual ~MediumAlgorithms();

  /**
   * @brief init
   * @return true if init successfully, otherwise false.
   */
  virtual bool init();

  /**
   * @brief Solution for the problem 2 Add_Two_Numbers.
   * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
   * and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
   * 
   * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
   * 
   * @example
   * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
   * Output: 7 -> 0 -> 8
   * Explanation: 342 + 465 = 807.
   */
  ListNode* AddTwoNumbersS2(ListNode* l1, ListNode* l2);

};

}  // namespace medium_algorithms

#endif // LEETCODE_CPP_MEDIUM_ALGORITHMS_H_