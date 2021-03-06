#include "linkedList.h"

List* createList(void) {
	List* list = (List*) malloc(sizeof(List));
	if (list == NULL) {
		printf("Probleme creating a linked list !\n");
		return NULL;
	}
	list->count = 0;
	list->head  = NULL;
	printf("The List Has Been Created !\n");
	return list;
}

Node* createNode(void* data) {
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL)
	{
		printf("Error while adding element, couldn't allocate new element\n");
	}
	node->data = (void*) malloc(sizeof(void));
	node->data = data;
	node->next = NULL;
}

Node* getNode(int idx, List* list) {
	if(idx > list->count-1 || idx < 0) {
		printf("Index out of range\n");
		return NULL;	
	}
	Node* node = list->head;
	while(idx--) {
		node = node->next;
	}
	return node;
}

Node* getTrailNode(List* list) {	
	return getNode(list->count-1, list);
}

void* getDataFromList(int idx, List* list) {
	return getNode(idx, list)->data;
}

bool insertNode(int idx, void* data, List* list) {
	if (idx == 0) {
		Node* node = createNode(data);
		if (node == NULL) return false;
		node->next = list->head;
		list->head = node;
		list->count++;
		return true;
	}

	Node* previousNode = getNode(idx-1, list);
	Node* newNode      = createNode(data);
	if(previousNode == NULL || newNode == NULL) return false;
	newNode->next = previousNode->next;
	previousNode->next = newNode;
	list->count++;
	return true;
}

void appendNode(void* data, List* list) {
	insertNode(list->count, data, list);
}

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
