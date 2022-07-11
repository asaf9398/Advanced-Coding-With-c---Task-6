#ifndef ADVANCEDCODINGC_TASK6_2_NUMBERSARRFUNCTIONS_H
#define ADVANCEDCODINGC_TASK6_2_NUMBERSARRFUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef unsigned char BYTE;
int* filter(int* Numbers, int size, unsigned char* pred,int* new_size);
bool isBitISet(BYTE ch, int i);
void checkAlloc(void * ptr);
int* xorFilter(int* Numbers, int size, unsigned char* pred1,unsigned char* pred2, int* new_size);
void turnBitOn(BYTE * byte,int i);


#endif //ADVANCEDCODINGC_TASK6_2_NUMBERSARRFUNCTIONS_H
