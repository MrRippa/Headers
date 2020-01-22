#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int data;
	struct stack *up;
	struct stack *down;
} Stack;

Stack *top = NULL, *bottom = NULL;

Stack *createNode(int value){
	Stack *node = malloc(sizeof(Stack));
	node->data = value;
	node->next = NULL;
	return node;
}

int isEmpty(void){
	return top == NULL;
}

void push(Stack *node){
	if (isEmpty()){
		top = node;
		bottom = node;
	}
	node->down = top;
	top->up = node;
	top = top->up;
}

Stack *pop(void){
	if (isEmpty()){
		return NULL;
	}
	Stack *remover = top;
	top = top->down;
	top->up = NULL;
	return remover;
}

int main(void){
	
	return 0;
}