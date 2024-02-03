/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/)
 * 
 * You are given an array A consisting of N integers.
 * For each number A[i] such that 0 ? i < N, we want to count the number of elements of the array that are not the divisors of A[i].
 * We say that these elements are non-divisors.
 * 
 * @example Consider integer N = 5 and array A such that:
 *     A[0] = 3
 *     A[1] = 1
 *     A[2] = 2
 *     A[3] = 3
 *     A[4] = 6
 * For the following elements:
 * A[0] = 3, the non-divisors are: 2, 6,
 * A[1] = 1, the non-divisors are: 3, 2, 3, 6,
 * A[2] = 2, the non-divisors are: 3, 3, 6,
 * A[3] = 3, the non-divisors are: 2, 6,
 * A[4] = 6, there aren't any non-divisors.
 * 
 * Write a function:
 *  class Solution { public int[] solution(int[] A); }
 * that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.
 * Result array should be returned as an array of integers.
 * 
 * @example Given:
 *     A[0] = 3
 *     A[1] = 1
 *     A[2] = 2
 *     A[3] = 3
 *     A[4] = 6
 * the function should return [2, 4, 3, 2, 0], as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..50,000];
 *  - each element of array A is an integer within the range [1..2 * N].
 * 
*/

#include<algorithm>
#include<numeric>

vector<int> solution(vector<int> &A) {
  /**
   * @note Time complexity: O(N * log(N))
   * 
   */
  vector<int> counts(*max_element(A.begin(), A.end()) + 1, 0);
  vector<int> R;

  int kVec_size = A.size();
  for (int i = 0; i < kVec_size; ++i) counts[A[i]]++;

  for (int i = 0; i < kVec_size; ++i) {
    int div = 0;
    for (int j = 1; j * j <= A[i]; ++j) {
      if (A[i] % j == 0) {
        div += counts[j];
        if (A[i] / j != j) div += counts[A[i] / j];
      }
    }
    R.push_back(kVec_size - div);
  }

  return R;
}