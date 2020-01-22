#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int data;
	struct queue *next;
} Queue;

Queue *front = NULL, *back = NULL;

Queue *createNode(int value){
	Queue *node = malloc(sizeof(Queue));
	node->data = value;
	node->next = NULL;
	return node;
}

int isEmpty(void){
	return back == NULL;
}

void push(Queue *node){
	if (isEmpty()){
		front = node;
		back = node;
	}
	back->next = node;
	back = back->next;
}

Queue *pop(void){
	if (isEmpty()){
		return NULL;
	}
	Queue *remover = front;
	front = front->next;
	return remover;
}

int main(void){
	
	return 0;
}