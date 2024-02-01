/**
 * @brief [Task description](https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/)
 * 
 * An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).
 * The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.
 * @example
 * Given
 *  A = [3, 8, 9, 7, 6]
 *  K = 3
 * => the function should return [9, 7, 6, 3, 8]. Three rotations were made:
 *  [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
 *  [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
 *  [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
 *  
 * Given
 *  A = [0, 0, 0]
 *  K = 1
 * => the function should return [0, 0, 0]
 * 
 * Given
 *  A = [1, 2, 3, 4]
 *  K = 4
 * => the function should return [1, 2, 3, 4]
 * 
 * @note Assume that:
 *  - N and K are integers within the range [0..100];
 *  - each element of array A is an integer within the range [?1,000..1,000].
 * 
 */

using namespace std;

vector<int> solution(vector<int> &A, int K) {
  
  int N = A.size();

  // No need to rotate in case of N = 0
  if (N == 0) return A;

  // Calculate the effective rotation times
  K %= N;

  // Create new vector to store the rotated array
  std::vector<int> rotated_vector(N);

  std::copy(A.end() - K, A.end(), rotated_vector.begin());
  std::copy(A.begin(), A.end() - K, rotated_vector.begin() + K);

  return rotated_vector;
}
