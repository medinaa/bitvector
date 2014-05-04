#ifndef _BV_H_
#define _BV_H_

typedef struct bitvec BitVec;

// Construct and return a BitVec that can hold maxsize bits.
BitVec* bv_construct(int maxsize);

// Construct and return a BitVec that can hold maxsize bits and initialized
// with the bitstring.
BitVec* bv_construct_str(int maxsize, const char* bitstring);

// Return the maximum size of the BitVec.
int bv_maxsize(BitVec* bv);

// Count the number of bits that are set to 1.
int bv_count(BitVec* bv);

// Returns 1 (true) if any bits are set to 1.
int bv_test_any(BitVec* bv);

// Returns 1 (true) if none of the bits are set to 1.
int bv_test_none(BitVec* bv);

// Returns 1 (true) if all bits are set to 1.
int bv_test_all(BitVec* bv);

// Return the bit value at position pos, either 0 or 1.
int bv_get(BitVec* bv, int pos);

// Set value at position pos to 1.
void bv_set(BitVec* bv, int pos);

// Set value at position pos to 0.
void bv_reset(BitVec* bv, int pos);

// Flip value at position pos to opposite. If it was 0 make it 1 and vice versa.
void bv_flip(BitVec* bv, int pos);

// Make a string from the BitVec bits (e.g. "10110000") then return buf.
// If bufsize is to small to hold bit string then return NULL
char* bv_tostring(BitVec* bv, char* buf, int bufsize);

// Destruct (free) the BitVec.
void bv_destruct(BitVec* bv);

#endif
