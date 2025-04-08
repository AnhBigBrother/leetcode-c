#pragma once

// Disjoint-set data structure
// Efficient determination of whether two elements belong to the same subset and
// merging subsets
typedef struct {
  int *representative;
  int size;
} disjoint_set;

// Create a disjoint-set data structure
disjoint_set *disjoint_set_create(int size);

// Find the representative of a number x in disjoint-set
int disjoint_set_find(disjoint_set *ds, int x);

// Union group of x and group of y
void disjoint_set_union(disjoint_set *ds, int x, int y);

// Free the memory of the disjoint-set
void disjoint_set_free(disjoint_set *ds);
