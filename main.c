#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

#define COUNT printf("count : %d\n", list->count)

int main(int argc, char const *argv[])
{
	List* list = createList();

	
/*
	int* a1 = (int*) malloc(sizeof(int));
	int* a2 = (int*) malloc(sizeof(int));

	int* p = (int*) malloc(sizeof(int));
	
	*a1 = 5;
	*a2 = 10;

	appendList((void*) a1, list);
	p = (int*) list->head->data;
	printf("val1 : %d\n", *p);
	p = NULL;
	COUNT;

	appendList((void*) a2, list); 
	p = (int*) list->head->next->data;
	
	if(p == NULL) printf("BAD\n");
	printf("size : %zu\n", sizeof(*p));

	printf("val2 : %d\n", *p);
	p = NULL;

	COUNT;
*/
	deleteList(list);
	return 0;
}