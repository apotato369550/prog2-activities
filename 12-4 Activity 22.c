#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp = fopen("example1.txt", "r+");
	
	if (fp == NULL) {
		printf("File not found...\n");
		return 0;
	}
	int value = 0;
	int count = 0;
	while (fread(&value, sizeof(int), 1, fp) == 1) {
		count++;
	}
	
	int *array = malloc(sizeof(int) * count);
	int i = 0;
	fseek(fp, 0, SEEK_SET);
	while (fread(&value, sizeof(int), 1, fp) == 1) {
		array[i] = value;
		i++;
	}
	
	for(i = 0; i < count; i++) {
		printf("Value [%d]: %d\n", i + 1, array[i]);
	}
	
	return 0;
}
