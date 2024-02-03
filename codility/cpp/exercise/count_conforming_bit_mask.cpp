/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/trainings/9/count_conforming_bitmasks/)
 * 
 * In this problem we consider unsigned 30-bit integers, i.e. all integers B such that 0 ? B < 230.
 * We say that integer A conforms to integer B if, in all positions where B has bits set to 1, A has corresponding bits set to 1.
 * 
 * @example
 *  00 0000 1111 0111 1101 1110 0000 1111(BIN) = 16,244,239 conforms to
 *  00 0000 1100 0110 1101 1110 0000 0001(BIN) = 13,032,961, but
 *  11 0000 1101 0111 0000 1010 0000 0101(BIN) = 819,399,173 does not conform to
 *  00 0000 1001 0110 0011 0011 0000 1111(BIN) = 9,843,471.
 * 
 * Write a function:
 *  int solution(int A, int B, int C);
 * that, given three unsigned 30-bit integers A, B and C, returns the number of unsigned 30-bit integers conforming to at least one of the given integers.
 * 
 * @example For integers:
 *  A = 11 1111 1111 1111 1111 1111 1001 1111(BIN) = 1,073,741,727,
 *  B = 11 1111 1111 1111 1111 1111 0011 1111(BIN) = 1,073,741,631, and
 *  C = 11 1111 1111 1111 1111 1111 0110 1111(BIN) = 1,073,741,679,
 * the function should return 8, since there are 8 unsigned 30-bit integers conforming to A, B or C, namely:
 *  11 1111 1111 1111 1111 1111 0011 1111(BIN) = 1,073,741,631,
 *  11 1111 1111 1111 1111 1111 0110 1111(BIN) = 1,073,741,679,
 *  11 1111 1111 1111 1111 1111 0111 1111(BIN) = 1,073,741,695,
 *  11 1111 1111 1111 1111 1111 1001 1111(BIN) = 1,073,741,727,
 *  11 1111 1111 1111 1111 1111 1011 1111(BIN) = 1,073,741,759,
 *  11 1111 1111 1111 1111 1111 1101 1111(BIN) = 1,073,741,791,
 *  11 1111 1111 1111 1111 1111 1110 1111(BIN) = 1,073,741,807,
 *  11 1111 1111 1111 1111 1111 1111 1111(BIN) = 1,073,741,823.
 * 
 * @note Assumptions:
 *  - A, B and C are integers within the range [0..1,073,741,823].
 *
*/


int zeros(int n) {
  const int kBit_len = 30;
  int res = 0;
  for (int i = 0; i < kBit_len; i++) {
    if (n % 2 == 0) res++;
    n >>= 1;
  }

  return res;
}


int confs(int n) {
  return 1 << zeros(n);
}


int solution(int A, int B, int C) {
  /**
   * @note Time complexity: O(log(A+B+C))
   * 
   */
  int common = confs(A | B) + confs(A | C) + confs(B | C) - confs(A | B | C);
  return confs(A) + confs(B) + confs(C) - common;
}
