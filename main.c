#include <string.h>
#include <stdio.h>
#include <stdlib.h>


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

ListElement* findTrail(MyList* list) {	
	ListElement* p = list->head;
	while(p->next != NULL) {
		p = p->next;
	}
	return p;
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

void showList(MyList list) {
	ListElement* p = list.head;
	printf("\nElements of the list are : ");
	for (int i = 0; i < list.count; ++i) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n\n");
}

void debug(void) {	
	MyList list;
	startList(&list);

	addElement(7, &list);
	addElement(14, &list);
	addElement(15, &list);
	addElement(17, &list);

	showList(list);
}

int main(int argc, char const *argv[])
{
	MyList list;
	startList(&list);
	
	debug();
	return 0;
}