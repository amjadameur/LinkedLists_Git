#include <string.h>
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

bool addElementIdx(int idx, void* data, MyList* list) {
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

void addElement(void* data, MyList* list) {
	addElementIdx(list->count, data, list);
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
		ListElement* elementPastTrail = findElement(list->count-2  , list);
		free(elementPastTrail->next->data);
		free(elementPastTrail->next);
		elementPastTrail->next = NULL;
		list->count--;		
		return true;
	}

	ListElement* previousElement  = findElement(idx-1, list);
	ListElement* currentElement   = findElement(idx  , list);

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

void* int_to_void(int val) {
	int* p = (int*) malloc(sizeof(int));
	*p = val;
	return (void*) p;
}


void* char_to_void(char val) {
	char* p = (char*) malloc(sizeof(char));
	*p = val;
	return (void*) p;
}


void showList_int(MyList list) {
	ListElement* p = list.head;
	void* data = (void*) malloc(sizeof(void));
	int val;

	printf("\nCount is : %d\n", list.count);
	printf("Elements of the list are : ");
	for (int i = 0; i < list.count; ++i) {
		data = p->data;
		val  = *((int*) data); 
		printf("%d ", val);
		p = p->next;
		data = NULL;
	}
	printf("\n\n");

	free(data);
}

void showList_char(MyList list) {
	ListElement* p = list.head;
	void* data = (void*) malloc(sizeof(void));
	char val;

	printf("\nCount is : %d\n", list.count);
	printf("Elements of the list are : ");
	for (int i = 0; i < list.count; ++i) {
		data = p->data;
		val  = *((char*) data); 
		printf("%c ", val);
		p = p->next;
		data = NULL;
	}
	printf("\n\n");

	free(data);
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
	int* a = (int*) malloc(sizeof(int));
	*a = 5;
	addElement(char_to_void('a'), list);
	addElement(char_to_void('b'), list);
	addElement(char_to_void('c'), list);
	addElement(char_to_void('d'), list);

	showList_char(*list);

	deleteList(list);
}

void test(void) {

}



