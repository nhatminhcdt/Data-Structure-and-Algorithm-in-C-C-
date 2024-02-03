/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/)
 * 
 * You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:
 *  with your first step you can stand on rung 1 or 2,
 *  if you are on rung K, you can move to rungs K + 1 or K + 2,
 *  finally you have to stand on rung N.
 * Your task is to count the number of different ways of climbing to the top of the ladder.
 * 
 * @example Given N = 4, you have five different ways of climbing, ascending by:
 *  1, 1, 1 and 1 rung,
 *  1, 1 and 2 rungs,
 *  1, 2 and 1 rung,
 *  2, 1 and 1 rungs, and
 *  2 and 2 rungs.
 * Given N = 5, you have eight different ways of climbing, ascending by:
 *  1, 1, 1, 1 and 1 rung,
 *  1, 1, 1 and 2 rungs,
 *  1, 1, 2 and 1 rung,
 *  1, 2, 1 and 1 rung,
 *  1, 2 and 2 rungs,
 *  2, 1, 1 and 1 rungs,
 *  2, 1 and 2 rungs, and
 *  2, 2 and 1 rung.
 * The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.
 * 
 * Write a function:
 *  vector<int> solution(vector<int> &A, vector<int> &B);
 * that, given two non-empty arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].
 * 
 * @example Given L = 5 and:
 *     A[0] = 4   B[0] = 3
 *     A[1] = 4   B[1] = 2
 *     A[2] = 5   B[2] = 4
 *     A[3] = 5   B[3] = 3
 *     A[4] = 1   B[4] = 1
 * the function should return the sequence [5, 1, 8, 0, 1], as explained above.
 * 
 * @note Assumptions:
 *  - L is an integer within the range [1..50,000];
 *  - each element of array A is an integer within the range [1..L];
 *  - each element of array B is an integer within the range [1..30].
 * 
*/


vector<int> solution(vector<int> &A, vector<int> &B) {
  const int kLen = A.size();
  vector<int> result(kLen, 0);
  vector<int> fib(kLen + 2, 0);
  fib[1] = 1;
  // Create a Fibonacci sequence
  for (int i = 2; i < kLen + 2; ++i) fib[i] = (fib[i - 1] + fib[i - 2]);

  // for (int i = 0; i < kLen; ++i) result[i] = fib[A[i] + 1] % pow(2, B[i]);
  // Use bitwise operation to improve performance
  // https://stackoverflow.com/questions/101439/the-most-efficient-way-to-implement-an-integer-based-power-function-powint-int
  for (int i = 0; i < kLen; ++i) result[i] = fib[A[i] + 1] & ((1 << B[i]) - 1);

  return result;
}