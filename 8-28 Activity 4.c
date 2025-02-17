#include <stdio.h>
#include <stdlib.h>

int* getEven(int array[], int arrayCount, int* evenCount);

int main() {
	int array[100];
	int arrayCount = 0, evenCount = 0;
	
	printf("Please input size of array: ");
	scanf("%d", &arrayCount);
	int i;
	
	for (i = 0; i < arrayCount; i++) {
		printf("Enter a random integer value: ");
		scanf("%d", &array[i]);
	}
	
	int* evenArray = getEven(array, arrayCount, &evenCount);
	
	for (i = 0; i < evenCount; i++) {
		printf("%d \n", evenArray[i]);
	}
	
	
	return 0;
}

int* getEven(int array[], int arrayCount, int* evenCount) {
	int i, j = 0;
	
	for (i = 0; i < arrayCount; i++) {
		if(array[i] % 2 == 0) {
			*evenCount = *evenCount + 1;
		}
	}
	int* evenArray = malloc((*evenCount) * sizeof(int));
	for(i = 0; i < arrayCount; i++) {
		if(array[i] % 2 == 0) {
			evenArray[j] = array[i];
			j++;
		}
	}
	return evenArray;
}
