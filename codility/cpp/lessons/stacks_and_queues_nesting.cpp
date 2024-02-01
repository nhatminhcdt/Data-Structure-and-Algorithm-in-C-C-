/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/)
 * 
 * A string S consisting of N characters is called properly nested if:
 *  S is empty;
 *  S has the form "(U)" where U is a properly nested string;
 *  S has the form "VW" where V and W are properly nested strings.
 * 
 * @example String "(()(())())" is properly nested but string "())" isn't.
 * 
 * Write a function:
 *  int solution(string &S);
 * that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.
 * 
 * @example, Given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [0..1,000,000];
 *  - string S is made only of the characters '(' and/or ')'.
 * 
*/

int solution(string &S) {
  /**
   * @note Time complexity: O(N)
   * 
   */
  if (S.empty()) return 1;

  int N = S.size();
  int open_brackets = 0;

  for (int i = 0; i < N; ++i) {
    if (S[i] == '(') {
      // Increase the number of open brackets
      open_brackets++;
    } else {
      // Decrease the number of open brackets
      open_brackets--;

      // If the number of open brackets is negative, then there are more closing brackets than opening brackets
      if (open_brackets < 0) return 0;
    }
  }

  // If the number of open brackets is not zero, then there are more opening brackets than closing brackets
  return open_brackets == 0 ? 1 : 0;
}