#include "linkedListCpp.h"

Node::Node(void* data) {
	this->data = data;
}

Node::~Node() {
	free(data);
}

List::List() {
	count = 0;
	head  = NULL;
	printf("The List Has Been Created !\n");
}

Node* List::getNode(int idx) {
	if(idx < 0 || idx > count-1) {
		printf("Index out of range\n");
		return NULL;	
	}
	Node* node = head;
	while(idx--) {
		node = node->next;
	}
	return node;
}

Node* List::getTrail() {
	return getNode(count-1);
}

void* List::getDataFromList(int idx) {
	return getNode(idx)->data;
}

void List::insertNode(int idx, void* data) {
	Node* newNode = new Node(data);
	if (idx == 0) {
		newNode->next = head;
		head = newNode;
		count++;
	} else {
		Node* previousNode = getNode(idx-1);
		newNode->next = previousNode->next;
		previousNode->next = newNode;
		count++;
	}
}

void List::appendNode(void* data) {
	insertNode(count, data);
}

void List::deleteNode(int idx) {
	if (count <= 0 || idx > count-1 || idx < 0) return;

	// element to be discarded is the head
	if(idx == 0) {
		Node* head = this->head;
		this->head = this->head->next;
		free(head->data);
		free(head);
		count--;		
		return;		
	}

	// element to be discarded is the trail 
	if(count-1 == idx) {
		Node* elementPastTrail = getNode(count-2);
		free(elementPastTrail->next->data);
		free(elementPastTrail->next);
		elementPastTrail->next = NULL;
		count--;		
		return;
	}

	Node* previousNode  = getNode(idx-1);
	Node* currentNode   = getNode(idx);

	previousNode->next = currentNode->next;
	free(currentNode->data);
	free(currentNode);
	count--;
}

List::~List() {
	for (int i = count-1; i >= 0; i--) {
		delete getNode(i);
	}
}


//////////////////////////////////////////////////////// Bonus methods
void List::appendIntList(int data) {
	int* p = (int*) malloc(sizeof(int));
	*p = data;
	appendNode((void*) p);
}

void List::appendCharList(char data) {
	char* p = (char*) malloc(sizeof(char));
	*p = data;
	appendNode((void*) p);
}

int List::getIntList(int idx) {
	return *((int*) getDataFromList(idx));
}

char List::getCharList(int idx) {
	return *((char*) getDataFromList(idx));
}


void List::setIntList(int idx, int data) {
	*((int*) getDataFromList(idx)) = data;
}

void List::setCharList(int idx, char data) {
	*((char*) getDataFromList(idx)) = data;
}
