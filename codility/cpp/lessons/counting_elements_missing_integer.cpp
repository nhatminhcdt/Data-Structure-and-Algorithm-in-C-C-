/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/)
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 * @example
 * Given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 * Given A = [1, 2, 3], the function should return 4.
 * Given A = [?1, ?3], the function should return 1.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..100,000];
 *  - Each element of array A is an integer within the range [?1,000,000..1,000,000].
 * 
*/

#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
  std::unordered_set<int> pos_ints;
  for_each (A.begin(), A.end(), [&](int i) { if (i > 0) pos_ints.insert(i); });
  int smallest_pos_int = 1;
  while (pos_ints.count(smallest_pos_int) > 0) {
    smallest_pos_int++;
  }

  return smallest_pos_int;
}