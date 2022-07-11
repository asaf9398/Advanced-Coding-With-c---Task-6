#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
typedef unsigned char BYTE;

void* scramble(void* arr, int ElemSize, int n, int* indArr);
int * getIntArr(int * size);
int * scrambleInt(int * arr, int size,int *indArr);
void printIntArr(int * arr,int size);
char ** getStringArr(int * size);
char **scrambleString(char **stringArr, int size, int * indArr);
void checkAlloc(void * ptr);
void freeMemory(int *intArr, int *scrambleIntArr, int intArrSize,char **stringArr, char **scrambleStringArr, int stringArrSize);
void printStringArr(char **scrambleStringArr, int stringSize);

#endif
