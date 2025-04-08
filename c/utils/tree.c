#include "tree.h"
#include <stdlib.h>
#include <string.h>

void tree_create_recur(int *arr, int lenArr, int idx, tree_node **node_arr,
                       int nodeArrLen) {
  tree_node **new_node_arr = malloc(2 * nodeArrLen * sizeof(tree_node *));
  int m = 0;
  for (int i = 0; i < nodeArrLen; i++) {
    tree_node *node = node_arr[i];
    if (node == NULL) {
      continue;
    }
    idx++;
    if (idx < lenArr && arr[idx != -1]) {
      tree_node *left = malloc(sizeof(tree_node));
      left->val = arr[idx];
      node->left = left;
      new_node_arr[m] = left;
      m++;
    }
    idx++;
    if (idx < lenArr && arr[idx] != -1) {
      tree_node *right = malloc(sizeof(tree_node));
      right->val = arr[idx];
      node->right = right;
      new_node_arr[m] = right;
      m++;
    }
  }
  if (m > 0) {
    tree_create_recur(arr, lenArr, idx, new_node_arr, m);
  }
}

tree_node *tree_create(int *arr, int arrLen) {
  if (arrLen == 0) {
    return NULL;
  }
  tree_node *root = malloc(sizeof(tree_node));
  tree_node *node_arr[1] = {root};
  tree_create_recur(arr, arrLen, 0, &node_arr[0], 1);
  return root;
}
