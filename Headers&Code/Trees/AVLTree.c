/*
	AVL TREE
		Balanced BST
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	int height;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
} AVL;

AVL *root = NULL;

AVL *createNode(int value){
	AVL *newNode = (AVL *)malloc(sizeof(AVL));
	newNode->data = value;
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int isEmpty(void){
	return root == NULL;
}

int getBalanceFactor(AVL *node){
	if (node == NULL){
		return 0;
	}
	int numLeft = 0, numRight = 0;
	if (node->left != NULL){
		numLeft = node->left->height + 1;
	}
	if (node->right != NULL){
		numRight = node->right->height + 1;
	}
	return numLeft - numRight;
}

int getHeight(AVL *node){
	if (node == NULL){
		return 0;
	}
	int numLeft = 0, numRight = 0;
	if (node->left != NULL){
		numLeft = node->left->height + 1;
	}
	if (node->right != NULL){
		numRight = node->right->height + 1;
		if (numRight > numLeft){
			return numRight;
		}
	}
	return numLeft;
}

void rightRotation(AVL *node){
	AVL *rotator = node->left;
	node->left = rotator->right;
	rotator->right = node;
	node->height = getHeight(node);
	rotator->height = getHeight(rotator);
}

void leftRotation(AVL *node){
	AVL *rotator = node->right;
	node->right = rotator->left;
	rotator->left = node;
	node->height = getHeight(node);
	rotator->height = getHeight(rotator);
}

void rotateNodes(AVL *node, int mode){
	switch (mode){
		case 1:
			leftRotation(node);
			break;
		case 2:
			rightRotation(node);
			break;
		case 3:
			rightRotation(node);
			leftRotation(node);
			break;
		case 4:
			leftRotation(node);
			rightRotation(node);
	}
}

void insert(AVL *traverseNode, AVL *insertNode){
	if (isEmpty()){
		root = insertNode;
	}
	if (traverseNode == NULL){
		traverseNode = insertNode;
		return;
	}
	if (insertNode->data < traverseNode->data){
		printf("WHAT\n");
		insert(traverseNode->left, insertNode);
		if (getBalanceFactor(traverseNode) == 2){
			if (insertNode->data < traverseNode->left->data){
				printf("Case 2\n");
				rotateNodes()
			} else {
				printf("Case 4\n");
			}
		}
	} else if (insertNode->data > traverseNode->data){
		printf("YEET");
		insert(traverseNode->right, insertNode);
		if (getBalanceFactor(traverseNode) == -2){
			if (insertNode->data > traverseNode->right->data){
				printf("Case 1\n");
			} else {
				printf("Case 3\n");
			}
		}
	}
	traverseNode->height = getHeight(traverseNode);
}



int main(void){
	int num = 0;
	while (num != -1){
		printf("Enter a number: ");
		scanf("%d", &num);
		insert(root, createNode(num));
	}
	return 0;
}