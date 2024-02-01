"""
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)
 * 
 * A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
 *  S is empty;
 *  S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
 *  S has the form "VW" where V and W are properly nested strings.
 * 
 * @example The string "{[()()]}" is properly nested but "([)()]" is not.
 * 
 * Write a function:
 *  int solution(string &S);
 * that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.
 * 
 * @example Given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
 * 
 * Write an efficient algorithm for the following assumptions:
 *  - N is an integer within the range [0..200,000];
 *  - string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.
 * 
*/
"""

def solution(S):
  """
  @brief Check if a string is properly nested
  @note time complexity: O(N)

  Args:
      S (string): input string

  Returns:
      int: 1 if S is properly nested and 0 otherwise
  """

  if not S:
    return 1

  stack = []

  for c in S:
    if c in ['(', '{', '[']:
      stack.append(c)
    else:
      if not stack:
        return 0
      if c == ')' and stack[-1] != '(':
        return 0
      if c == '}' and stack[-1] != '{':
        return 0
      if c == ']' and stack[-1] != '[':
        return 0
      stack.pop()

  return 1 if not stack else 0