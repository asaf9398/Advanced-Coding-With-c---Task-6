#include "functions.h"

//The function returns the difference between two pointers to strings
int strCompare(void *a, void *b)
{
    char **str1;
    char **str2;
    int output;
    str1 = (char **)a;
    str2 = (char **)b;
    output = strcmp(*str1, *str2);
    return output;
}

//The following function returns the difference between two integers
int intCompare(void *a, void *b)
{
    int *num1;
    int *num2;
    num1 = (int *)a;
    num2 = (int *)b;
    return *num1 - *num2;
}

//The following function makes integers array and returns it
int *getIntArr(int *size)
{
    int *intArr;
    int i;
    scanf("%d", size); // intArr array size.
    intArr = (int *)malloc((*size)*(sizeof(int)));
    checkAlloc(intArr);
    for (i = 0; i < (*size); i++)
    {
        scanf("%d", &intArr[i]);
    }
    return intArr;
}

//The following function makes strings array and returns it
char **getStringArr(int *size)
{
    char **stringArr;
    char line[SIZE];
    int lineLen,i;
    scanf("%d", size); // stringArr array size.
    getchar();
    stringArr = (char **)malloc((*size)*(sizeof(char*)));
    checkAlloc(stringArr);
    for (i = 0; i < (*size); i++)
    {
        gets(line);
        lineLen = strlen(line);
        stringArr[i] = (char *)malloc((lineLen +1)*sizeof(char));//+1 for \0
        checkAlloc(stringArr[i]);
        strcpy(stringArr[i], line);
    }
    return stringArr;
}

//The following function free the integers array + strings array
void freeMemory(int *intArr, int intArrSize, char **stringArr, int stringArrSize)
{
    int i;
    for (i = 0; i < stringArrSize; i++)
    {
        free(stringArr[i]);
    }
    free(stringArr);
    free(intArr);
}

//The following function uses binSearch function for array of strings
int stringBinSearch(char **arr, int size, char *str)
{
    return binSearch(arr, size, sizeof(char *), &str,strCompare);
}

//The following function uses binSearch function for array of int
int intBinSearch(int *arr, int size, int num)
{
    return binSearch(arr, size, sizeof(int), &num,intCompare);
}

//The following function is generic binarySearch function
int binSearch(void *arr, int size, int elemSize, void * variable,int(*compare)(void *, void *))
{
    bool found=false;
    int left=0,right=size-1,i;
    while ((left <= right) && !found)
    {
        i = ((left + right) / 2);
        if (compare((BYTE *)arr + (i * elemSize), (BYTE*)variable) == 0)
        {
            found = true;
        }
        else if (compare((BYTE *)arr + (i * elemSize),(BYTE *)variable) < 0)
        {
            left = i + 1;
        }
        else
        {
            right = i - 1;
        }
    }
    return found;
}



//The following function checks memory allocation
void checkAlloc(void * ptr)
{
    if(ptr==NULL)
    {
        printf("Memory allocation failed!!Exiting");
        exit(1);
    }
}