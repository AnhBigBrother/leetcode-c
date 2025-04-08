#pragma once

// The heap data structure.
// Use to get MIN/MAX of an group of integers efficiently !
// Don't touch this struct's members, it will make the algorithm broken.
typedef struct Heap {
  int *bucket;
  int size;
  unsigned long capacity;
  int (*comp)(int, int);
} heap;

// Create a heap
// Using `comp` to perform the comparison
heap *heap_create(int(comp)(int, int), unsigned long capacity);

int heap_top(heap *h);

// Push value to the heap
void heap_push(heap *h, int val);

// Pop value from the heap
int heap_pop(heap *h);

// Get heap's length, use to prevent acidently change heap.size
int heap_length(heap *h);

// Free the memory of the heap
void heap_free(heap *h);
