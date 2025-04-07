#include "libs/hash_table.h"
#include "libs/tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include problems from 'problems' folder and test here

int main() {
  unsigned long SZ = 1000;
  hash_table *table = hash_table_create(SZ);
  char *key1 = "Tien Anh";
  char *key2 = "Tien Bro";
  hash_table_set(table, key1, "dep trai nhat the gioi!");
  printf("%s: %s\n", key1, hash_table_get(table, key1));
  printf("%s: %s\n", key2, hash_table_get(table, key2));
  hash_table_free(table);

  return 0;
}
