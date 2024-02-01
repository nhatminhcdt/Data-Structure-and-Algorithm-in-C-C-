/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/6-sorting/triangle/)
 * 
 * An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ? P < Q < R < N and:
 * A[P] + A[Q] > A[R],
 * A[Q] + A[R] > A[P],
 * A[R] + A[P] > A[Q].
 * 
 * @example consider array A such that:
 *   A[0] = 10    A[1] = 2    A[2] = 5
 *   A[3] = 1     A[4] = 8    A[5] = 20
 * Triplet (0, 2, 4) is triangular.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
 * 
 * @example given array A such that:
 *   A[0] = 10    A[1] = 2    A[2] = 5
 *   A[3] = 1     A[4] = 8    A[5] = 20
 * the function should return 1, as explained above. Given array A such that:
 *   A[0] = 10    A[1] = 50    A[2] = 5
 *   A[3] = 1
 * the function should return 0.
 * 
 * @note assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - each element of array A is an integer within the range [?2,147,483,648..2,147,483,647].
 * 
*/

#include <algorithm>

int solution(vector<int> &A) {
  /**
   * @note time complexity: O(N*log(N))
   * 
   */
  
  if (A.size() < 3) return 0;

  // Sort the array in ascending order
  sort(A.begin(), A.end());

  for (unsigned int i = 0; i < A.size() - 2; ++i) {
    if (A[i] > A[i + 2] - A[i + 1]) return 1;
  }

  return 0;
}
