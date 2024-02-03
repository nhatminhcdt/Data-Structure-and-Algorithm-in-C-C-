"""
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/8-leader/equi_leader/)
 * 
 * A non-empty array A consisting of N integers is given.
 * The leader of this array is the value that occurs in more than half of the elements of A.
 * An equi leader is an index S such that 0 ? S < N ? 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N ? 1] have leaders of the same value.
 * 
 * @example Given array A such that:
 *     A[0] = 4
 *     A[1] = 3
 *     A[2] = 4
 *     A[3] = 4
 *     A[4] = 4
 *     A[5] = 2
 * we can find two equi leaders:
 *  0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
 *  2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
 * The goal is to count the number of equi leaders.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given a non-empty array A consisting of N integers, returns the number of equi leaders.
 * 
 * @example Given:
 *     A[0] = 4
 *     A[1] = 3
 *     A[2] = 4
 *     A[3] = 4
 *     A[4] = 4
 *     A[5] = 2
 * the function should return 2, as explained above.
 * 
 * Assumptions:
 *  - N is an integer within the range [1..100,000];
 *  - each element of array A is an integer within the range [?1,000,000,000..1,000,000,000].
 * 
*/
"""

def solution(A):
  """
  @brief Find the number of equi leaders
  @note time complexity: O(N)

  Args:
      A (List[int]): input array

  Returns:
      int: the number of equi leaders
  """

  N = len(A)
  if N == 0:
    return 0
  
  # Find the candidate for the dominator
  B = A.copy()
  B.sort()
  c = 1
  leader = 0

  for i in range(1, len(B)):
    if B[i] == B[i-1]:
      c += 1
    else:
      c = 1
    if c*2 > N:
      leader = B[i]
      break

  # Get the number of occurrences of the leader
  count = 0
  for i in range(N):
    if A[i] == leader:
      count += 1

  # Find the equi leaders
  equi_leaders = 0
  left_count = 0
  for i in range(N):
    if A[i] == leader:
      left_count += 1
    if left_count*2 > (i + 1) and (count - left_count) * 2 > (N - i - 1):
      equi_leaders += 1

  return equi_leaders