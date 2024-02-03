/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/)
 * 
 * An integer N is given, representing the area of some rectangle.
 * The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).
 * The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.
 * @example Given integer N = 30, rectangles of area 30 are:
 *  (1, 30), with a perimeter of 62,
 *  (2, 15), with a perimeter of 34,
 *  (3, 10), with a perimeter of 26,
 *  (5, 6), with a perimeter of 22.
 * 
 * Write a function:
 *  int solution(int N);
 * that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.
 * 
 * @example Given an integer N = 30, the function should return 22, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..1,000,000,000].
 * 
*/

#include <limits.h>
#include <math.h>

int solution(int N) {
  /**
   * @note Time complexity: O(sqrt(N))
   * 
   */
  int l, w;
  int root = static_cast<int>(sqrt(N));
  int perimeter = INT_MAX;
  for (l = 1; l <= root; l++) {
    if (N % l == 0) {
      w = N / l;
      perimeter = min(perimeter, 2 * (l + w));
    }
  }

  return perimeter;
}