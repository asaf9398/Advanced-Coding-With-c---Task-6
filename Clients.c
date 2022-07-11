#include "Clients.h"

//The following function gets arr of short_clients + size + id and returns its phone number(as string)
char* searchClientByID(Short_client* arr, int size, char * id)
{
    unsigned char* phoneNumber = (char*)malloc(sizeof(char) * 12);
    if (!isInsideArr(arr,&phoneNumber,id,size))
    {
        free(phoneNumber);
        return NULL;
    }
    else
    {
        return phoneNumber;
    }
}
//The following function gets short_id and id and returns if they are even
bool sameIdNumber(unsigned char * short_id, char * id)
{
    int i;
    char* tmpId = (char*)malloc(sizeof(char) * 9);
    tmpId[8] = '\0';
    bool leftHalfOfByte = true;
    for (i = 0; i < 8; i++)
    {
        if (leftHalfOfByte)
        {
            tmpId[i] = (short_id[i / 2]) >> 4;
            tmpId[i]+='0';
            leftHalfOfByte = !leftHalfOfByte;
        }
        else
        {
            tmpId[i] = (short_id[i / 2]) << 4;
            tmpId[i]=tmpId[i]>>4;
            tmpId[i]+='0';
            leftHalfOfByte = !leftHalfOfByte;
        }
    }
    bool isEqual=false;
    if (strcmp(id, tmpId) == 0)
    {
        isEqual = true;
    }
    free(tmpId);
    return isEqual;
}

//The following function updates phone number to be the phone number inside short_phone
void getPhoneNumber(unsigned char * short_phone,unsigned char * phoneNumber)
{
    int i=0,indexInShortPhone=0;
    bool isLeftByte = true;
    phoneNumber[11] = '\0';
    while (i < 11)
    {
        if (i == 3)
        {
            phoneNumber[i] = '-';
        }
        else
        {
            if (isLeftByte)
            {
                phoneNumber[i]=0;
                phoneNumber[i]=(short_phone[indexInShortPhone])>>4;
                phoneNumber[i]+='0';
                isLeftByte=!isLeftByte;
            }
            else
            {
                phoneNumber[i]=0;
                phoneNumber[i] = (short_phone[indexInShortPhone]) << 4;
                phoneNumber[i] =phoneNumber[i] >>4;
                phoneNumber[i]+='0';
                isLeftByte=!isLeftByte;
                indexInShortPhone++;
            }
        }
        i++;
    }
}

//The following functino gets short_clients arr + adress of string(represents phone number)
//The function will update phone number if id is inside and returns true/false if id is in
bool isInsideArr(Short_client* arr,unsigned char** phoneNumber,char * id,int size)
{
    bool found = false;
    int i = 0;
    while (!found&&i<size)
    {
        if (sameIdNumber(arr[i].short_id,id))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (!found)
    {
        return false;
    }
    else
    {
        getPhoneNumber(arr[i].short_phone,*phoneNumber);
        return true;
    }
}

//The following function creates array of Short_client with "size" cells and returns its adress
Short_client* createShortClientArr(int size)
{
    Client* clientsArr = makeArr(size);
    char ch=getchar();//getting rid of last \n
    return compressArr(&clientsArr, size);
}

//The following function checks allocation
void checkAlloc(void* p)
{
    if (p == NULL)
    {
        printf("Memory allocation failed!Exiting");
        exit(1);
    }
}


//The following function makes arr of clients
Client* makeArr(int n)
{
    Client* arr = (Client*)malloc(n*sizeof(Client));
    int i;
    for  (i = 0; i < n; i++)
    {
        getClient(&arr[i]);
    }

    return arr;
}

//The following function gets a client from the user
void getClient(Client * cli)
{
    static bool firstClient=true;
    int i;
    printf("Please enter ID ");
    fflush(stdout);
    scanf("%s", cli->id);
    printf("Please enter phone number ");
    fflush(stdout);
    scanf("%s", cli->phone);
}

//The following function gets array of clients + size and returns array of short clients
//The function also frees the original array
Short_client* compressArr(Client** arr, int size)
{
    Short_client* compressedArr;
    Client* clientsArr = *arr;
    compressedArr = (Short_client*)calloc(size, sizeof(Short_client));
    int i;
    for (i = 0; i < size; i++)
    {
        compressedArr[i] = compressClient(clientsArr[i]);
    }
    // printf("test");
    // fflush(stdout);
    free(clientsArr);
    return compressedArr;
}

//The following function gets a client and compress it to be short client
Short_client compressClient(Client client)
{
    Short_client compressedClient;
    int i;
    for (i = 0; i < 8; i+=2)
    {
        compressedClient.short_id[i/2] = ((client.id[i] - '0') << 4) | (client.id[i + 1] - '0');
    }

    int numOfByte = 0;
    bool firstBits = true;
    for (i = 0; i < 11; i++)
    {
        if (i != 3)
        {
            if (firstBits)
            {
                compressedClient.short_phone[numOfByte] = (client.phone[i] - '0') << 4;
                firstBits = false;
            }
            else
            {
                compressedClient.short_phone[numOfByte] = (compressedClient.short_phone[numOfByte]) | (client.phone[i] - '0');
                numOfByte++;
                firstBits = true;
            }
        }
    }

    return compressedClient;
}
