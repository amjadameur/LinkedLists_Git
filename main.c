#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"


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





