#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Hi myproject
// Hi tmp
typedef enum {false, true} bool;

typedef struct List_Element {
	int data;
	struct List_Element* next;	
} ListElement;

typedef struct My_List {
	int count;
	ListElement* head;
} MyList;



MyList* startList(void) {
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

ListElement* creatElement(int data) {
	ListElement* element = (ListElement*) malloc(sizeof(ListElement));
	if (element == NULL)
	{
		printf("Error while adding element, couldn't allocate new element\n");
	}
	element->data = data;
	element->next = NULL;
}

ListElement* findElement(int idx, MyList* list) {
	if(idx > list->count-1 || idx < 0) return NULL;	
	ListElement* p = list->head;
	while(idx--) {
		p = p->next;
	}
	return p;
}

ListElement* findTrail(MyList* list) {	
	return findElement(list->count-1, list);
}

bool addElementIdx(int idx, int data, MyList* list) {
	if (idx == 0) {
		ListElement* element = creatElement(data);
		if (element == NULL) return false;
		element->next = list->head;
		list->head = element;
		list->count++;
		return true;
	}

	ListElement* previousElement = findElement(idx-1, list);
	ListElement* newElement      = creatElement(data);
	if(previousElement == NULL || newElement == NULL) return false;
	newElement->next = previousElement->next;
	previousElement->next = newElement;
	list->count++;
	return true;
}

void addElement(int data, MyList* list) {
	addElementIdx(list->count, data, list);
}

bool addElements(int n, int* idx, int* data, MyList* list) {
	for (int i = 0; i < n; ++i)	{
		addElementIdx(idx[i], data[i], list);
	}
}

bool deleteElement(int idx, MyList* list) {
	if (list->count <= 0 || idx > list->count-1 || idx < 0) return false;

	// element to be discarded is the head
	if(idx == 0) {
		ListElement* head = list->head;
		list->head = list->head->next;
		free(head);
		list->count--;		
		return true;		
	}

	// element to be discarded is the trail 
	if(list->count-1 == idx) {
		ListElement* elementPastTrail = findElement(list->count-2  , list);
		free(elementPastTrail->next);
		elementPastTrail->next = NULL;
     	list->count--;		
		return true;
	}

	ListElement* previousElement  = findElement(idx-1, list);
	ListElement* currentElement   = findElement(idx  , list);

	previousElement->next = currentElement->next;
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

void showList(MyList list) {
	ListElement* p = list.head;
	printf("\nElements of the list are : ");
	for (int i = 0; i < list.count; ++i) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\nCount is : %d\n", list.count);
}

//////Debug & Main////////////////////////////////////////////////////////////////////////////
void debug(void);
void test(void);

int main(int argc, char const *argv[])
{
	MyList* list = startList();	
	debug();

	test();

	deleteList(list);
	return 0;
}

void debug(void) {	
	MyList* list = startList();

	addElement(7,  list);
	addElement(14, list);
	addElement(15, list);
	addElement(17, list);

	showList(*list);

	deleteList(list);
}

void test(void) {
	void* p;// = (void*) malloc(sizeof(void));
	int* a = (int*) malloc(sizeof(int));
	*a = 2;
	p = a;
	printf("a : %d\n", *a);
	//*((int*) p) = 5;
	//printf("a : %d\n", *a);

}



