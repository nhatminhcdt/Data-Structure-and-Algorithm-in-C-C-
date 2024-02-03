/***
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

#include <stack>
#include <string>


int solution(string &S) {
  /**
   * @note Time complexity: O(N)
   * 
   */
  if (S.empty()) return 1;

  stack<char> brackets;

  for (char bracket : S) {
    if ((bracket == '(') || (bracket == '[') || (bracket == '{')) {
      // Push the opening brackets to the stack
      brackets.push(bracket);
    } else {
      if (brackets.empty()) return 0;
      
      // Pop the last opening bracket from the stack
      char last_opening = brackets.top();

      // Check if the last opening bracket matches the current closing bracket
      if ((last_opening != '(' && bracket == ')') ||
          (last_opening != '[' && bracket == ']') ||
          (last_opening != '{' && bracket == '}')) {
        return 0;        
      } else {
        brackets.pop();
      }
    }
  }

  // If the stack is not empty, then there are some opening brackets left
  return brackets.empty() ? 1 : 0;
}