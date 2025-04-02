#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// djb2 hash function: http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash_function(char *str, unsigned long long CAP) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    hash %= CAP;
  }
  return hash;
}

// hash-table item
typedef struct HashTableItem {
  char *key;
  char *val;
} hash_table_item;

hash_table_item *hash_table_item_create(char *key, char *val) {
  hash_table_item *item = (hash_table_item *)malloc(sizeof(hash_table_item));
  item->key = (char *)malloc(strlen(key) + 1);
  item->val = (char *)malloc(strlen(val) + 1);
  strcpy(item->key, key);
  strcpy(item->val, val);
  return item;
}

void hash_table_item_free(hash_table_item *item) {
  free(item->key);
  free(item->val);
  free(item);
}

// hash-table linked-list
typedef struct HashTableLinkedList {
  hash_table_item *item;
  struct HashTableLinkedList *next;
} hash_table_linked_list;

hash_table_linked_list *hash_table_linked_list_create() {
  hash_table_linked_list *node =
      (hash_table_linked_list *)malloc(sizeof(hash_table_linked_list));
  return node;
}

hash_table_linked_list *
hash_table_linked_list_insert(hash_table_linked_list *list,
                              hash_table_item *item) {
  if (!list) {
    hash_table_linked_list *head = hash_table_linked_list_create();
    head->item = item;
    head->next = NULL;
    list = head;
    return list;
  }
  hash_table_linked_list *temp = list;
  while (temp->next) {
    temp = temp->next;
  }
  hash_table_linked_list *node = hash_table_linked_list_create();
  node->item = item;
  node->next = NULL;
  temp->next = node;
  return list;
}

void hash_table_linked_list_free(hash_table_linked_list *head) {
  hash_table_linked_list *temp = head;
  while (head) {
    temp = head;
    head = head->next;
    free(temp->item->key);
    free(temp->item->val);
    free(temp->item);
    free(temp);
  }
}

// hash table
typedef struct HashTable {
  unsigned long long size;
  unsigned long long count;
  hash_table_linked_list **overflow_bucket;
  hash_table_item **items;
} hash_table;

hash_table *hash_table_create(unsigned long long size) {
  hash_table *table = (hash_table *)malloc(sizeof(hash_table));
  table->size = size;
  table->count = 0;
  table->items = (hash_table_item **)malloc(size * sizeof(hash_table_item *));
  for (int i = 0; i < size; i++) {
    table->items[i] = NULL;
  }

  hash_table_linked_list **buckets = (hash_table_linked_list **)malloc(
      size * sizeof(hash_table_linked_list *));
  for (int i = 0; i < size; i++) {
    buckets[i] = NULL;
  }
  table->overflow_bucket = buckets;

  return table;
}

void hash_table_set(hash_table *table, char *key, char *val) {
  int idx = hash_function(key, table->size);
  hash_table_item *cur = table->items[idx];
  if (cur == NULL) {
    if (table->count == table->size) {
      printf("Insert Error: Hash Table is full\n");
      return;
    }
    hash_table_item *item = hash_table_item_create(key, val);
    table->items[idx] = item;
    table->count++;
    return;
  }
  if (strcmp(cur->key, key) == 0) {
    strcpy(table->items[idx]->val, val);
    return;
  }
  hash_table_linked_list *head = table->overflow_bucket[idx];
  hash_table_item *item = hash_table_item_create(key, val);
  if (head == NULL) {
    head = hash_table_linked_list_create();
    head->item = item;
    table->overflow_bucket[idx] = head;
    return;
  }
  table->overflow_bucket[idx] = hash_table_linked_list_insert(head, item);
  return;
}

char *hash_table_get(hash_table *table, char *key) {
  int idx = hash_function(key, table->size);
  hash_table_item *item = table->items[idx];
  hash_table_linked_list *head = table->overflow_bucket[idx];
  while (item != NULL) {
    if (strcmp(item->key, key) == 0) {
      return item->val;
    }
    if (head == NULL) {
      return NULL;
    }
    item = head->item;
    head = head->next;
  }
  return NULL;
}

void hash_table_free(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    hash_table_item *item = table->items[i];
    if (item != NULL) {
      hash_table_item_free(item);
    }
  }
  for (int i = 0; i < table->size; i++) {
    hash_table_linked_list *item = table->overflow_bucket[i];
    if (item != NULL) {
      hash_table_linked_list_free(item);
    }
  }
  free(table->overflow_bucket);
  free(table->items);
  free(table);
}