/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/)
 * 
 * The Fibonacci sequence is defined using the following recursive formula:
 *     F(0) = 0
 *     F(1) = 1
 *     F(M) = F(M - 1) + F(M - 2) if M >= 2
 * A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position ?1) and wants to get to the other bank (position N).
 * The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.
 * The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N ? 1 on the river.
 * Array A contains only 0s and/or 1s:
 *  0 represents a position without a leaf;
 *  1 represents a position containing a leaf.
 * The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position ?1 to position N). The frog can jump between positions ?1 and N (the banks of the river) and every position containing a leaf.
 * 
 * @example Consider array A such that:
 *     A[0] = 0
 *     A[1] = 0
 *     A[2] = 0
 *     A[3] = 1
 *     A[4] = 1
 *     A[5] = 0
 *     A[6] = 1
 *     A[7] = 0
 *     A[8] = 0
 *     A[9] = 0
 *     A[10] = 0
 * The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return ?1.
 * 
 * @example Given:
 *     A[0] = 0
 *     A[1] = 0
 *     A[2] = 0
 *     A[3] = 1
 *     A[4] = 1
 *     A[5] = 0
 *     A[6] = 1
 *     A[7] = 0
 *     A[8] = 0
 *     A[9] = 0
 *     A[10] = 0
 * the function should return 3, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - each element of array A is an integer that can have one of the following values: 0, 1.
 * 
*/

enum {
  kNo_leaf = 0,
  kLeaf = 1,
};


int solution(vector<int> &A)  {
  /**
   * @note Time complexity: O(N*log(N))
   * 
   */
  A.push_back(1);
  const unsigned int kLen = A.size();

  vector<float> fib(100, 0);
  const unsigned int kFib_size = fib.size();
  fib[1] = 1;
  for (unsigned int i = 2; i < 100; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (fib[i] > kLen) break;
  }

  fib.erase(fib.begin());
  fib.erase(fib.begin());

  vector<int> reach_steps(kLen, 0);
  for (unsigned int j = 0; j < kLen; j++) {
    if (A[fib[j] - 1] == kLeaf) reach_steps[fib[j] - 1] = 1;
  }
  
  for (unsigned int i = 0; i < kLen; i++) {
    // Skip if no leaf found or reach_steps already set
    if (A[i] == 0 || reach_steps[i] > 0) continue;

    int min_i = -1;
    int min_v = 100000;
    for (unsigned int j = 0; j < kFib_size; j++) {
      int prev_i = i - fib[j];
      if (prev_i < 0) break;
      if (reach_steps[prev_i] > 0 && min_v > reach_steps[prev_i]) {
        min_i = prev_i;
        min_v = reach_steps[prev_i];
      }
    }
    if (min_i != -1) reach_steps[i] = min_v + 1;
  }
  if (reach_steps[kLen - 1] > 0) return reach_steps[kLen - 1];
  return -1;
}