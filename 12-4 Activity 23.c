#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	int age;
} Person;

typedef struct node{
	Person data;
	struct node* next;
} Node;

void printLinkedList(Node *head);
void insertFirst(Node **head, Person person);
void storeLegal(Node **head, Node **legalHead);
void writeLegal(Node **head, FILE *fp);

int main() {
	Node *head = NULL;
	FILE *fp = fopen("exercise1.bin", "rb");
	
	if (fp == NULL) {
		printf("File not found...\n");
		return 0;
	}
	
	// reads contents of file to linked list
	Person tempPerson;
	while (fread(&tempPerson, sizeof(Person), 1, fp) == 1) {
		insertFirst(&head, tempPerson);
	}
	
	fclose(fp);
	
	printf("Displaying all persons: \n");
	printLinkedList(head);
	
	// store legal age persons in new linked list
	Node *legalHead = NULL;
	storeLegal(&head, &legalHead);
	// printf("Displaying all persons of legal drinking age: \n");
	// printLinkedList(legalHead);
	
	// write the new linked list into a file
	fp = fopen("legal.bin", "wb+");
	writeLegal(&legalHead, fp);
	fseek(fp, 0, SEEK_SET);
	
	// get data from file to form new linked list
	Node *newLegalHead = NULL;
	while (fread(&tempPerson, sizeof(Person), 1, fp) == 1) {
		insertFirst(&newLegalHead, tempPerson);
	}
	
	printf("Displaying all persons of legal drinking age from the file: \n");
	printLinkedList(newLegalHead);
	
	
	
	return 0;
}

void printLinkedList(Node *head) {
	while (head != NULL) {
		printf("Name: %s Age: %d\n", head->data.name, head->data.age);
		head = head->next;
	}
}

void insertFirst(Node **head, Person person) {
	Node *newNode = malloc(sizeof(Node));
	newNode->data = person;
	newNode->next = *head;
	*head = newNode;
}

void storeLegal(Node **head, Node **legalHead) {
	while (*head != NULL) {
		Person current = (*head)->data;
		if (current.age >= 21) {
			insertFirst(legalHead, current);
		}
		head = &(*head)->next;
	}
}

void writeLegal(Node **head, FILE *fp) {
	while (*head != NULL) {
		fwrite(&(*head)->data, sizeof(Person), 1, fp);
		head = &(*head)->next;
	}
}
