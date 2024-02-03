/***
 * @brief [Task description](https://app.codility.com/programmers/lessons/1-iterations/binary_gap/)
 * A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
 * 
 * @example
 *    - Number 9 has binary representation 1001 and contains a binary gap of length 2.
 *    - Number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
 *    - Number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
 *    - Number 32 has binary representation 100000 and has no binary gaps.
 *    - NUmber 1041 should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
*/

int solution(int N) {
  
  int currentSequence = 0;
  int longestSequence = 0;
  bool isBoundaryFound = false;

  // Iterate through bits of binary
  while (N > 0) {
    // Check if the current bit is 0
    if ((N & 1) == 0) {
      // Increment the current sequence of zeros
      currentSequence++;
    } else {
      if (isBoundaryFound == false) {
        isBoundaryFound = !isBoundaryFound;
      } else {
        // Update the longest sequence
        longestSequence = max(longestSequence, currentSequence);
      }
      // Reset the current sequence
      currentSequence = 0;
    }

    // Right shift
    N >>= 1;
  }

  // Update the longest sequence one more time (in case it ends with zeros)
  longestSequence = max(longestSequence, currentSequence);

  return longestSequence;
}