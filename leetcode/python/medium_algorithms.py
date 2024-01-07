"""
  @file medium_algorithms.py
  @brief Contains medium algorithms from LeetCode.
"""

from common import *


class MediumAlgorithms(object):
  """
    @class MediumAlgorithms
    @brief Contains medim algorithms from LeetCode.
  """
  def __init__(self):
    pass


  def AddTwoNunmberS2(self, l1: ListNode, l2: ListNode) -> ListNode:
    """
    @brief You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.

    Args:
      l1 (ListNode): First linked list.
      l2 (ListNode): Second linked list.
    Returns:
      (ListNode): Sum of two linked lists.

    @note You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    @example
    l1 = [2, 4, 3]
    l2 = [5, 6, 4]
    result = AddTwoNunmberS2(l1, l2)
    # Result = 342 + 465 = 807 = [7, 0, 8]
    """
    result = ListNode(0)
    curr = result
    carry = 0

    while l1 or l2 or carry:
      if l1:
        carry += l1.val
        l1 = l1.next
      if l2:
        carry += l2.val
        l2 = l2.next
      curr.next = ListNode(carry % 10)
      curr = curr.next
      carry //= 10

    return result.next


if __name__ == '__main__':
  sol = MediumAlgorithms()

  # Test AddTwoNunmberS2
  l1 = ListNode(2, ListNode(4, ListNode(2)))
  l2 = ListNode(5, ListNode(6, ListNode(4)))
  expected_result = ListNode(7, ListNode(0, ListNode(8)))
  actual_result = sol.AddTwoNunmberS2(l1, l2)
  # Assert that each node in the linked list is equal
  while actual_result and expected_result:
    assert actual_result.val == expected_result.val, f'AddTwoNunmberS2 - test failed !'
    actual_result = actual_result.next
    expected_result = expected_result.next
    
  
  print('All tests passed')