#pragma once

typedef struct ListNode {
  int val;
  struct ListNode *prev;
  struct ListNode *next;
} list_node;

typedef struct LinkedList {
  list_node *front;
  list_node *rear;
  // Don't change the linked-list's size
  int size;
} linked_list;

// Create double-linked-list from an array
linked_list *linked_list_create(int *arr, int len_arr);
// Spread linked-list to an array, length of the array == linked_list.size
int *linked_list_to_array(linked_list *list);

// Return front value of linked-list
int linked_list_get_front(linked_list *list);
// Return rear value of linked-list
int linked_list_get_rear(linked_list *list);

// Push value to front of linked-list
void linked_list_push_front(linked_list *list, int val);
// Push value to the back of linked-list
void linked_list_push_back(linked_list *list, int val);

// Pop value from front of linked-list
void linked_list_pop_front(linked_list *list);
// Pop value from back of linked-list
void linked_list_pop_back(linked_list *list);

// Free the memory of the linked list
void list_node_free(list_node *node);
