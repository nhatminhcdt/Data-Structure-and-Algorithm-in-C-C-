"""
  @file easy_algorithms.py
  @brief Contains easy algorithms from LeetCode.
"""

class EasyAlgorithms(object):
  """
    @class EasyAlgorithms
    @brief Contains easy algorithms from LeetCode.
  """
  def __init__(self):
    pass


  def TwoSumS1(self, nums, target) -> list:
    """
    @brief Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    The order of the result does not matter.
    Args:
      nums (list of int): List of integers.
      target (int): Target sum.
    Returns:
      (list of int): List of indices of the two numbers such that they add up to a specific target.

    @example
    nums = [2, 7, 11, 15]
    target = 18
    result = TwoSumS1(nums, target)
    # Result: [2, 1]
    """
    num_to_index = {}
    for i, num in enumerate(nums):
      complement = target - num            
      if complement in num_to_index:
        return [num_to_index[complement], i]
      num_to_index[num] = i
    return []


  def AddTwoIntegersS2235(self, num1, num2):
    """
    @brief Function to add two integers.
    Args:
      num1 (int): First integer.
      num2 (int): Second integer.
    Returns:
      (int): Sum of two integers.

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
  # Test TwoSumS1
  assert sol.TwoSumS1([2, 7, 11, 15], 18) == [1, 2]
  assert sol.TwoSumS1([2, 7, 11, 15], 9) == [0, 1]
  assert sol.TwoSumS1([2, 7, 11, 15], 26) == [2, 3]
  assert sol.TwoSumS1([2, 7, 11, 15], 17) == [0, 3]
  assert sol.TwoSumS1([2, 7, 11, 15], 13) == [0, 2]
  assert sol.TwoSumS1([2, 7, 11, 15], 22) == [1, 3]
  assert sol.TwoSumS1([2, 7, 11, 15], 0) == []

  # Test AddTwoIntegersS2235
  assert sol.AddTwoIntegersS2235(12, 5) == 17
  assert sol.AddTwoIntegersS2235(-10, 4) == -6
  assert sol.AddTwoIntegersS2235(0, 0) == 0
  assert sol.AddTwoIntegersS2235(0, 1) == 1
  assert sol.AddTwoIntegersS2235(1, 0) == 1

  
  print('All tests passed')