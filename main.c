#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"



int main(int argc, char const *argv[])
{
	MyList* list = createList();
	addIntElement('a', list);

	int v = *((char*) list->head->data);
	printf("%c\n", v);

	return 0;
}