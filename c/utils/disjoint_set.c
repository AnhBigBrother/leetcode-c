#include <stdlib.h>

typedef struct {
  int *representative;
  int size;
} disjoint_set;

disjoint_set *disjoint_set_create(int size) {
  int *rep = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    rep[i] = i;
  }
  disjoint_set *ds = malloc(sizeof(disjoint_set));
  ds->representative = rep;
  ds->size = size;
  return ds;
}

int disjoint_set_find(disjoint_set *ds, int x) {
  int parent = ds->representative[x];
  if (parent == x) {
    return x;
  }
  return disjoint_set_find(ds, parent);
}

void disjoint_set_union(disjoint_set *ds, int x, int y) {
  int px = disjoint_set_find(ds, x);
  int py = disjoint_set_find(ds, x);
  if (px < py) {
    ds->representative[py] = px;
  } else if (px > py) {
    ds->representative[px] = py;
  }
}

void disjoint_set_free(disjoint_set *ds) {
  free(ds->representative);
  free(ds);
}
