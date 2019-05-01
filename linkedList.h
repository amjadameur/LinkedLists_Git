#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct List_Element {
	void* data;
	struct List_Element* next;	
} ListElement;

typedef struct My_List {
	int count;
	ListElement* head;
} MyList;


MyList* startList(void);

ListElement* creatElement(void* data);

ListElement* findElement(int idx, MyList* list);

ListElement* findTrail(MyList* list);

bool addElementIdx(int idx, void* data, MyList* list);

void addElement(void* data, MyList* list);

bool deleteElement(int idx, MyList* list);

void deleteList(MyList* list);

#endif