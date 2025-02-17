#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char productName[50];
	int price;
} Product;

typedef struct Node {
	Product data;
	struct Node *next;
} Node;

void displayProducts(Node *head);
void insertProductLast(Node **head, char productName[], int price);
void deleteProductLast(Node **head);

int main() {
	printf("Welcome to Prog 2 Catalog!\n");
	Node *head = NULL;
	char productName[50];
	int price = 0;
	int input = -1;
	
	while (input != 0) {
		printf("Choices \n");
		printf("1 - Insert product last\n");
		printf("2 - Delete product last\n");
		printf("3 - Display products\n");
		
		scanf("%d", &input);
		
		switch(input) {
			case 0:
				printf("Exiting program...\n");
				break;
			case 1: 
				printf("Inserting product last...\n");
				printf("Enter product name: ");
				scanf("%s", productName);
				printf("Enter product price: ");
				scanf("%d", &price);
				insertProductLast(&head, productName, price);
				break;
			case 2:
				printf("Deleting product last...\n");
				deleteProductLast(&head);
				break;
			case 3:
				printf("Displaying products...\n");
				displayProducts(head);
				break;
		}
	}
	
	return 0;
}

void displayProducts(Node *head) {
	int i = 0;
	while(head != NULL) {
		printf("Product number: %d\n", i + 1);
		printf("Name of Product: %s\n", head->data.productName);
		printf("Price of Product: %d\n", head->data.price);
		head = head->next;
		i++;
	}
}

void insertProductLast(Node **head, char productName[], int price) {
	Node *newProduct = malloc(sizeof(Node));
	newProduct->data.price = price;
	strcpy(newProduct->data.productName, productName);
	newProduct->next = NULL;
	
	while (*head != NULL) {
		head = &(*head)->next;
	}
	*head = newProduct;
	printf("Product successfully inserted!!!\n");
}

void deleteProductLast(Node **head) {
	if (*head == NULL) {
		printf("Catalog already empty! \n");
		return;
	} else if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
	} else {
		while ((*head)->next != NULL) {
			head = &(*head)->next;
		}
		free(*head);
		*head = NULL;
	}
	printf("Product successfully deleted!!!\n");
}
