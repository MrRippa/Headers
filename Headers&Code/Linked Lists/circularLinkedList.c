#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list *next;
} List;

List *head = NULL;

List *createNode(int value){
	List *node = malloc(sizeof(List));
	node->data = value;
	node->next = NULL;
	return node;
}

int isEmpty(void){
	return head == NULL;
}

void insertToFront(List *node){
	if (isEmpty()){
		head = node;
		head->next = head;
		return;
	}
	List *traverser = head;
	while (traverser->next != head){
		traverser = traverser->next;
	}
	node->next = head;
	traverser->next = node;
	head = node;
}

void insertToBack(List *node){
	if (isEmpty()){
		head = node;
		head->next = head;
		return;
	}
	List *traverser = head;
	while (traverser->next != head){
		traverser = traverser->next;
	}
	node->next = head;
	traverser->next = node;
}



int main(void){
	
	return 0;
}