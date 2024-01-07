from common import *

TEST_CASES = {
  ## @brief Test cases for EasyAlgorithms.
  'TwoSumS1': [
    (([2, 7, 11, 15], 18), [1, 2]),
    (([2, 7, 11, 15], 9), [0, 1]),
    (([2, 7, 11, 15], 26), [2, 3]),
    (([2, 7, 11, 15], 17), [0, 3]),
    (([2, 7, 11, 15], 13), [0, 2]),
    (([2, 7, 11, 15], 22), [1, 3]),
    (([2, 7, 11, 15], 0), []),
  ],

  'AddTwoIntegersS2235': [
    ((12,   5), 17),
    ((-10,  4), -6),
    ((0,    0), 0),
    ((0,    1), 1),
    ((1,    0), 1),
  ],

  ## @brief Test cases for MediumAlgorithms.
  'AddTwoNunmberS2': [
    ((ListNode(2, ListNode(4, ListNode(3))), ListNode(5, ListNode(6, ListNode(4)))), ListNode(7, ListNode(0, ListNode(8)))),
  ]
}