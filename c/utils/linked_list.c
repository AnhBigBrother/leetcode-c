#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linked_list *linked_list_create(int *arr, int len_arr) {
  linked_list *list = malloc(sizeof(linked_list));
  list->front = NULL;
  list->rear = NULL;
  list->size = 0;
  return list;
}
int *linked_list_to_array(linked_list *list) {
  int *ans = malloc(sizeof(int) * list->size);
  list_node *p = list->front;
  int i = 0;
  while (p != NULL) {
    ans[i] = p->val;
    p = p->next;
    i++;
  }
  return ans;
}

int linked_list_get_front(linked_list *list) {
  if (list->size == 0) {
    printf("Linked-list is empty!");
    return -1;
  }
  return list->front->val;
}
int linked_list_get_rear(linked_list *list) {
  if (list->size == 0) {
    printf("Linked-list is empty!");
    return -1;
  }
  return list->rear->val;
}

void linked_list_push_front(linked_list *list, int val) {
  list_node *node = malloc(sizeof(list_node));
  node->val = val;
  list->size++;
  if (list->front == NULL && list->rear == NULL) {
    list->front = node;
    list->rear = node;
    return;
  }
  list->front->prev = node;
  node->next = list->front;
  list->front = node;
}
void linked_list_push_back(linked_list *list, int val) {
  list_node *node = malloc(sizeof(list_node));
  node->val = val;
  list->size++;
  if (list->front == NULL && list->rear == NULL) {
    list->front = node;
    list->rear = node;
    return;
  }
  list->rear->next = node;
  node->prev = list->rear;
  list->rear = node;
}

void linked_list_pop_front(linked_list *list) {
  if (list->size == 0) {
    printf("Linked-list is empty!");
    return;
  }
  list->size--;
  if (list->front == list->rear) {
    free(list->front);
    list->front = NULL;
    list->rear = NULL;
    list->size = 0;
    return;
  }
  list_node *node = list->front->next;
  free(list->front);
  node->prev = NULL;
  list->front = node;
}
void linked_list_pop_back(linked_list *list) {
  if (list->size == 0) {
    printf("Linked-list is empty!");
    return;
  }
  list->size--;
  if (list->rear == list->front) {
    free(list->rear);
    list->front = NULL;
    list->rear = NULL;
    list->size = 0;
    return;
  }
  list_node *node = list->rear->prev;
  free(list->rear);
  node->next = NULL;
  list->rear = node;
}

void linked_list_free(linked_list *list) {
  list_node *p = list->front;
  while (p != NULL) {
    list_node *n = p->next;
    free(p);
    p = n;
  }
  free(list);
}
