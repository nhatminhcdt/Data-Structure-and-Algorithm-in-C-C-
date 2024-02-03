/**
 * @brief Find smallest positive integer not in array
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 * 
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

#include <algorithm>

using namespace std;


int solution(vector<int> &A) {
    // Implement your solution here
    std::sort(A.begin(), A.end());

    int smallest_positive = 1;

    for (int num : A) {
        if (num > smallest_positive) break;
        if (num == smallest_positive) ++smallest_positive;
    }

    return smallest_positive;
}