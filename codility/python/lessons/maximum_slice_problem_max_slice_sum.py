"""
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/)
 * 
 * A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ? P ? Q < N, is called a slice of array A.
 * The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns the maximum sum of any slice of A.
 * 
 * @example Given array A such that:
 * A[0] = 3  A[1] = 2  A[2] = -6
 * A[3] = 4  A[4] = 0
 * the function should return 5 because:
 * (3, 4) is a slice of A that has sum 4,
 * (2, 2) is a slice of A that has sum ?6,
 * (0, 1) is a slice of A that has sum 5,
 * no other slice of A has sum greater than (0, 1).
 * @note Assumptions:
 *  - N is an integer within the range [1..1,000,000];
 *  - each element of array A is an integer within the range [?1,000,000..1,000,000];
 *  - the result will be an integer within the range [?2,147,483,648..2,147,483,647].
 * 
*/
"""

def solution(A):
  """
  @brief Find the maximum sum of any slice of A
  @note time complexity: O(N)

  Args:
      A (List[int]): input array

  Returns:
      int: the maximum sum of any slice of A
  """

  N = len(A)
  if N == 0: return 0
  max_val = A[0]
  sum_val = 0
  for i in range(0, N):
    sum_val = max(sum_val + A[i], 0)
    max_val = max(max_val, sum_val)

  return max_val