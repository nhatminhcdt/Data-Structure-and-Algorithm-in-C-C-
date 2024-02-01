/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/)
 * 
 * You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.
 * You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.
 * The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.
 * The large sum is the maximal sum of any block.
 * 
 * @example You are given integers K = 3, M = 5 and array A such that:
 *   A[0] = 2
 *   A[1] = 1
 *   A[2] = 5
 *   A[3] = 1
 *   A[4] = 2
 *   A[5] = 2
 *   A[6] = 2
 * The array can be divided, for example, into the following blocks:
 *  [2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
 *  [2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
 *  [2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
 *  [2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
 * The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.
 * 
 * Write a function:
 *  int solution(int K, int M, vector<int> &A);
 * that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.
 * 
 * @example Given K = 3, M = 5 and array A such that:
 *   A[0] = 2
 *   A[1] = 1
 *   A[2] = 5
 *   A[3] = 1
 *   A[4] = 2
 *   A[5] = 2
 *   A[6] = 2
 * the function should return 6, as explained above.
 * 
 * @note Assumptions:
 *  - N and K are integers within the range [1..100,000];
 *  - M is an integer within the range [0..10,000];
 *  - each element of array A is an integer within the range [0..M].
 * 
*/


bool is_split_valid(int K, int mid, vector<int> &A) {
  /**
   * @brief Check if the split is valid
   * 
   */
  int sum = 0, count = 0;
  for (auto &a : A) {
    sum += a;
    if (sum > mid) {
      sum = a;
      ++count;
    }
  }

  return count < K;
}


int binary_search(int K, int min_sum, int max_sum, vector<int> &A) {
  /**
   * @brief Search for the minimum large sum
   * 
   */
  int result = max_sum;
  while (min_sum <= max_sum) {
    int mid_sum = (min_sum + max_sum) / 2;
    if (is_split_valid(K, mid_sum, A)) {
      // find smaller mid value
      result = mid_sum;
      max_sum = mid_sum - 1;
    } else {
      // find larger mid value
      min_sum = mid_sum + 1;
    }
  }

  return result;
}


int solution(int K, int M, vector<int> &A) {
  /**
   * @note Time complexity: O(N*log(N+M))
   * 
   */
  const int kLen = A.size();
  int min_sum = 0, max_sum = 0;
  for (auto &a : A) {
    min_sum = std::max(min_sum, a);
    max_sum += a;
  }

  if (K == 1) return max_sum;
  if (K >= kLen) return min_sum;

  return binary_search(K, min_sum, max_sum, A);
}