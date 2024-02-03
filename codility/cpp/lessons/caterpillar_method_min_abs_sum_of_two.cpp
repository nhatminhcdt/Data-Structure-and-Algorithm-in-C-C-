/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/15-caterpillar_method/min_abs_sum_of_two/)
 * 
 * Let A be a non-empty array consisting of N integers.
 * The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ? P ? Q < N.
 * 
 * @example The following array A:
 *   A[0] =  1
 *   A[1] =  4
 *   A[2] = -3
 * has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
 *  The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
 *  The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
 *  The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (?3)| = 2.
 *  The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
 *  The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (?3)| = 1.
 *  The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(?3) + (?3)| = 6.
 * 
 * Write a function:
 *  class Solution { public int solution(int[] A); }
 * that, given a non-empty array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.
 * 
 * @example Given the following array A:
 *   A[0] =  1
 *   A[1] =  4
 *   A[2] = -3
 * the function should return 1, as explained above.
 * 
 * Given array A:
 *   A[0] = -8
 *   A[1] =  4
 *   A[2] =  5
 *   A[3] =-10
 *   A[4] =  3
 * the function should return |(?8) + 5| = 3.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..100,000];
 *  - each element of array A is an integer within the range [?1,000,000,000..1,000,000,000].
 *
*/

#include <algorithm>


int solution(vector<int> &A) {
  /**
   * @note Time complexity: O(N*log(N))
   * 
   */
  const int kLen = A.size();
  int minimum = abs(A[0]+A[0]);
  std::sort(A.begin(), A.end());

  if (A[0] >= 0) { return A[0]+A[0]; }
  if (A[kLen-1] <= 0) { return abs(A[kLen-1] + A[kLen-1]); }

  int left = 0;
  int right = kLen-1;

  while (left <= right) {
    int sum = A[left] + A[right];
    if (abs(sum) < minimum) { minimum = abs(sum); }
    if (sum > 0) {
      right--; 
    } else if (sum < 0) {
      left++;
    } else {
      break;
    }
  }
  return minimum;
}