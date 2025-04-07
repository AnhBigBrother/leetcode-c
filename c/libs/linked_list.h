#pragma once

typedef struct LinkedList {
  int val;
  struct LinkedList *next;
} linked_list;

linked_list *linked_list_create(int *arr, int len_arr);

int *linked_list_to_array(linked_list *head, int *list_size);

void linked_list_free(linked_list *head);
