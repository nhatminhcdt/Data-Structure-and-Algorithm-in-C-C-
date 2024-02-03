/**
 * @brief [Task description](https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/)
 * A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
 * @example
 * In array A such that:
 *  A[0] = 9  A[1] = 3  A[2] = 9
 *  A[3] = 3  A[4] = 9  A[5] = 7
 *  A[6] = 9
 * the elements at indexes 0 and 2 have value 9,
 * the elements at indexes 1 and 3 have value 3,
 * the elements at indexes 4 and 6 have value 9,
 * the element at index 5 has value 7 and is unpaired.
 * 
 * Write a function:
 *    int solution(vector<int> &A);
 * that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
 * 
 * @note Each element of array A is an integer within the range [1..1,000,000,000]; all but one of the values in A occur an even number of times.
 * 
 */

using namespace std;


int solution(vector<int> &A) {

  // // Create hash map
  // std::unordered_map<int, int> element_freq;

  // // Update frequency of element
  // for (int i : A) element_freq[i]++;

  // // Find the unpaired element
  // for (auto it : element_freq) {
  //     if (it.second % 2 == 1) return it.first;
  // }

  // // Return -1 in case no unpaired element found
  // return -1;

  int unpaired_element = 0;

  // XOR all elements in the array
  for (int i : A) {
    unpaired_element ^= i;
  }

  return unpaired_element;

}