
#ifndef ADVANCEDPROGRAMMINGC_TASK6_1_CLIENTS_H
#define ADVANCEDPROGRAMMINGC_TASK6_1_CLIENTS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct _client
{
	char id[9];     // “12345678”
	char phone[12]; // “054-1234567”
} Client;

typedef struct _short_client
{
	unsigned char short_id[4];
	unsigned char short_phone[5];
} Short_client;


Client* makeArr(int n);
void getClient(Client* cli);
Short_client* compressArr(Client** arr, int size);
Short_client compressClient(Client client);
void checkAlloc(void* p);
Short_client* createShortClientArr(int size);
char* searchClientByID(Short_client* arr, int size, char * id);
bool isInsideArr(Short_client* arr,unsigned char** phoneNumber, char * id,int size);
bool sameIdNumber(unsigned char * short_id, char * id);
void getPhoneNumber(unsigned char* short_phone,unsigned char* phoneNumber);



#endif //ADVANCEDPROGRAMMINGC_TASK6_1_CLIENTS_H
