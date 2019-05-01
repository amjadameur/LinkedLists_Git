#include "linkedList.h"


bool deleteNode(int idx, List* list) {
	if (list->count <= 0 || idx > list->count-1 || idx < 0) return false;

	// element to be discarded is the head
	if(idx == 0) {
		Node* head = list->head;
		list->head = list->head->next;
		free(head->data);
		free(head);
		list->count--;		
		return true;		
	}

	// element to be discarded is the trail 
	if(list->count-1 == idx) {
		Node* elementPastTrail = getNode(list->count-2  , list);
		free(elementPastTrail->next->data);
		free(elementPastTrail->next);
		elementPastTrail->next = NULL;
		list->count--;		
		return true;
	}

	Node* previousNode  = getNode(idx-1, list);
	Node* currentNode   = getNode(idx  , list);

	previousNode->next = currentNode->next;
	free(currentNode->data);
	free(currentNode);
	list->count--;
	return true;
}

void deleteList(List* list) {
	for (int i = list->count-1; i >= 0; i--) {
		deleteNode(i, list);
	}
	free(list);
}


//////// Bonus functions :
void appendIntList(int data, List* list) {
	int* p = (int*) malloc(sizeof(int));
	*p = data;
	appendNode((void*) p, list);
}

void appendCharList(char data, List* list) {
	char* p = (char*) malloc(sizeof(char));
	*p = data;
	appendNode((void*) p, list);
}


int getIntList(int idx, List* list) {
	return *((int*) getDataFromList(idx, list));
}

char getCharList(int idx, List* list) {
	return *((char*) getDataFromList(idx, list));
}


void setIntList(int idx, int data, List* list) {
	*((int*) getDataFromList(idx, list)) = data;
}

void setCharList(int idx, char data, List* list) {
	*((char*) getDataFromList(idx, list)) = data;
}
