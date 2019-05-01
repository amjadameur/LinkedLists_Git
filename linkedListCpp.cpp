#include "linkedListCpp.h"

Node::Node(void* data) {
	this->data = data;
}

void* Node::getData(void) {
	return data;
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

Node* List::getTrail(void) {
	return getNode(count-1);
}

void List::insertNode(int idx, void* data) {
	Node* newNode      = new Node(data);
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
