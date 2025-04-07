#pragma once

typedef struct {
  int *representative;
  int size;
} disjoint_set;

disjoint_set *disjoint_set_create(int size);

int disjoint_set_find(disjoint_set *ds, int x);

void disjoint_set_union(disjoint_set *ds, int x, int y);

void disjoint_set_free(disjoint_set *ds);
