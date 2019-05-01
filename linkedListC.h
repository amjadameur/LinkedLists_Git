#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct ListNode {
	void* data;
	struct ListNode* next;	
} Node;

typedef struct LinkedList {
	int count;
	Node* head;
} List;


////////////////////////////////////////// Fondamental functions :
List* createList(void);

Node* createNode(void* data);

Node* getNode(int idx, List* list);

void* getDataFromList(int idx, List* list);

Node* getTrail(List* list);

bool insertNode(int idx, void* data, List* list);

void appendNode(void* data, List* list);

bool deleteNode(int idx, List* list);

void deleteList(List* list);


//////////////////////////////////////////// Bonus functions :
void appendIntList(int data, List* list);

void appendCharList(char data, List* list);

int  getIntList(int idx, List* list);

char getCharList(int idx, List* list);

void setIntList(int idx, int data, List* list);

void setCharList(int idx, char data, List* list);

#endif