#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

void insertLast(Node **head, int value);
void insertFirst(Node **head, int value);
void insertInto(Node **head, int value, int index);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteIndex(Node **head, int index);
void displayLinkedList(Node *head);
int getLinkedListLength(Node *head);

int main() {
	Node *head = NULL;
	int value = 0;
	int choice = -1;
	int index = -1;
	printf("Welcome to Linked List Mania!\n");
	
	while (choice != 0) {
		printf("Perform an action: \n");
		printf("1 - Insert Last \n");
		printf("2 - Insert First \n");
		printf("3 - Insert Into \n");
		printf("4 - Delete Last \n");
		printf("5 - Delete First \n");
		printf("6 - Delete Index \n");
		printf("7 - Display linked list. \n");
		printf("0 - Exit \n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Inserting Last...\n");
				printf("Enter number you wish to insert: ");
				scanf("%d", &value);
				insertLast(&head, value);
				break;
			case 2:
				printf("Inserting First...\n");
				printf("Enter number you wish to insert: ");
				scanf("%d", &value);
				insertFirst(&head, value);
				break;
			case 3:
				printf("Inserting Into...\n");
				printf("Enter number you wish to insert: ");
				scanf("%d", &value);
				printf("Enter the index you wish to insert: ");
				scanf("%d", &index);
				insertInto(&head, value, index);
				break;
			case 4:
				printf("Deleting Last...\n");
				deleteLast(&head);
				break;
			case 5:
				printf("Deleting First...\n");
				deleteFirst(&head);
				break;
			case 6:
				printf("Deleting at index...");
				printf("Enter the index you wish to delete: ");
				scanf("%d", &index);
				deleteIndex(&head, index);
			case 7:
				printf("Displaying linked list...\n");
				displayLinkedList(head);
			case 0:
				break;
		}
	}
}

void displayLinkedList(Node *head) {
	if (head == NULL) {
		printf("Linked list is empty. Insert some values first!");
	} else {
		int i = 0;
		printf("Length of Linked List: %d\n", getLinkedListLength(head));
		while (head != NULL) {
			printf("Value at index %d: %d\n", i, head->value);
			i++;
			head = head->next;
		}
	}
	printf("Sucessfully displayed linked list.\n");
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
	newNode->next = NULL;
	newNode->value = value;
	if (*head == NULL) {
		*head = newNode;
	} else {
		Node *temp = *head;
		while (temp->next != NULL) {
			temp= temp->next;
		}
		temp->next = newNode;
	}
	printf("Insertion Successful!\n");
}

void insertFirst(Node **head, int value) {
	Node *newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->value = value;
	if (*head == NULL) {
		*head = newNode;
	} else {
		newNode->next = *head;
		*head = newNode;
	}
	printf("Insertion Successful!\n");
}

void insertInto(Node **head, int value, int index) {
	Node *newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->value = value;
	if (*head == NULL) {
		*head = newNode;
	} else {
		if (index == 0) {
			insertFirst(head, value);
		} else if (index >= getLinkedListLength(*head)) {
			insertLast(head, value);
		} else {
			Node *temp = *head;
			int i = 0;
			while (temp->next != NULL && i < index - 1) {
				i++;
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			printf("Insertion Successful!\n");
		}
	}
}

void deleteFirst(Node **head) {
	Node *traverse = *head;
	if (traverse == NULL) {
		printf("Linked List already empty...\n");
	} else if (traverse->next == NULL) {
		free(*head);
		*head = NULL;
		printf("Deletion successful!\n");
	} else {
		*head = traverse->next;
		free(traverse);
		printf("Deletion successful!\n");
	}
}


void deleteLast(Node **head) {
	Node *traverse = *head;
	if (*head == NULL) {
		printf("Linked List already empty...\n");
	} else if (traverse->next == NULL) {
		free(*head);
		*head = NULL;
		printf("Deletion successful!\n");
	} else {
		while (traverse->next->next != NULL) {
			traverse = traverse->next;
		}
		Node *temp = traverse;
		traverse->next = NULL;
		free(temp->next);
		printf("Deletion successful!\n");
	}
}

void deleteIndex(Node **head, int index) {
	Node *traverse = *head;
	if (*head == NULL) {
		printf("Linked List already empty...\n");
	} else if (traverse->next == NULL) {
		free(*head);
		*head = NULL;
		printf("Deletion successful!\n");
	} else {
		int i = 0;
		while (traverse->next->next != NULL && i < index - 1) {
			i++;
			traverse = traverse->next;
		}
		Node *temp = traverse->next;
		traverse->next = temp->next;
		free(temp);
		printf("Deletion successful!\n");
	}
}



