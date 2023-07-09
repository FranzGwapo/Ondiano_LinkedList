#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list){
	list = NULL;
}
List newList(){
	List list = NULL;
	return list;
}

NodeType createNode(DATA data){
	NodePtr newNode = malloc(sizeof(NodeType));
	newNode->data = data;
	newNode->next = NULL;
}

void displayList(List list){
	printf("DISPLAY LIST: \n { ");
	while(list!=NULL){
		printf("%d ", list->data);
		list = list->next;
	}
	printf("}\n\n");
	
}

bool insertFront(List *list, DATA item){
	NodePtr newPtr = malloc(sizeof(NodeType));
	
	newPtr->data = item;
	newPtr->next = *list;
	*list = newPtr;
	return true;
	
}

bool insertRear(List *list, DATA item){
	NodePtr end;
	NodePtr newPtr1 = malloc(sizeof(NodeType));
	newPtr1->data = item;
	newPtr1->next = NULL;
	
	end = *list;
	
	while(end->next!=NULL){
		end = end->next;
	}
	end->next = newPtr1;
	
	return true;
}

bool insertAt(List *list, DATA item, int loc){
	NodePtr newPtr = malloc(sizeof(NodeType));
	newPtr->data = item;
	newPtr->next = NULL;
	int i;
	
	NodePtr temp = *list;
	
	for(i=0;i<loc-1;++i){
		temp = temp->next;
	}
	newPtr->next = temp->next;
	temp->next = newPtr;
//	while(temp->next!=loc){
//		temp = temp->next;
//	}
	
}

bool insertSorted(List *list, DATA data){
	NodePtr trav, newPtr;
	newPtr = malloc(sizeof(NodeType));
	newPtr->data = data;
	newPtr->next = NULL;
	
	trav = *list;
	int count = 0;
	while(trav->data< data){
		trav = trav->next;
	}
	
	if(trav->data > data && count==0){
		insertFront(list, data);
	}
	else{
		newPtr->next = trav->next;
		trav->next = newPtr;
	}

	
}

bool searchItem(List list, DATA key);

int getItem(List list, DATA key);

bool deleteFront(List *list);

bool deleteRear(List *list);

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
