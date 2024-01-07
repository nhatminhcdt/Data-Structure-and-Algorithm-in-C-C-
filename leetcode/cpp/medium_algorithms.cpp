/**
 * @file medium_algorithms.cpp
 * @brief medium_algorithms implementation.
 */

#include "medium_algorithms.h"

namespace medium_algorithms {

/**
 * Constructor
 */
MediumAlgorithms::MediumAlgorithms() {}

/**
 * Destructor
 */
MediumAlgorithms::~MediumAlgorithms() {}

/**
 * Initialize
 */
bool MediumAlgorithms::init() {
	return true;
}

/**
 * Solution for the problem 2 Add_Two_Numbers. * 
 */
ListNode* MediumAlgorithms::AddTwoNumbersS2(ListNode* l1, ListNode* l2) {
  ListNode* result = new ListNode(0);
  ListNode* p_result = result;
  int carry = 0;

  while (l1 || l2 || carry) {
    int d1 = l1 ? l1->val : 0;
    int d2 = l2 ? l2->val : 0;
    int sum = d1 + d2 + carry;
    carry = sum / 10;
    p_result->next = new ListNode(sum % 10);
    p_result = p_result->next;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
  }  

  return result->next;
}

}  // namespace easy