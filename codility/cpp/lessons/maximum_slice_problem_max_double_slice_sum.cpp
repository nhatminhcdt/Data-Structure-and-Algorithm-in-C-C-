/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/)
 * 
 * A non-empty array A consisting of N integers is given.
 * A triplet (X, Y, Z), such that 0 ? X < Y < Z < N, is called a double slice.
 * The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y ? 1] + A[Y + 1] + A[Y + 2] + ... + A[Z ? 1].
 * 
 * @example Array A such that:
 *     A[0] = 3
 *     A[1] = 2
 *     A[2] = 6
 *     A[3] = -1
 *     A[4] = 4
 *     A[5] = 5
 *     A[6] = -1
 *     A[7] = 2
 * contains the following example double slices:
 *  double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
 *  double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 ? 1 = 16,
 *  double slice (3, 4, 5), sum is 0.
 *  
 * The goal is to find the maximal sum of any double slice.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.
 * 
 * @example Given:
 *     A[0] = 3
 *     A[1] = 2
 *     A[2] = 6
 *     A[3] = -1
 *     A[4] = 4
 *     A[5] = 5
 *     A[6] = -1
 *     A[7] = 2
 * the function should return 17, because no double slice of array A has a sum of greater than 17.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [3..100,000];
 *  - each element of array A is an integer within the range [?10,000..10,000].
 * 
*/

#include 

int solution(vector<int> &A) {
  /**
   * @note Time complexity: O(N)
   * 
   */
  int kSize = A.size();
  if (kSize < 4) return 0;
  vector<int> l_r(kSize, 0), r_l(kSize, 0);

  int sum_val = 0;

  // Calculate the left to right max slice sum
  for (int i = 1; i < kSize - 1; ++i) {
    sum_val = max(0, sum_val + A[i]);
    l_r[i] = sum_val;
  }

  // Calculate the right to left max slice sum
  sum_val = 0;
  for (int i = kSize - 2; i > 0; --i) {
    sum_val = max(0, sum_val + A[i]);
    r_l[i] = sum_val;
  }

  // Calculate the max double slice sum
  int max_val = 0;
  for (int i = 0; i < kSize - 2; ++i) {
    max_val = max(max_val, l_r[i] + r_l[i + 2]);
  }

  return max_val;
}