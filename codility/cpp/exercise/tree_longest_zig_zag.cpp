/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/trainings/7/tree_longest_zig_zag/)
 * 
 * In this problem we consider binary trees. Let's define a turn on a path as a change in the direction of the path (i.e. a switch from right to left or vice versa). A zigzag is simply a sequence of turns (it can start with either right or left). The length of a zigzag is equal to the number of turns.
 * Consider binary tree below:
 * There are two turns on the marked path. The first one is at [15]; the second is at [30]. That means that the length of this zigzag is equal to 2.
 * This is also the longest zigzag in the tree under consideration. In this problem you should find the longest zigzag that starts at the root of any given binary tree and form a downwards path.
 * Note that a zigzag containing only one edge or one node has length 0.
 * 
 * Write a function:
 *  class Solution { public int solution(Tree T); }
 * that, given a non-empty binary tree T consisting of N nodes, returns the length of the longest zigzag starting at the root.
 * 
 * @example Given tree T shown in the figure above, the function should return 2, as explained above. Note that the values contained in the nodes are not relevant in this task.
 * 
 * A binary tree can be specified using a pointer data structure. Assume that the following declarations are given:
 * class Tree {
 *   public int x;
 *   public Tree l;
 *   public Tree r;
 * }
 * An empty tree is represented by an empty pointer (denoted by null). A non-empty tree is represented by a pointer to an object representing its root. The attribute x holds the integer contained in the root, whereas attributes l and r hold the left and right subtrees of the binary tree, respectively.
 * For the purpose of entering your own test cases, you can denote a tree recursively in the following way. An empty binary tree is denoted by None. A non-empty tree is denoted as (X, L, R), where X is the value contained in the root and L and R denote the left and right subtrees, respectively. The tree from the above figure can be denoted as:
 *   (5, (3, (20, (6, None, None), None), None), (10, (1, None, None), (15, (30, None, (9, None, None)), (8, None, None))))
 * 
 * @note Assumptions
 *  - N is an integer within the range [1..100,000];
 *  - the height of tree T (number of edges on the longest path from root to leaf) is within the range [0..800].
 *
*/

#include <algorithm>


enum {
  kLeft = -1,
  kRight = 1,
  kNeutral = 0
};


class Tree {
  public int x;
  public Tree l;
  public Tree r;
};


int dfs(Tree* tree, int zigzag, int direction) {
  /**
   * @brief Calculate the longest zigzag starting at the root.
   * @param[in] tree The root of the tree.
   * @param[in] zigzag The length of the longest zigzag.
   * @param[in] direction The direction of the last turn. -1: left, 1: right, 0: neutral.   * 
   * @return The length of the longest zigzag
   * 
   * @note Time complexity: O(N)
   */
  int max_val = zigzag;

  if (tree->l != nullptr) {
    int new_zigzag = zigzag;
    if (direction == kRight) new_zigzag++;
    max_val = max(dfs(tree->l, new_zigzag, -1), max_val);
  }

  if (tree->r != nullptr) {
    int new_zigzag = zigzag;
    if (direction == kLeft) new_zigzag++;
    max_val = max(dfs(tree->r, new_zigzag, 1), max_val);
  }

  return max_val;
}


int solution(tree * T) {
  /**
   * @note Time complexity: O(N)
   * 
   */
  if (T == nullptr) return 0;
  return dfs(T, 0, kNeutral);
}