/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/)
 * 
 * Write a function:
 *  int solution(int A, int B, int K);
 * that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.: { i : A ? i ? B, i mod K = 0 }
 * 
 * @example
 * for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10
 * 
 * @note Assumptions:
 *  - A and B are integers within the range [0..2,000,000,000];
 *  - K is an integer within the range [1..2,000,000,000];
 *  - A ? B.
 * 
*/


int solution(int A, int B, int K) {
  // Implement your solution here
    int num_divisible = 0;
    if (A % K == 0) ++num_divisible;
    
    return B/K - A/K + num_divisible;
}
