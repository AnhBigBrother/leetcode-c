#pragma once

typedef struct HashTableItem {
  char *key;
  char *val;
} hash_table_item;

typedef struct HashTableLinkedList {
  hash_table_item *item;
  struct HashTableLinkedList *next;
} hash_table_linked_list;

typedef struct HashTable {
  unsigned long capacity;
  unsigned long size;
  hash_table_linked_list **overflow_bucket;
  hash_table_item **items;
} hash_table;

unsigned long hash_function(char *str, unsigned long capacity);

hash_table *hash_table_create(unsigned long capacity);

void hash_table_set(hash_table *table, char *key, char *val);

char *hash_table_get(hash_table *table, char *key);

void hash_table_free(hash_table *table);
