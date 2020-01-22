#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct queue{
	int data;
} Queue;

Queue *queueArray[SIZE];
int front = 0, end = 0;

Queue *createNode(int value){
	Queue *node = malloc(sizeof(Queue));
	node->data = value;
	return node;
}

int isEmpty(void){
	return end == 0;
}

int isFull(void){
	return end == SIZE;
}

void push(Queue *node){
	if (isFull()){
		return;
	}
	queueArray[back] = node;
	back++;
}

Queue *pop(void){
	if (isEmpty()){
		return NULL;
	}
	Stack *remover = queueArray[front];
	for (int i = 0; i < back - 1; i++){
		queueArray[i] = queueArray[i] + 1;
	}
	back--;
	return remover;
}

int main(void){
	
	return 0;
}