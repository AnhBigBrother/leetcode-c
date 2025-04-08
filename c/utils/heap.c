#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void heap_shift_up(heap *this, int idx) {
  if (idx == 0) {
    return;
  }
  int parent = (idx - 1) / 2;
  if (this->comp(this->bucket[parent], this->bucket[idx]) < 0) {
    int temp = this->bucket[parent];
    this->bucket[parent] = this->bucket[idx];
    this->bucket[idx] = temp;
    heap_shift_up(this, parent);
  }
}

void heap_shift_down(heap *this, int idx) {
  int child_idx = 2 * idx + 1;
  if (child_idx >= this->size) {
    return;
  }
  if (2 * idx + 2 < this->size &&
    this->comp(this->bucket[child_idx], this->bucket[2 * idx + 2]) < 0 ) {
    child_idx = 2 * idx + 2;
  }
  if (this->comp(this->bucket[idx], this->bucket[child_idx]) < 0) {
    int temp = this->bucket[idx];
    this->bucket[idx] = this->bucket[child_idx];
    this->bucket[child_idx] = temp;
    heap_shift_down(this, child_idx);
  }
}

heap *heap_create(int(comp)(int, int), unsigned long capacity) {
  heap *h = malloc(sizeof(heap));
  h->bucket = calloc(capacity, sizeof(int));
  h->capacity = capacity;
  h->size = 0;
  h->comp = comp;
  return h;
}

int heap_top(heap *this) {
  if (this->size == 0) {
    printf("Heap is empty!");
    return -1;
  }
  return this->bucket[0];
}

void heap_push(heap *this, int val) {
  if (this->size == this->capacity) {
    printf("Heap is full!");
    return;
  }
  this->bucket[this->size] = val;
  this->size++;
  heap_shift_up(this, this->size - 1);
}

int heap_pop(heap *this) {
  if (this->size == 0) {
    printf("Heap is empty!");
    return -1;
  }
  int res = this->bucket[0];
  this->bucket[0] = this->bucket[this->size - 1];
  this->bucket[this->size - 1] = 0;
  this->size--;
  heap_shift_down(this, 0);
  return res;
}

int heap_length(heap *this) { return this->size; }

void heap_free(heap *this) {
  free(this->bucket);
  free(this);
}
