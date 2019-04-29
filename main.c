#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct List_Element {
	int data;
	struct List_Element* next;	
} ListElement;

typedef struct My_List {
	int count;
	ListElement* head;
} MyList;



void startList(MyList* list) {
	list->count = 0;
	list->head  = NULL;
	printf("The List Has Been Created !\n");
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

void addElement(int data, MyList* list) {
	ListElement* element = creatElement(data);

	if(list->head == NULL) {
		list->head = element;
		list->count++;		
		return;
	}

	ListElement* trail = findTrail(list);
	trail->next = element;
	list->count++;
}

bool addElementIdx(int idx, int data, MyList* list) {
	if (idx > list->count-1) {
		addElement(data, list); 
		return true;
	}
	if (idx <= 0) {
		ListElement* element = (ListElement*) malloc(sizeof(ListElement));
		if (element == NULL) return false;
		element->data = data;
		element->next = list->head;
		list->head = element;
		return true;
	}


}


void showList(MyList list) {
	ListElement* p = list.head;
	printf("\nElements of the list are : ");
	for (int i = 0; i < list.count; ++i) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
}

//////Debug & Main////////////////////////////////////////////////////////////////////////////
void debug(void) {	
	MyList list;
	ListElement element;
	startList(&list);

	addElement(7, &list);
	addElement(14, &list);
	addElement(15, &list);
	addElement(17, &list);

	addElementIdx(0, 5, &list);
	showList(list);

	element = *findElement(3, &list);
	printf("found : %d\n", element.data);
}

int main(int argc, char const *argv[])
{
	MyList list;
	startList(&list);
	
	debug();
	return 0;
}