"""
  @file easy_algorithms.py
  @brief Contains easy algorithms from LeetCode.
"""

class EasyAlgorithms(object):
  def AddTwoIntegersS2235(self, num1, num2):
    """
    @brief Function to add two integers.
    :type num1: int
    :type num2: int
    :rtype: int

    @note Constraints: -100 <= num1, num2 <= 100
    @example
    int result = AddTwoIntegersS2235(12, 5);
    // Result: 17

    int result = AddTwoIntegersS2235(-10, 4);
    // Result: -6
    """
    return num1 + num2

if __name__ == '__main__':
  sol = EasyAlgorithms()
  assert sol.AddTwoIntegersS2235(12, 5) == 17
  assert sol.AddTwoIntegersS2235(-10, 4) == -6
  assert sol.AddTwoIntegersS2235(0, 0) == 0
  assert sol.AddTwoIntegersS2235(0, 1) == 1
  assert sol.AddTwoIntegersS2235(1, 0) == 1
  print('All tests passed')