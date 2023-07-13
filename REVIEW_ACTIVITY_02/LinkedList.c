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

bool searchItem(List list, DATA key){
	while(list!=NULL){
		if(list->data==key){
			return true;
		}
		list = list->next;
	}
	return false;
}

int getItem(List list, DATA key){
	int num;
	while(list!=NULL){
		if(list->data==key){
			num = key;
			return num;
		}
		list = list->next;
	}
	return -1;
}

bool deleteFront(List *list){
	if(list!=NULL){
		*list = (*list)->next;
		return true;
	}
	return false;
	
}

bool deleteRear(List *list){
	NodePtr trav = *list;
	NodePtr temp;
	if(list!=NULL){
		while(trav->next!=NULL){
			temp = trav;
			trav = trav->next;
		}
		temp->next = NULL;
		return true;
	}
	return false;
	
	
}

int deleteAt(List *list, int loc){
	int i, num;
	bool state;
	NodePtr trav = *list;
	NodePtr prev;
	if(loc==0){
		num = trav->data;
		state = deleteFront(list);
		return num;
	}

	for(i=0;i!=loc;++i){
		prev = trav;
		trav = trav->next;
			
	}
	if(trav->next==NULL){
		num = trav->data;
		state = deleteRear(list);
		return num;
	}
	num = trav->data;
	prev->next = trav->next;
	return num;
	
}

bool deleteItem(List *list, DATA key){
	NodePtr trav = *list;
	NodePtr prev;
	int count;
	bool state;
	
	while(trav->data!=key && trav->next!=NULL){
		count++;
		prev = trav;
		trav = trav->next;
	}
	
	if(count==0){
		state = deleteFront(list);
		return state;	
	}
	else if(trav->next==NULL){
		state = deleteRear(list);
		return state;
	}
	else if(trav->data==key){
		prev->next = trav->next;
		return true;
	}
	return false;
	
	
}

int deleteAllItem(List *list, DATA key){
	int count = 0, num;
	bool state;
	NodePtr trav = *list;
	while(trav->next!=NULL){
		if(trav->data == key && count==0){
			state = deleteFront(list);
			count = 0;
		}
		else if (trav->data==key && count!=0){
			num = deleteAt(list, count);

			trav = trav->next;
		}
		else{
			count++;
			trav = trav->next;	
		}

	}
	
	if(trav->data == key && count==0){
			state = deleteFront(list);
			count = 0;
	}
	else if(trav->data==key){
		state = deleteRear(list);
	}
	return key;
}
