/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/)
 * An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A, returns the value of the missing element.
 * 
 * @example
 * given array A such that:
 *  A[0] = 2
 *  A[1] = 3
 *  A[2] = 1
 *  A[3] = 5
 * the function should return 4, as it is the missing element.
 * @note assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - The elements of A are all distinct;
 *  - Each element of array A is an integer within the range [1..(N + 1)].
 * 
*/


#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
  // Implement your solution here
  long long N = A.size();
  long long expected_vec_sum = (N + 1) * (N + 2) / 2;
  // long long vec_sum = accumulate(A.begin(), A.end(), 0);
  long long vec_sum = 0;
  for_each(A.begin(), A.end(), [&](long long i) { vec_sum += i; });

  // Return missing element
  return expected_vec_sum - vec_sum;
}
