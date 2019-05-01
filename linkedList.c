#include "linkedList.h"

MyList* createList(void) {
	MyList* list = (MyList*) malloc(sizeof(MyList));
	if (list == NULL) {
		printf("Probleme creating a linked list !\n");
		return NULL;
	}
	list->count = 0;
	list->head  = NULL;
	printf("The List Has Been Created !\n");
	return list;
}

ListElement* creatElement(void* data) {
	ListElement* element = (ListElement*) malloc(sizeof(ListElement));
	if (element == NULL)
	{
		printf("Error while adding element, couldn't allocate new element\n");
	}
	element->data = (void*) malloc(sizeof(void));
	element->data = data;
	element->next = NULL;
}

ListElement* getElement(int idx, MyList* list) {
	if(idx > list->count-1 || idx < 0) return NULL;	
	ListElement* p = list->head;
	while(idx--) {
		p = p->next;
	}
	return p;
}

ListElement* getTrail(MyList* list) {	
	return getElement(list->count-1, list);
}

bool insertElement(int idx, void* data, MyList* list) {
	if (idx == 0) {
		ListElement* element = creatElement(data);
		if (element == NULL) return false;
		element->next = list->head;
		list->head = element;
		list->count++;
		return true;
	}

	ListElement* previousElement = getElement(idx-1, list);
	ListElement* newElement      = creatElement(data);
	if(previousElement == NULL || newElement == NULL) return false;
	newElement->next = previousElement->next;
	previousElement->next = newElement;
	list->count++;
	return true;
}

void addElement(void* data, MyList* list) {
	insertElement(list->count, data, list);
}

void addIntElement(int data, MyList* list) {
	int* p = (int*) malloc(sizeof(int));
	*p = data;
	addElement((void*) p, list);
}

void addCharElement(char data, MyList* list) {
	char* p = (char*) malloc(sizeof(char));
	*p = data;
	addElement((void*) p, list);
}

bool deleteElement(int idx, MyList* list) {
	if (list->count <= 0 || idx > list->count-1 || idx < 0) return false;

	// element to be discarded is the head
	if(idx == 0) {
		ListElement* head = list->head;
		list->head = list->head->next;
		free(head->data);
		free(head);
		list->count--;		
		return true;		
	}

	// element to be discarded is the trail 
	if(list->count-1 == idx) {
		ListElement* elementPastTrail = getElement(list->count-2  , list);
		free(elementPastTrail->next->data);
		free(elementPastTrail->next);
		elementPastTrail->next = NULL;
		list->count--;		
		return true;
	}

	ListElement* previousElement  = getElement(idx-1, list);
	ListElement* currentElement   = getElement(idx  , list);

	previousElement->next = currentElement->next;
	free(currentElement->data);
	free(currentElement);
	list->count--;
	return true;
}

void deleteList(MyList* list) {
	for (int i = list->count-1; i >= 0; i--) {
		deleteElement(i, list);
	}
	free(list);
}
