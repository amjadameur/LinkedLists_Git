#ifndef LINKEDLISTCPP_H
#define LINKEDLISTCPP_H

#include "stdlib.h"
#include "assert.h"
#include <iostream>
#include <fstream>
#include <string>

class Node {
	public :
	void* data;
	Node* next;

	Node(void) {}
	Node(void* data);

	void* getData(void);
};



class List {
	public :
	int count;
	Node* head;

	List();

	Node* getNode(int idx);

	//void* getDataFromList(int idx);

	Node* getTrail(void);

	void insertNode(int idx, void* data);

};

/*
////////////////////////////////////////// Fondamental functions :

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
*/
#endif