#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*
Question 3: Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.

Examples:

Example 1:
Input:
        1
       / \
      2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents 12.
The root-to-leaf path 1->3 represents 13.
12 + 13 = 25.

Example 2:
Input:
          4
         / \
        9   0
       / \
      5   1
Output: 1026
Explanation:
The numbers are 495, 491, and 40.
495 + 491 + 40 = 1026.

Function to complete:
    int sumNumbers(struct TreeNode* root);

Note:
- Each node stores a digit from 0 to 9.
- If the tree is empty, return 0.
- Build the current number as you move from root to leaf.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct NodeTracker {
  int* summing; 
  int sizing; // starts at 1, not 0 (overshoots summing)
  struct TreeNode *assignment;
};

struct NodeTracker* newTracker(int insert, struct TreeNode *assign) {
  struct NodeTracker* returning = malloc(sizeof(struct NodeTracker));
  returning->sizing= 1;
  returning->summing = malloc(sizeof(int));
  returning->summing[0] = insert;
  returning->assignment = assign;

  return returning;
}

void trackerFwd(struct NodeTracker* tracker, int direction) { // if direction == 1, go left, if == --1, go right
  tracker->sizing = tracker->sizing + 1;
  tracker->summing = realloc(tracker->summing, sizeof(int) * tracker->sizing);
  if(direction == 1) { // left
    tracker->summing[tracker->sizing - 1] = tracker->assignment->left->val;
    tracker->assignment = tracker->assignment->left;
  }
  if(direction == -1) { // right
    tracker->summing[tracker->sizing - 1] = tracker->assignment->right->val;
    tracker->assignment = tracker->assignment->right;
  }
}

struct NodeTracker* cloneTracker(struct NodeTracker* tracker) {
  struct NodeTracker* returning = malloc(sizeof(struct NodeTracker));

  returning->summing = malloc(sizeof(int) * tracker->sizing);
  for(int i = 0; i < tracker->sizing; i++) {
    returning->summing[i] = tracker->summing[i];
  }

  returning->sizing = tracker->sizing;
  returning->assignment = tracker->assignment;

  return returning;
}

// actual function start

int sumNumbers(struct TreeNode* root) {
  if(root == NULL) {
    return 0;
  }

  struct NodeTracker** nodify = malloc(sizeof(struct NodeTracker*));
  nodify[0] = newTracker(root->val, root);

  int nodify_s = 1;

  while(1) {
    int nulls = 1;

    for(int i = nodify_s - 1; i >= 0; i--) { // iterate top to bottom through list of tracker nodes

      if(nodify[i]->assignment->right != NULL && nodify[i]->assignment->left != NULL) {
        struct NodeTracker* clone_r = cloneTracker(nodify[i]); // must clone to extend list
        nulls = 0;

        nodify_s++;
        nodify = realloc(nodify, sizeof(struct NodeTracker*) * nodify_s);
        for(int j = nodify_s - 1; j > i + 1; j--) {
          nodify[j] = nodify[j - 1];
        }
        nodify[i + 1] = clone_r; // if 2 paths are available, must make room for new path and clone to new path


        trackerFwd(nodify[i + 1], -1);
        trackerFwd(nodify[i], 1); // forward lower node left, upper node right

      } else if(nodify[i]->assignment->left != NULL) {
        nulls = 0;


        trackerFwd(nodify[i], 1); // if only left has path, forward left
      } else if(nodify[i]->assignment->right != NULL) {
        nulls = 0;

        trackerFwd(nodify[i], -1); // if only right has path, forward right
      }

    }

    if(nulls == 1) {
      break; // terminate loop once all node trackers have reached endpoints
    }
  }

  // now that tracker list is fully compiled, go through and complete each part of the sum
  int sum = 0;
  for(int i = 0; i < nodify_s; i++) {
    int mult = 1;
    for(int j = nodify[i]->sizing - 1; j >= 0; j--) {
      sum += nodify[i]->summing[j] * mult; // add each digit to the sum based on its position relative to depth
      mult *= 10;
    }
    free(nodify[i]);
  }

  free(nodify);

  return sum;

}