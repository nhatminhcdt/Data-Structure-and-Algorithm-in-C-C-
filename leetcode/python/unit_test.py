import unittest
from utils import TEST_CASES
from easy_algorithms import EasyAlgorithms


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
    :type test_cases: list of tuple of (tuple of int, int)
    :rtype: void
    """
    solution_name = solution.__name__
    num_test_cases = len(test_cases)
    print(f'=== Running {num_test_cases} test cases for {solution_name} ===')
    for test_case in test_cases:
      input_data, expected_result = test_case
      actual_result = solution(input_data[0], input_data[1])
      self.assertEqual(actual_result, expected_result, 'Failed test case: {}'.format(test_case))

  def test_cases(self):
    self.solution = EasyAlgorithms().AddTwoIntegersS2235
    self.run_test_two_input_one_output(self.solution, TEST_CASES['AddTwoIntegersS2235'])


if __name__ == '__main__':
  unittest.main()