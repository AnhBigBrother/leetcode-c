#include <stdlib.h>

typedef struct LinkedList {
  int val;
  struct LinkedList *next;
} linked_list;

linked_list *linked_list_create(int *arr, int len_arr) {
  linked_list *head = malloc(sizeof(linked_list));
  linked_list *p = head;
  for (int i = 0; i < len_arr - 1; i++) {
    p->val = arr[i];
    p->next = malloc(sizeof(linked_list));
    p = p->next;
  }
  p->val = arr[len_arr - 1];
  return head;
}

int *linked_list_to_array(linked_list *head, int *list_size) {
  int sz = 0;
  linked_list *p = head;
  while (p != NULL) {
    sz++;
    p = p->next;
  }
  *list_size = sz;
  p = head;
  int *res = malloc(sz * sizeof(int));
  int i = 0;
  while (p != NULL) {
    res[i] = p->val;
    i++;
    p = p->next;
  }
  return res;
}

void linked_list_free(linked_list *head) {
  while (head != NULL) {
    linked_list *node = head;
    head = head->next;
    free(node);
    node = NULL;
  }
}
