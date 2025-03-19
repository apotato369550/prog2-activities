#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

void insertLast(Node **head, int value);
void insertFirst(Node **head, int value);
void insertInto(Node **head, int value, int index);
int getLinkedListLength(Node *head);
void deleteLast(Node **head);
void deleteFirst(Node **head);
void deleteIndex(Node **head, int index);

int main() {
	Node *head = NULL;
	insertLast(&head, 0);
	insertLast(&head, 1);
	insertLast(&head, 2);
	insertFirst(&head, 4);
	insertFirst(&head, 5);
	insertFirst(&head, 6);
	insertInto(&head, 7, 0);
	insertInto(&head, 8, 3);
	insertInto(&head, 9, 6);
	
	// expected output
	// 7 6 5 8 4 0 9 1 2
	deleteIndex(&head, 3);
	
	while (head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	
	return 0;
}

void deleteIndex(Node **head, int index) {
	Node *temp = *head;
	if (*head == NULL) {
		printf("The list is already empty...\n");
	} else if(temp->next == NULL) {
		free(*head);
		*head = NULL;
	} else {
		if (index >= getLinkedListLength(*head)) {
			deleteLast(head);
		} else {
			int i = 0;
			while (temp->next != NULL && i < index - 1) {
				i++;
				temp = temp->next;
			}
			Node *select = temp->next;
			temp->next = select->next;
			free(select);
		}
	}
}

void deleteLast(Node **head) {
	Node *temp = *head;
	if (*head == NULL) {
		printf("The list is already empty...\n");
	} else if(temp->next == NULL) {
		free(*head);
		*head = NULL;
	} else {
		while(temp->next->next != NULL) {
			temp = temp->next;
		}
		Node *last = temp->next;
		temp->next = NULL;
		free(last);
	}
}

void deleteFirst(Node **head) {
	Node *temp = *head;
	if (*head == NULL) {
		printf("The list is already empty...\n");
	} else if(temp->next == NULL) {
		free(*head);
		*head = NULL;
	} else {
		*head = temp->next;
		free(temp);
	}
}

int getLinkedListLength(Node *head) {
	int length = 0;
	while(head != NULL) {
		head = head->next;
		length++;
	}
	
	return length;
}

void insertLast(Node **head, int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	} else {
		Node *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void insertFirst(Node **head, int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	} else {
		newNode->next = *head;
		*head = newNode;
	}
}

void insertInto(Node **head, int value, int index) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	} else {
		if (index == 0) {
			insertFirst(head, value);
		} else {
			int i = 0;
			Node *temp = *head;
			while (temp->next != NULL && i < index - 1) {
				i++;
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}
