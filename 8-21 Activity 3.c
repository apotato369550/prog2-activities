#include <stdio.h>

int main() {
	int array[100], oddArray[100], evenArray[100];
	int arrayCount = 0, oddArrayCount = 0, evenArrayCount = 0;
	
	printf("Please input size of array: ");
	scanf("%d", &arrayCount);
	int i;
	
	for (i = 0; i < arrayCount; i++) {
		printf("Enter a random integer value: ");
		scanf("%d", &array[i]);
	}
	
	for(i = 0; i < arrayCount; i++) {
		if (array[i] % 2 == 0) {
			evenArray[evenArrayCount] = array[i];
			evenArrayCount++;
		} else {
			oddArray[oddArrayCount] = array[i];
			oddArrayCount++;
		}
	}
	
	printf("Printing all the elements in the even array: \n");
	
	for(i = 0; i < evenArrayCount; i++) {
		printf("%d \n", evenArray[i]);
	}
	
	printf("Printing all the elements in the odd array: \n");
	
	for(i = 0; i < oddArrayCount; i++) {
		printf("%d \n", oddArray[i]);
	}
	
}
