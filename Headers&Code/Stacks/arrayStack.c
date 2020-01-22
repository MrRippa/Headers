#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct stack{
	int data;
} Stack;

Stack *stackArray[SIZE];
int top = 0, bottom = 0;

Stack *createNode(int value){
	Stack *node = malloc(sizeof(Stack));
	node->data = value;
	return node;
}

int isEmpty(void){
	return top == 0;
}

int isFull(void){
	return top == SIZE;
}

void push(Stack *node){
	if (isFull()){
		return;
	}
	stackArray[top] = node;
	top++;
}

Stack *pop(void){
	if (isEmpty()){
		return NULL;
	}
	Stack *remover = stackArray[top];
	stackArray[top] = NULL;
	top--;
	return remover;
}

int main(void){
	
	return 0;
}