/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/)
 * 
 * An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.
 * A pair of integers (P, Q), such that 0 ? P ? Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.
 * 
 * @example Consider integer M = 6 and array A such that:
 *     A[0] = 3
 *     A[1] = 4
 *     A[2] = 5
 *     A[3] = 5
 *     A[4] = 2
 * There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).
 * The goal is to calculate the number of distinct slices.
 * 
 * Write a function:
 *  int solution(int M, vector<int> &A);
 * that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.
 * If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.
 * 
 * @example Given integer M = 6 and array A such that:
 *     A[0] = 3
 *     A[1] = 4
 *     A[2] = 5
 *     A[3] = 5
 *     A[4] = 2
 * the function should return 9, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..100,000];
 *  - M is an integer within the range [0..100,000];
 *  - each element of array A is an integer within the range [0..M].
 * 
*/


int solution(int M, vector<int> &A) {
  /**
   * @note Time complexity
   * 
   */
  const int kLen = A.size();
  int count = 0;
  int front = 0, back = 0;
  std::vector<bool> seen(M + 1, false);
  
  while (front < kLen && back < kLen) {
    // move front foward as far as posiible
    while (front < kLen && !seen[A[front]]) {
      seen[A[front]] = true;
      count += front - back + 1;
      if (count > 1000000000) return 1000000000;
      ++front;
    }

    // move back to the duplicate element
    while (front < kLen && back < kLen && A[back] != A[front]) {
      seen[A[back]] = false;
      ++back;
    }

    // reset the seen and make back to next number
    seen[A[back]] = false;
    ++back;
  }

  return count;
}