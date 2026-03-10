#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSymmetric(struct TreeNode* root) {
  if(root == NULL) {
    return true;
  }

  int tack_on = 1;
  int size = 1;
  int active_size = 1;
  int depth = 0;
  struct TreeNode** flatten = malloc(sizeof(struct TreeNode*));
  flatten[0] = root;

while(1) {
    depth++;
    tack_on *= 2;
    flatten = realloc(flatten, sizeof(struct TreeNode*) * (size + tack_on));

    bool nulls = true;
    for(int i = 0; i < tack_on / 2; i++) {
      if(flatten[size + i - (tack_on / 2)] != NULL) {
        struct TreeNode* paste_l = flatten[size + i - (tack_on / 2)]->left;
        struct TreeNode* paste_r = flatten[size + i - (tack_on / 2)]->right;
        flatten[active_size] = paste_l;
        flatten[active_size + 1] = paste_r;
        active_size += 2;
        if(nulls == true && (paste_l != NULL || paste_r != NULL)) {
          nulls = false;
        }
      } else {
        flatten[active_size] = NULL;
        flatten[active_size + 1] = NULL;
        active_size += 2;
      }
    }
    size += tack_on;

    if(nulls) {
      break; // if no more nodes to pursue, finalize list
    }
  }
  depth--;
  size -= tack_on;

  if(depth == 0) {
    return true;
  }

  int floor = 1;
  int thickness = 2;
  for(int i = 0; i < depth; i++) {
    for(int j = 0; j < thickness / 2; j++) {
      if(flatten[floor + j] == NULL || flatten[floor + thickness - j -1 ] == NULL) {
        if(flatten[floor + j] != flatten[floor + thickness - j - 1]) {
          return false;
        }
      } else if(flatten[floor + j]->val != flatten[floor + thickness - j - 1]->val) {
        return false;
      }
    }

    // post
    floor += thickness;
    thickness *= 2;
  }

  return true;
}