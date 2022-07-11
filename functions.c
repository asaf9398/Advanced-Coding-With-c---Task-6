#include "functions.h"



//The following function returns new arr in order of indArr indexes
void *scramble(void *arr, int ElemSize, int n, int *indArr)
{
    int i;
    void * res = malloc(n*ElemSize);
    checkAlloc(res);
    for (i = 0; i < n; i++)
    {
        memcpy(((BYTE *)res + (i * ElemSize)), ((BYTE *)arr + (indArr[i] * ElemSize)), ElemSize);
    }
    return res;
}

//The following function scrambles array of integers
int *scrambleInt(int *intArr, int intSize, int *indArr)
{
    return (int *)scramble(intArr, sizeof(int), intSize, indArr);
}

//The following function scrambles array of strings
char **scrambleString(char **stringArr, int size, int * indArr)
{
    return (char **)scramble(stringArr, sizeof(char *),size, indArr);
}


//The following function prints array of strings
void printStringArr(char **scrambleStringArr, int stringSize)
{
    int i;
    for (i = 0; i < stringSize; i++)
    {
        printf("%s\n", scrambleStringArr[i]);
    }
}


//The following function prints array of int
void printIntArr(int * arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

//The following function returns array of integers + size
int *getIntArr(int *intSize)
{
    int *intArr;
    int i;
    scanf("%d", intSize);
    intArr = (int *)malloc((*intSize)*(sizeof(int)));
     checkAlloc(intArr);
    for (i = 0; i < (*intSize); i++)
    {
        scanf("%d", &intArr[i]);
    }
    return intArr;
}

//The following function returns array of strings + size
char ** getStringArr(int * size)
{
    char ** stringArr;
    char line[SIZE];
    int lineLength;
    int i;
    scanf("%d", size); // stringArr array size.
    getchar();
    stringArr = (char **)malloc((*size)*(sizeof(char*)));
    checkAlloc(stringArr);
    for (i = 0; i < (*size); i++)
    {
        gets(line);
        lineLength = strlen(line);
        stringArr[i] = (char *)malloc((lineLength +1)*sizeof(char));
        checkAlloc(stringArr[i]);
        strcpy(stringArr[i], line);
    }
    return stringArr;
}
void checkAlloc(void * ptr)
{
    if(ptr==NULL)
    {
        printf("Memroy allocation failed!!Exiting");
        exit(1);
    }
}

//The following function gets the integers array + strings array and frees them
void freeMemory(int *intArr, int *scrambleIntArr, int intArrSize,char **stringArr, char **scrambleStringArr, int stringArrSize)
{
    int i;
    free(intArr);
    free(scrambleIntArr);
    for (i = 0; i < stringArrSize; i++)
    {
        free(stringArr[i]);
    }
    free(stringArr);
    free(scrambleStringArr);
}