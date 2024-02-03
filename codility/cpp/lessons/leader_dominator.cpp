/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/8-leader/dominator/)
 * 
 * An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.
 * For example, consider array A such that
 *  A[0] = 3    A[1] = 4    A[2] =  3
 *  A[3] = 2    A[4] = 3    A[5] = -1
 *  A[6] = 3    A[7] = 3
 * The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.
 * 
 * Write a function
 *  int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return ?1 if array A does not have a dominator.
 * 
 * @example Given array A such that
 *  A[0] = 3    A[1] = 4    A[2] =  3
 *  A[3] = 2    A[4] = 3    A[5] = -1
 *  A[6] = 3    A[7] = 3
 * the function may return 0, 2, 4, 6 or 7, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - each element of array A is an integer within the range [?2,147,483,648..2,147,483,647].
 * 
*/

#include <stack>

int solution(vector<int> &A) {
  /**
   * @note Time complexity: O(N)
   * 
   */
  int N = A.size();
  if (N == 0) return -1;
  std::stack<int> stack;
  for (auto a : A) {
    if (stack.empty()) {
      stack.push(a);
    } else {
      if (stack.top() == a) stack.push(a);
      else stack.pop();
    }
  }
  if (stack.empty()) return -1;
  int candidate = stack.top();
  int count = 0;
  int index = -1;
  for (int i = 0; i < N; i++) {
    if (A[i] == candidate) {
      count++;
      index = i;
    }
  }
  if (count > N / 2) return index;
  
  return -1;
}