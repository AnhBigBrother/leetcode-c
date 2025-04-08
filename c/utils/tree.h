#pragma once

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} tree_node;

// Create tree from array
tree_node *tree_create(int *arr, int arrLen);
