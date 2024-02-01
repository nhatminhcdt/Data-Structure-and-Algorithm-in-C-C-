/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/)
 * 
 * A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars on a road.
 * Array A contains only 0s and/or 1s:
 *  0 represents a car traveling east,
 *  1 represents a car traveling west.
 * The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 ? P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.
 * 
 * @example
 * Consider array A such that:
 *  A[0] = 0
 *  A[1] = 1
 *  A[2] = 0
 *  A[3] = 1
 *  A[4] = 1
 * We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given a non-empty array A of N integers, returns the number of pairs of passing cars.
 * The function should return ?1 if the number of pairs of passing cars exceeds 1,000,000,000.
 * For example, given:
 *  A[0] = 0
 *  A[1] = 1
 *  A[2] = 0
 *  A[3] = 1
 *  A[4] = 1
 * the function should return 5, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..100,000];
 *  - Each element of array A is an integer that can have one of the following values: 0, 1.
 * 
*/

using namespace std;

int solution(vector<int> &A) {

  int n = A.size();

  // Count the number of cars traveling east at each position
  std::vector<int> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
  }

  int passing_cars = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i] == 0) passing_cars += prefix_sum[n] - prefix_sum[i];
    if (passing_cars > 1000000000) return -1;
  }

  return passing_cars;
}