#include <stdio.h>

int main() {
	int array[100];
	int arrayCount;
	printf("Please input size of array: ");
	scanf("%d", &arrayCount);
	int i;
	
	for (i = 0; i < arrayCount; i++) {
		printf("Enter a random integer value: ");
		scanf("%d", &array[i]);
	}
	
	for(i = 0; i < arrayCount; i++) {
		if (array[i] % 2 == 0) {
			array[i] *= 2;
		} else {
			array[i] *= 3;
		}
	}
	
	printf("Printing all the elements in the array: \n");
	
	for(i = 0; i < arrayCount; i++) {
		printf("%d \n", array[i]);
	}
	
	return 0;
}
