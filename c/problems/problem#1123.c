#include "../utils/tree.c"
#include <string.h>

typedef struct TreeNode tree_node;

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root) {
  int deep[1001];
  tree_node *queue[1001];
  tree_node *map[1001];
  int parent[1001];
  int queue2[1001];
  for (int i = 0; i < 1001; i++) {
    deep[i] = -1;
    queue[i] = NULL;
    map[i] = NULL;
    parent[i] = -1;
    queue2[i] = -1;
  }
  deep[root->val] = 0;
  queue[0] = root;
  int i = 0;
  int j = 1;
  while (i < 1001 && queue[i] != NULL) {
    tree_node *cur = queue[i];
    map[cur->val] = cur;
    if (cur->left != NULL) {
      parent[cur->left->val] = cur->val;
      deep[cur->left->val] = deep[cur->val] + 1;
      queue[j] = cur->left;
      j++;
    }
    if (cur->right != NULL) {
      parent[cur->right->val] = cur->val;
      deep[cur->right->val] = deep[cur->val] + 1;
      queue[j] = cur->right;
      j++;
    }
    i++;
  }
  int max_deep = 0;
  for (int i = 0; i < 1001; i++) {
    if (deep[i] > max_deep) {
      max_deep = deep[i];
    }
  }
  i = 0;
  j = 0;
  for (int k = 0; k < 1001; k++) {
    if (deep[k] == max_deep) {
      queue2[j] = k;
      j++;
    }
  }
  int ans = root->val;
  while (i < 1001 && queue2[i] > -1) {
    if (i == j - 1) {
      ans = queue2[i];
      break;
    }
    int cur = queue2[i];
    if (parent[cur] != queue2[j - 1]) {
      queue2[j] = parent[cur];
      j++;
    }
    i++;
  }
  return map[ans];
}
