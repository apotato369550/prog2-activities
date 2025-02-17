// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void printArray(int array[], int arrayCount);
void insertFirst(int array[], int *arrayCount, int item);
void insertLast(int array[], int *arrayCount, int item);
void deleteFirst(int array[], int *arrayCount);
void deleteLast(int *arrayCount);

int main() {
    int array[100] = {1, 2, 3, 4, 5};
    int arrayCount = 5;
    int i;
    printf("Welcome to array operations!");
    // insert first, insert last, delete first, delete last
    printArray(array, arrayCount);
    
    int on = 1;
    
    while (on) {
    	printf("Select operation: \n");
    	printf("1 - Insert First \n");
    	printf("2 - Insert Last \n");
    	printf("3 - Delete First \n");
    	printf("4 - Delete Last \n");
    	printf("5 - Quit \n");
    	
    	int input;
    	printf("Enter your choice: ");
    	scanf("%d", &input);
    	int item;
    	
    	switch(input) {
    		case 1:
    			printf("You selected: Insert First");
    			printf("\nEnter the item to insert first: ");
    			scanf("%d", &item);
    			insertFirst(array, &arrayCount, item);
    			break;
    		case 2:
    			printf("You selected: Insert Last");
    			printf("\nEnter the item to insert last: ");
    			scanf("%d", &item);
    			insertLast(array, &arrayCount, item);
    			break;
    		case 3:
    			printf("\nYou selected: Delete First");
    			deleteFirst(array, &arrayCount);
    			break;
    		case 4:
    			printf("\nYou selected: Delete Last");
    			deleteLast(&arrayCount);
    			break;
    		case 5:
    			printf("\nYou selected: Exit\n");
    			on = 0;
    			break;
		}
		printArray(array, arrayCount);
	}

    return 0;
}

void printArray(int array[], int arrayCount) {
	int i;
	printf("Printing the elements of the array: \n");
	for (i = 0; i < arrayCount; i++) {
		printf("%d ", array[i]);
	}
	printf(" - Count of the Array: %d -", arrayCount);
}

void insertFirst(int array[], int *arrayCount, int item) {
	int i;
	for (i = *arrayCount; i >= 0; i--) {
		array[i] = array[i - 1];
	}
	array[0] = item;
	*arrayCount += 1;
}

void insertLast(int array[], int *arrayCount, int item) {
	array[*arrayCount] = item;
	*arrayCount += 1;
}

void deleteFirst(int array[], int *arrayCount) {
	int i;
	for (i = 0; i < *arrayCount; i++) {
		array[i] = array[i + 1];
	}
	*arrayCount -= 1;
}

void deleteLast(int *arrayCount) {
	*arrayCount -= 1;
}

