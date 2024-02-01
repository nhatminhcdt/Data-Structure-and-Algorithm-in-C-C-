/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/15-caterpillar_method/count_triangles/)
 * 
 * An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if it is possible to build a triangle with sides of lengths A[P], A[Q] and A[R]. In other words, triplet (P, Q, R) is triangular if 0 ? P < Q < R < N and:
 *  A[P] + A[Q] > A[R],
 *  A[Q] + A[R] > A[P],
 *  A[R] + A[P] > A[Q].
 * 
 * @example Consider array A such that:
 *   A[0] = 10    A[1] = 2    A[2] = 5
 *   A[3] = 1     A[4] = 8    A[5] = 12
 * There are four triangular triplets that can be constructed from elements of this array, namely (0, 2, 4), (0, 2, 5), (0, 4, 5), and (2, 4, 5).
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns the number of triangular triplets in this array.
 * 
 * @example Given array A such that:
 *   A[0] = 10    A[1] = 2    A[2] = 5
 *   A[3] = 1     A[4] = 8    A[5] = 12
 * the function should return 4, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [0..1,000];
 *  - each element of array A is an integer within the range [1..1,000,000,000].
 * 
*/

#include <algorithm>


int solution(vector<int> &A) {
  const int kLen = A.size();
  int result = 0;

  // Sort the array
  std::sort(A.begin(), A.end());

  // Iterate over the array
  for (int first = 0; first < kLen - 2; ++first) {
    int third = first + 2;
    for (int second = first + 1; second < kLen - 1; ++second) {
      while (third < kLen && A[first] + A[second] > A[third]) {
        ++third;
      }
      result += third - second - 1;
    }
  }

  return result;
}