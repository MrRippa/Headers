/*
	Binary Search Tree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
} BST;

BST *root = NULL;

BST *createNode(int value){
	BST *newNode = (BST *)malloc(sizeof(BST));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int isEmpty(void){
	return root == NULL;
}

void printTree(BST *printNode){
	if (printNode == NULL){
		return;
	}
	printTree(printNode->left);
	printf("%d ", printNode->data);
	printTree(printNode->right);
}

void insert(BST *node){
	if (isEmpty()){
		root = node;
		return;
	}
	BST *traverser = root;
	while (traverser != NULL){
		if (node->data < traverser->data){
			if (traverser->left == NULL){
				traverser->left = node;
				return;
			}
			traverser = traverser->left;
		} else if (node->data > traverser->data){
			if (traverser->right == NULL){
				traverser->right = node;
				return;
			}
			traverser = traverser->right;
		}
	}
}

void deleteNode(int value){
	if (isEmpty()){
		return;
	} else if (root->data == value){
		
	}
	BST *traverser = root, *deleter = NULL;
	while (traverser != NULL){
		if (traverser->left->data == value){
			
	}
}

int main(void){
	int var = 0;
	while (var != -1){
		printf("Enter a number: ");
		scanf("%d", &var);
		insert(createNode(var));
	}
	printTree(root);
	return 0;
}