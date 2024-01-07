import unittest
from test_utils import *
from easy_algorithms import EasyAlgorithms
from medium_algorithms import MediumAlgorithms


class TestAlgorithms(unittest.TestCase):
  """
  @class TestAlgorithms
  @brief Test class for EasyAlgorithms.
  """
  def setUp(self):
    self.solution = None
    pass

  def tearDown(self):
    pass

  def run_test_two_input_one_output(self, solution, test_cases):
    """
    @brief Run test cases for two input one output functions.
    Args:
      solution (function): Solution function.
      test_cases (list of tuple): Test cases.
    Returns:
      None      
    """
    solution_name = solution.__name__
    num_test_cases = len(test_cases)
    print(f'=== Running {num_test_cases} test cases for {solution_name} ===')
    for test_case in test_cases:
      input_data, expected_result = test_case
      actual_result = solution(input_data[0], input_data[1])

      if isinstance(expected_result, list):
        self.assertListEqual(actual_result, expected_result, 'Failed test case: {}'.format(test_case))
      elif isinstance(expected_result, ListNode):
        while actual_result and expected_result:
          self.assertEqual(actual_result.val, expected_result.val, f'Failed test case: {test_case}')
          actual_result = actual_result.next
          expected_result = expected_result.next
      else:
        self.assertEqual(actual_result, expected_result, 'Failed test case: {}'.format(test_case))

  def test_cases(self):
    self.solution = EasyAlgorithms()
    self.run_test_two_input_one_output(self.solution.TwoSumS1, TEST_CASES['TwoSumS1'])  
    self.run_test_two_input_one_output(self.solution.AddTwoIntegersS2235, TEST_CASES['AddTwoIntegersS2235'])

    self.solution = MediumAlgorithms()
    self.run_test_two_input_one_output(self.solution.AddTwoNunmberS2, TEST_CASES['AddTwoNunmberS2'])


if __name__ == '__main__':
  unittest.main()