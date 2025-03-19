#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

void displayLinkedList(Node *head);
int getLinkedListLength(Node *head);
void insertLast(Node **head, int value);
void insertFirst(Node **head, int value);
void insertInto(Node **head, int value, int index);
void insertLastPointer(Node **head, int value);
void insertIntoPointer(Node **head, int value, int index);
void deleteLast(Node **head);
void deleteFirst(Node **head);
void deleteIndex(Node **head, int index);
void deleteLastPointer(Node **head);
void deleteIndexPointer(Node **head, int index);

int main () {
	Node *head = NULL;
	int choice = -1;
	int value = -1;
	int index = -1;
	printf("Welcome to Linked List Mania!!!\n");
	
	while (choice != 0) {
		printf("Select an option: \n");
		printf("0 - Exit\n");
		printf("1 - Display Linked List\n");
		printf("2 - Insert Last (Pointer to node)\n");
		printf("3 - Insert First\n");
		printf("4 - Insert Into (Pointer to node)\n");
		printf("5 - Insert Last (Pointer to pointer to node)\n");
		printf("6 - Insert Into (Pointer to pointer to node)\n");
		printf("7 - Delete Last (Pointer to node)\n");
		printf("8 - Delete First\n");
		printf("9 - Delete Index (Pointer to node)\n");
		printf("10 - Delete Last (Pointer to pointer to node)\n");
		printf("11 - Delete Into (Pointer to pointer to node)\n");
		
		scanf("%d", &choice);
		switch(choice) {
			case 0:
				printf("Exiting program...");
				break;
			case 1:
				printf("Displaying linked list...");
				displayLinkedList(head);
				break;
			case 2:
				printf("Inserting last via pointer to node...");
				printf("Input value to insert: ");
				scanf("%d", &value);
				insertLast(&head, value);
				break;
			case 3:
				printf("Inserting first...");
				printf("Input value to insert: ");
				scanf("%d", &value);
				insertFirst(&head, value);
				break;
			case 4:
				printf("Inserting into via pointer to node...");
				printf("Input value to insert: ");
				scanf("%d", &value);
				printf("Enter index to insert into: ");
				scanf("%d", &index);
				insertInto(&head, value, index);
				break;
			case 5:
				printf("Inserting last via pointer to pointer to node...");
				printf("Input value to insert: ");
				scanf("%d", &value);
				insertLastPointer(&head, value);
				break;
			case 6:
				printf("Inserting into via pointer to pointer to node...");
				printf("Input value to insert: ");
				scanf("%d", &value);
				printf("Enter index to insert into: ");
				scanf("%d", &index);
				insertIntoPointer(&head, value, index);
				break;
			case 7:
				printf("Deleting last via pointer to node...");
				deleteLast(&head);
				break;
			case 8:
				printf("Deleting first via pointer to node...");
				deleteFirst(&head);
				break;
			case 9:
				printf("Deleting index via pointer to node...");
				printf("Enter index to delete: ");
				scanf("%d", &index);
				deleteIndex(&head, index);
				break;
			case 10:
				printf("Deleting last via pointer to pointer to node...");
				deleteLastPointer(&head);
				break;
			case 11:
				printf("Deleting index via pointer to pointer to node...");
				printf("Enter index to delete: ");
				scanf("%d", &index);
				deleteIndexPointer(&head, index);
				break;
		}
	}
}

void displayLinkedList(Node *head) {
	if (head == NULL) {
		printf("The linked list is empty!\n");
	} else {
		int i = 0;
		Node *temp = head;
		printf("Linked list length: %d\n", getLinkedListLength(head));
		while (head != NULL) {
			printf("Value at index [%d]: %d\n", i, head->value);
			head = head->next;
			i++;
		}
	}
}

int getLinkedListLength(Node *head) {
	int length = 0;
	while (head != NULL) {
		length++;
		head = head->next;
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
	printf("Node successfully inserted!\n");
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
	printf("Node successfully inserted!\n");
}

void insertInto(Node **head, int value, int index) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	} else if ((*head)->next == NULL) {
		insertLast(head, value);
		return;
	} else {
		if (index == 0) {
			insertFirst(head, value);
			return;
		} else if (index > getLinkedListLength(*head)) {
			insertLast(head, value);
			return;
		} else {
			int i = 0;
			Node *temp = *head;
			while (temp->next != NULL && i < index - 1) {
				temp = temp->next;
				i++;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			
		}
	}
	printf("Node successfully inserted!\n");
}

void insertLastPointer(Node **head, int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	while (*head != NULL) {
		head = &(*head)->next; 
	}
	*head = newNode;
	printf("Node successfully inserted!\n");
}

void insertIntoPointer(Node **head, int value, int index) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	int i = 0;
	while (*head != NULL && i < index) {
		head = &(*head)->next; 
		i++;
	}
	newNode->next = *head;
	*head = newNode;
	printf("Node successfully inserted!\n");
}

void deleteLast(Node **head) {
	if (*head == NULL) {
		printf("List is already empty...\n");
		return;
	} else if ((*head)->next == NULL) {
		free((*head));
		*head = NULL;
	} else {
		Node *temp = *head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
	printf("Deletion successful!\n");
}

void deleteFirst(Node **head) {
	if (*head == NULL) {
		printf("List is already empty...\n");
		return;
	} else if ((*head)->next == NULL) {
		free((*head));
		*head = NULL;
	} else {
		Node *temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
	printf("Deletion successful!\n");
}

void deleteIndex(Node **head, int index) {
	if (*head == NULL) {
		printf("List is already empty...\n");
		return;
	} else if ((*head)->next == NULL) {
		free((*head));
		*head = NULL;
	} else {
		if (index == 0) {
			deleteFirst(head);
			return;
		} else if (index >= getLinkedListLength(*head)) {
			deleteLast(head);
			return;
		}
		Node *temp = *head;
		int i = 0;
		while (temp->next->next != NULL && i < index - 1) {
			temp = temp->next;
			i++;
		}
		Node *toDelete = temp->next;
		temp->next = temp->next->next;
		free(toDelete);
	}
	printf("Deletion successful!\n");
}

void deleteLastPointer(Node **head) {
	if (*head == NULL) {
		printf("List is already empty...\n");
		return;
	} else if ((*head)->next == NULL) {
		free((*head));
		*head = NULL;
	} else {
		while ((*head)->next != NULL) {
			head = &(*head)->next;
		}
		free((*head));
		*head = NULL;
	}
}

void deleteIndexPointer(Node **head, int index) {
	if (*head == NULL) {
		printf("List is already empty...\n");
		return;
	} else if ((*head)->next == NULL) {
		free((*head));
		*head = NULL;
	} else {
		if (index == 0) {
			deleteFirst(head);
			return;
		} else if (index >= getLinkedListLength(*head)) {
			deleteLast(head);
			return;
		}
		int i = 0;
		while ((*head)->next != NULL && i < index) {
			i++;
			head = &(*head)->next;
		}
		Node *temp = *head;
		*head = temp->next;
		free(temp);
	}
}


