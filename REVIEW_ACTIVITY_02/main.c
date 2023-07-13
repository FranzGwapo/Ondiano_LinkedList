#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char *argv[]) {
	List head = newList();
	initList(&head);
	bool state;
	int num;
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
	
	state = insertAt(&head, 9, 3);
	state = insertAt(&head, 12, 5);
	printf("Insert At:\n");
	displayList(head);
	
	printf("Search Item (6):\n");
	state = searchItem(head, 6);
	(state) ? printf("Number 6 is there.\n\n") : printf("Number 6 is not there.\n\n");
	displayList(head);
	
	
	printf("Get Item (6):\n");
	num = getItem(head, 6);
	printf("Number got: %d\n\n", num);
	
	printf("Delete Front: \n");
	deleteFront(&head);
	displayList(head);
	
	printf("Delete Rear: \n");
	deleteRear(&head);
	displayList(head);
	
	printf("Delete At (Index 3): \n");
	num = deleteAt(&head, 3);
	printf("Number deleted: %d\n", num);
	displayList(head);
	
	printf("Delete Item (6): \n");
	state = deleteItem(&head, 6);
	displayList(head);
	
	printf("Delete All Item (5): \n");
	state = deleteAllItem(&head, 9);
	displayList(head);
	return 0;
}
