/*
	Singly Linked Lists
*/

typedef struct list{
	int data;
	struct list *next;
	struct list *prev;
} List;

List *head = NULL;

List *createNode(int value){
	List *node = malloc(sizeof(List));
	node->data = value;
	node->next = NULL;
	node->prev = NULL;
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
	head->prev = node;
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
	node->prev = traverser;
	traverser->next = node;
}

void insertAscendingOrder(List *node){
	if (isEmpty()){
		head = node;
		return;
	} else if (head->data > node->data){
		node->next = head;
		head->prev = node;
		head = node;
		return;
	}
	List *traverser = head;
	while (traverser->next != NULL && traverser->next->data < node->data){
		traverser = traverser->next;
	}
	node->next = traverser->next;
	node->prev = traverser;
	traverser->next->prev = node;
	traverser->next = node;
}

void insertAscendingOrder(List *node){
	if (isEmpty()){
		head = node;
		return;
	} else if (head->data < node->data){
		node->next = head;
		head->prev = node;
		head = node;
		return;
	}
	List *traverser = head;
	while (traverser->next != NULL && traverser->next->data > node->data){
		traverser = traverser->next;
	}
	node->next = traverser->next;
	node->prev = traverser;
	traverser->next->prev = node;
	traverser->next = node;
}

/* Remove Functions */

List *removeFromFront(void){
	if (isEmpty()){
		return NULL;
	}
	List *remover = head;
	head = head->next;
	head->prev = NULL;
	remover->next = NULL;
	return remover;
}

List *removeFromBack(void){
	if (isEmpty()){
		return NULL;
	} else if (head->next == NULL){
		List *remover = head;
		head = NULL;
		return remover;
	}
	List *traverser = head, *remover = NULL;
	while (traverser->next != NULL){
		traverser = traverser->next;
	}
	remover = traverser;
	traverser = traverser->prev;
	traverser->next = NULL;
	return traverser;
}

List *removeValue(int value){
	if (isEmpty()){
		return NULL;
	} else if (head->data == value){
		List *remover = head;
		head = head->next;
		head->prev = NULL;
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
}

void deleteBack(void){
	
}

void deleteValue(int value){
	
}

void deleteList(void){
	
}

int main(void){
	
}