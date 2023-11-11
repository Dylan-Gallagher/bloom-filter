#include "bitset.h"

// include the standard library header files that we use in this
// program, which are denoted by angle brackets < >
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size) {
    // bits is a pointer to an array
    // universe_size is the number of bits
    // a word is 64 bits
    // size_in_words = (universe_size / 64) + 1, this is not an error, 
        // it's meant to be integer division, that's why we add 1
    int size_in_words_var = (size / 64);
    if (size % 64 > 0) {
        size_in_words_var++;
    }
    struct bitset * result = calloc(1, sizeof(struct bitset));
    result->bits = (uint64_t *)calloc(size_in_words_var, sizeof(uint64_t));
    result->universe_size = size;
    result->size_in_words = size_in_words_var;
    return result;
}


/*
// inserts an item into a uint64_t bitset
// this should be called by another method that pre-selects set and item correctly
uint64_t insert(uint64_t set, int item) {
    // return set with item added
    uint64_t mask = 1ULL << item;
    uint64_t result = set | mask;
    return result;
}
*/

/*
// removes an item from a uint64_t bitset
// this should be called by another method that pre-selects set and item correctly
uint64_t remove(uint64_t set, int item) {
    uint64_t mask = ~(1ULL << item);
    uint64_t result = set & mask;
    return result;
}
*/

/*
// checks if an item is a member of a uint64_t bitset
// this should be called by another method that pre-selects set and item correctly
int check_membership(uint64_t set, int item) {
    uint64_t mask = 1ULL << item;
    uint64_t result = set & mask;
    return result >> item;
}
*/

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this) {
    return this->universe_size;
}

// return the number of set bits in an array of uint64_t values
int bitset_cardinality(struct bitset * this){
    int count = 0;
    int num_elements= this->size_in_words;
    for (int i = 0; i < num_elements; i++) {
        uint64_t element = this->bits[i]; 
        uint64_t mask = 1ULL;
        for (int i = 0; i < 64; i++) {
            if (element & mask) {
                count++;
            }
            mask = mask << 1;
        }
    }
    return count;
}

/*
// get the number of items that are stored in the set
// this code is only for one 64-bit word, you need to iterate through all
    // of the words and sum the cardinality of each.
int cardinality(uint64_t set){
    uint64_t mask = 1ULL;
    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (set & mask) {
            count++;
        }
        mask = mask << 1;
    }
}
*/



// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item){
    int index = item / 64;
    int shift_amount = item - (index * 64);
    uint64_t mask = 1ULL << shift_amount;
    uint64_t result = this->bits[index] & mask;
    if (result > 0) {
        return 1;
    }
    return 0;
}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item) {
    int index = item / 64;
    int shift_amount = item - (index * 64);
    uint64_t mask = 1ULL << shift_amount;
    this->bits[index] = this->bits[index] | mask;
}

// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item) {
    int index = item / 64;
    int shift_amount = item - (index * 64);
    uint64_t mask = ~(1ULL << shift_amount);
    this->bits[index] = this->bits[index] & mask;
}

// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1, struct bitset * src2) {
    assert(src1 -> universe_size == src2 -> universe_size);
    
    // add something to check size of dest
    // or just dont??

    for (int i = 0; i < src1->size_in_words; i++) { // size_in_words as it contains the number of array elements
        dest->bits[i] = (src1->bits[i]) | (src2->bits[i]);
    }
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1, struct bitset * src2) { 
    assert(src1 -> universe_size == src2 -> universe_size);


    for (int i = 0; i < src1->size_in_words; i++) { // size_in_words as it contains the number of array elements
        dest->bits[i] = (src1->bits[i]) & (src2->bits[i]);
    }

}
