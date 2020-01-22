/*
	Linked Lists
*/

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

void isEmpty(void){
	return head == NULL;
}

/* Insert Functions */

void insertToFront(List *node){
	if (isEmpty()){
		head = node;
		return;
	}
	node->next = head;
	head = node;
}

void insertToBack(List *node){
	if (isEmpty()){
		head = node;
		return;
	}
	List *traverser = head;
	while (traverser->next != NULL){
		traverser = traverser->next;
	}
	traverser->next = node;
}

void insertAscendingOrder(List *node){
	if (isEmpty()){
		head = node;
		return;
	} else if (head->data > node->data){
		node->next = head;
		head = node;
		return;
	}
	List *traverser = head;
	while (traverser->next != NULL && traverser->next->data < node->data){
		traverser = traverser->next;
	}
	node->next = traverser->next;
	traverser->next = node;
}

void insertDescendingOrder(List *node){
	if (isEmpty()){
		head = node;
		return;
	} else if (head->data < node->data){
		node->next = head;
		head = node;
		return;
	}
	List *traverser = head;
	while (traverser->next != NULL && traverser->next->data > node->data){
		traverser = traverser->next;
	}
	node->next = traverser->next;
	traverser->next = node;
}

/* Remove Functions */

List *removeFromFront(void){
	if (isEmpty()){
		return NULL;
	}
	List *remover = head;
	head = head->next;
	return remover;
}

List *removeFromBack(void){
	if (isEmpty()){
		return NULL;
	} else if (head->next = NULL){
		List *remover = head;
		head = NULL;
		return remover;
	}
	List *traverser = head, *remover = NULL;
	while (traverser->next->next != NULL){
		traverser = traverser->next;
	}
	remover = traverser->next;
	traverser->next = NULL;
	return remover;
}

List *removeValue(int value){
	if (isEmpty()){
		return NULL;
	} else if (head->data == value){
		List *remover = head;
		head = head->next;
		return remover;
	}
	List *remover = head;
	while (remover != NULL && remover->data != value){
		remover = remover->next;
	}
	return remover; //will return node with specified data or NULL if value is not in list
}

/* Delete Functions */

void deleteFront(void){
	if (isEmpty()){
		return;
	}
	List *deleter = head;
	head = head->next;
	free(deleter);
}

void deleteBack(void){
	if (isEmpty()){
		return;
	} else if (head->next == NULL){
		free(head);
		head = NULL;
		return;
	}
	List *traverser = head, *deleter = NULL;
	while (traverser->next->next != NULL){
		traverser = traverser->next;
	}
	deleter = traverser->next;
	traverser->next = NULL;
	free(deleter);
}

void deleteValue(int value){
	if (isEmpty()){
		return NULL;
	} else if (head->data == value){
		List *deleter = head;
		head = head->next;
		free(deleter);
	}
	List *deleter = head;
	while (deleter != NULL && deleter->data != value){
		deleter = deleter->next;
	}
	if (deleter == NULL){
		return;
	}
	free(deleter);
}

void deleteList(void){
	if (isEmpty()){
		return;
	}
	List *traverser = head, *deleter = NULL;
	while (traverser != NULL){
		deleter = traverser;
		traverser = traverser->next;
		free(deleter);
	}
}

int main(void){
	
	return 0;
}