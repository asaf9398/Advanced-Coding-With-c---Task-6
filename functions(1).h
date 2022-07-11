#ifndef TASK6_4_FUNCTIONS_H
#define TASK6_4_FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

typedef unsigned char BYTE;

int strCompare(void *a, void *b);
int intCompare(void *a, void *b);
int *getIntArr(int *size);
char **getStringArr(int * size);
void freeMemory(int *intArr, int intArrSize, char **stringArr, int stringArrSize);
int stringBinSearch(char ** arr, int size, char *str);
int intBinSearch(int * arr, int size, int num);
int binSearch(void *arr, int size, int elemSize, void * variable,int(*compare)(void *, void *));
void checkAlloc(void * ptr);

#endif //TASK6_4_FUNCTIONS_H
