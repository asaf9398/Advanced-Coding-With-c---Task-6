#include "NumbersArrFunctions.h"


//The following function gets 2 arrays of BYTEs and returns the new filtered integers array that created from XOR pred1&pred2 using "filter" function
int* xorFilter(int* Numbers, int size, unsigned char* pred1, unsigned char* pred2, int* new_size)
{
    BYTE mask = 0x80;
    int i;
    BYTE* newPred = (BYTE*)calloc((size / 8), sizeof(BYTE));
    checkAlloc(newPred);
    for (i = 0; i < size/8; i++)
    {
        newPred[i] = pred1[i] ^ pred2[i];
    }
    int* newNumbers = filter(Numbers, size, newPred, new_size);
    free(newPred);
    return newNumbers;
}

//The function turning bit i on
void turnBitOn(BYTE* byte, int i)
{
    BYTE mask = 0x80;
    mask = mask >> i;
    *byte = (*byte) | mask;
}


//The function gets an array of integers + array of BYTEs and returns an updated array of the integers that include only the bits that were on in "pred"
int* filter(int* Numbers, int size, unsigned char* pred, int* new_size)
{
    int phySize = 1, logSize = 0, i = 0;
    int* tmpArr = (int*)malloc(sizeof(int) * phySize);
    checkAlloc(tmpArr);
    while (i < size)
    {
        if (phySize == logSize)
        {
            phySize *= 2;
            tmpArr = (int*)realloc(tmpArr, sizeof(int) * phySize);
            checkAlloc(tmpArr);
        }
        if (isBitISet(pred[i / 8], (i % 8)))
        {
            tmpArr[logSize] = Numbers[i];
            logSize++;
        }
        i++;
    }


    phySize = logSize;
    tmpArr = (int*)realloc(tmpArr, sizeof(int) * phySize);
    checkAlloc(tmpArr);
    *new_size = phySize;
    return tmpArr;

}


//Checking if bit i in the specific byte is set
bool isBitISet(BYTE ch, int i)
{
    BYTE mask = 1 << i;
    return mask & ch;
}

//Memory allocation check
void checkAlloc(void* ptr)
{
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed!! Exiting");
        exit(1);
    }
}
