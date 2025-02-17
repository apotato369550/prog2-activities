#include <stdio.h>

typedef struct personInfo {
	int age;
	char name[50];
} personInfo;

int main() {
	int i;
	personInfo people[5];
	for( i = 0; i < 5; i++) {
		printf("Enter person %d's name: ", i + 1);
		gets(people[i].name);
		printf("Enter %s's age: ", people[i].name);
		scanf("%d", &people[i].age);
		fflush(stdin);
	}
	
	printf("Displaying all people above 18: \n");
	for(i = 0; i < 5; i++) {
		if (people[i].age > 18) {
			printf("%s \n", people[i].name);
		}
	}
	return 0;
}
