#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char name[30];
	float price;
	int quantity;
	Date expiry;
} Product;

typedef struct Node {
	Product product;
	struct Node *next;
} ProductNode, *ProdNodePtr, *ProductList;

// Requirements
// 1. Create a program that will populate a list of products into "product.dat"
// 2. Create a program that will create a new file that will store the expired products into "expired.dat"

void addProduct(ProductNode **head, char name[30], float price, int quantity, int month, int day, int year);
void printProducts(ProductNode *head);
void populateProducts(ProductNode *head, FILE **filePointer);
void populateExpired(ProductNode *head, FILE **filePointer, Date currentDate);
void readProducts(ProductNode **head, FILE **filePointer);

int main() {
	Date currentDate = {2, 12, 2024};
	ProductNode *head = NULL;
	
	addProduct(&head, "A5 Wagyu Steak", 4000.46, 3, 1, 16, 2025); // fresh
	addProduct(&head, "Piattos", 35, 16, 6, 26, 2026); // fresh
	addProduct(&head, "Hawaiian Pizza", 35, 16, 10, 22, 2022); // expired
	addProduct(&head, "Milk", 96, 5, 3, 6, 2023); // expired
	addProduct(&head, "Pringles", 88, 34, 6, 26, 2026);// fresh
	addProduct(&head, "Mangoes", 180, 7, 9, 2, 2017); // expired
	
	// printProducts(head);
	
	FILE *writePointer = fopen("products.dat", "wb");
	populateProducts(head, &writePointer);
	
	FILE *expiredPointer = fopen("expired.dat", "wb");
	populateExpired(head, &expiredPointer, currentDate);
	
	ProductNode *newHead = NULL;
	FILE *readPointer = fopen("products.dat", "rb");
	readProducts(&newHead, &readPointer);
	
	ProductNode *expiredHead = NULL;
	FILE *expiredRead = fopen("expired.dat", "rb");
	readProducts(&expiredHead, &expiredRead);
	
	printf("Printing All products: \n");
	printProducts(newHead);
	
	printf("Printing Expired products: \n");
	printProducts(expiredHead);
	
	
	return 0;
	
}

void addProduct(ProductNode **head, char name[30], float price, int quantity, int month, int day, int year) {
	ProductNode *newNode = malloc(sizeof(ProductNode));
	strcpy(newNode->product.name, name);
	newNode->product.price = price;
	newNode->product.quantity = quantity;
	Date expiry = {day, month, year};
	newNode->product.expiry = expiry;
	newNode->next = NULL;
	while (*head != NULL) {
		head = &(*head)->next;
	}
	*head = newNode;
}

void printProducts(ProductNode *head) {
	while (head != NULL) {
		char *name = head->product.name;
		float price = head->product.price;
		int quantity = head->product.quantity;
		Date expiry = head->product.expiry;
		printf("Product: %s\nPrice: %.2f\nQuantity: %d\nExpiry: %d-%d-%d\n\n", name, price, quantity, expiry.month, expiry.day, expiry.year);
		head = head->next;
	}
}
void populateProducts(ProductNode *head, FILE **filePointer) {
	if (*filePointer != NULL) {
		while (head != NULL) {
			// printf("Writing to 'products.dat'");
			fwrite(&(head->product), sizeof(Product), 1, *filePointer);
			head = head->next;
		}
		fclose(*filePointer);
		printf("Successfully populated 'products.dat'\n");
	} else {
		printf("Error opening 'products.dat' for writing.");
	}
}
void populateExpired(ProductNode *head, FILE **filePointer, Date currentDate) {
	if (*filePointer != NULL) {
		while (head != NULL) {
			int day = head->product.expiry.day;
			int month = head->product.expiry.month;
			int year = head->product.expiry.year;
			if (year < currentDate.year || (year == currentDate.year && month < currentDate.month) || (year == currentDate.year && month == currentDate.month && day < currentDate.day)) {
				// printf("Adding expired product...\n");
				fwrite(&(head->product), sizeof(Product), 1, *filePointer);
			} 
			head = head->next;
		}
		fclose(*filePointer);
		printf("Successfully populated 'expired.dat'\n");
	} else {
		printf("Error opening 'expired.dat' for writing.");
	}
}
void readProducts(ProductNode **head, FILE **filePointer) {
	if (*filePointer != NULL) {
		Product product;
		while (fread(&product, sizeof(Product), 1, *filePointer) != 0) {
			ProductNode *newNode = malloc(sizeof(ProductNode));
			// printf("Product Name: %s\n", product.name);	
			newNode->next = NULL;
			newNode->product = product;
			while (*head != NULL) {
				head = &(*head)->next;
			}
			*head = newNode;
		}
		fclose(*filePointer);
	} else {
		printf("Error opening 'products.dat' for reading.");
	}
	return;
}
