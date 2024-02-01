/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/trainings/7/count_bounded_slices/)
 * 
 * An integer K and a non-empty array A consisting of N integers are given.
 * A pair of integers (P, Q), such that 0 ? P ? Q < N, is called a slice of array A.
 * A bounded slice is a slice in which the difference between the maximum and minimum values in the slice is less than or equal to K. More precisely it is a slice, such that max(A[P], A[P + 1], ..., A[Q]) ? min(A[P], A[P + 1], ..., A[Q]) ? K.
 * The goal is to calculate the number of bounded slices.
 * 
 * @example Consider K = 2 and array A such that:
 *     A[0] = 3
 *     A[1] = 5
 *     A[2] = 7
 *     A[3] = 6
 *     A[4] = 3
 * There are exactly nine bounded slices: (0, 0), (0, 1), (1, 1), (1, 2), (1, 3), (2, 2), (2, 3), (3, 3), (4, 4).
 * 
 * Write a function:
 *  int solution(int K, vector<int> &A);
 * that, given an integer K and a non-empty array A of N integers, returns the number of bounded slices of array A.
 * 
 * If the number of bounded slices is greater than 1,000,000,000, the function should return 1,000,000,000.
 * 
 * @example Given:
 *     A[0] = 3
 *     A[1] = 5
 *     A[2] = 7
 *     A[3] = 6
 *     A[4] = 3
 * the function should return 9, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..100,000];
 *  - K is an integer within the range [0..1,000,000,000];
 *  - each element of array A is an integer within the range [?1,000,000,000..1,000,000,000].
 *
*/

#include <unordered_map>


int solution(int K, vector<int> &A) {
  /**
   * @note Time complexity: O(N**2)
   * 
   */
  
  const int kLen = A.size();
  int result = 0;
  for (int i = 0; i < kLen; i++) {
    int max_val = A[i];
    int min_val = A[i];

    for (int j = i; j < kLen; j++) {
      max_val = max(max_val, A[j]);
      min_val = min(min_val, A[j]);

      if (max_val - min_val <= K) result++;
      else break;
    }
  }

  return result;
}