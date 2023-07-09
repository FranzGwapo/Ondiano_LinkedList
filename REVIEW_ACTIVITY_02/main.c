#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char *argv[]) {
	List head = newList();
	initList(&head);
	bool state;
	state = insertFront(&head, 5);
	state = insertFront(&head, 6);
	state = insertFront(&head, 7);
	state = insertFront(&head, 8);
	printf("Insert Front:\n");
	displayList(head);
	
	state = insertRear(&head, 9);
	state = insertRear(&head, 10);
	printf("Insert Rear:\n");
	displayList(head);
	
	state = insertAt(&head, 11, 3);
	state = insertAt(&head, 12, 5);
	printf("Insert At:\n");
	displayList(head);
	
	return 0;
}
