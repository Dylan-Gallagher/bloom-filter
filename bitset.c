#include "bitset.h"

// include the standard library header files that we use in this
// program, which are denoted by angle brackets < >
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// define constant dummy values to avoid compiler warnings
static const int dummy_integer_value = -99;
static struct bitset * dummy_pointer_value = NULL;

// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size) {
  // delete the next line when you write your own code here
  return dummy_pointer_value;
}

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this) {
  // delete the next line when you write your own code here
  return dummy_integer_value;
}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this){
  // delete the next line when you write your own code here
  return dummy_integer_value;
}

// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item){
  // delete the next line when you write your own code here
  return dummy_integer_value;
}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item) {
}

// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item) {
}

// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1,
    struct bitset * src2) {
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,
    struct bitset * src2) {
}
