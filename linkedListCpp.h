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

	void* getData(int idx);

	Node* getTrail(void);

	void insertNode(int idx, void* data);
	
	void appendNode(void* data);

	void deleteNode(int idx);

	// not necessary methods
	void appendInt(int data);

	void appendChar(char data);

	int  getInt(int idx);

	char getChar(int idx);

	void setInt(int idx, int data);

	void setChar(int idx, char data);
};

#endif