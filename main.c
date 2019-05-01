#include <string.h>

#include "linkedList.h"

#define COUNT printf("count : %d\n", list->count)

int main(int argc, char const *argv[])
{
	List* list = createList();

	appendIntList(5, list);
	appendIntList(7, list);
	appendIntList(9, list);
	appendIntList(10, list);

	deleteNode(2, list);

	for (int i = 0; i < list->count; ++i)
	{
		printf("%d ", getIntFromList(i, list));
	}
	printf("\n\n");

	deleteList(list);
	return 0;
}