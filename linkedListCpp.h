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
	~Node();

};



class List {
	public :
	int count;
	Node* head;

	List();
	~List();

	Node* getNode(int idx);

	void* getDataFromList(int idx);

	Node* getTrail(void);

	void insertNode(int idx, void* data);
	
	void appendNode(void* data);

	void deleteNode(int idx);

	void deleteList(void);


	// not necessary methods
	void appendIntList(int data);

	void appendCharList(char data);

	int  getIntList(int idx);

	char getCharList(int idx);

	void setIntList(int idx, int data);

	void setCharList(int idx, char data);
};

#endif