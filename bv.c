#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bv.h"

struct bitvec {
    char* space;
    int maxsize;
};

BitVec* bv_construct(int maxsize)
{
    BitVec* bv = (BitVec*) calloc(1, sizeof(BitVec));
    int length = ceil(maxsize/8.0);
    bv->space = (char*) calloc(length, sizeof(char));
    bv->maxsize = maxsize;
    return bv;
}

BitVec* bv_construct_str(int maxsize, const char* bitstring)
{
    BitVec* bv = bv_construct(maxsize);
    if (strlen(bitstring) > maxsize) { return NULL; }
    for (int a = 0; a < strlen(bitstring); a++)
    {
        if (bitstring[a] == '1')
        {
            bv_set(bv, a);
        }
        else 
        {
            bv_reset(bv, a);
        }
    }
    return bv;
}

/* REQUIRED FUNCTION */
int bv_get(BitVec* bv, int pos)
{
    return (bv->space[pos/8] & (1 << (pos%8)));
}

void bv_set(BitVec* bv, int pos)
{
    bv->space[pos/8] = bv->space[pos/8] | (1 << (pos%8));
}

void bv_reset(BitVec* bv, int pos)
{
    bv->space[pos/8] = bv->space[pos/8] & ~(1 << (pos%8));
}

int bv_maxsize(BitVec* bv)
{
    return bv->maxsize;
}

int bv_count(BitVec* bv)
{
    int count = 0;
    for (int a = 0; a < bv->maxsize; a++)
    {
        if (bv_get(bv, a) != 0) { count++; }
    }
    return count;
}

int bv_test_any(BitVec* bv)
{
    for (int a = 0; a < bv->maxsize; a++)
    {
        if (bv_get(bv, a) != 0) { return 1; }
    }
    return 0;
}

int bv_test_none(BitVec* bv)
{
    for (int a = 0; a < bv->maxsize; a++)
    {
        if (bv_get(bv, a) != 0) { return 0; }
    }
    return 1;
}

int bv_test_all(BitVec* bv)
{
    for (int a = 0; a < bv->maxsize; a++)
    {
        if (bv_get(bv, a) != 0) { continue; }
        else { return 0; }
    }
    return 1;
}

void bv_flip(BitVec* bv, int pos)
{
    int value = bv_get(bv, pos);
    if (value != 0)
    {
        bv_reset(bv, pos);
    }
    else 
    {
        bv_set(bv, pos);
    }
}

char* bv_tostring(BitVec* bv, char* buf, int bufsize)
{
    if (bufsize < bv->maxsize) { return NULL; }
    int temp = 0;
    int a = 0;
    for (a = 0; a < bv->maxsize; a++)
    {
        temp = bv_get(bv, a);
        if (temp != 0)
        {
            buf[a] = '1';
        }
        else 
        {
            buf[a] = '0';
        }
    }
    buf[a] = '\0';
    return buf;
}

void bv_destruct(BitVec* bv)
{
    free(bv->space);
    free(bv);
}
