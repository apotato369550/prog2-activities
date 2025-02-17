#include <stdio.h>

typedef struct personInfo {
	int age;
	char name[50];
	int allowance[5];
	int weeklyAllowance;
} personInfo;

int main() {
	int peopleSize;
	int i,j;
	printf("Enter number of people: ");
	scanf("%d", &peopleSize);
	fflush(stdin);
	personInfo people[peopleSize];
	for(i = 0; i < peopleSize; i++) {
		printf("Enter person %d's name: ", i + 1);
		gets(people[i].name);
		printf("Enter %s's age: ", people[i].name);
		scanf("%d", &people[i].age);
		fflush(stdin);
		printf("Enter daily allowance: \n");
		people[i].weeklyAllowance = 0;
		for (j = 0; j < 5; j++) {
			printf("Enter allowance for day %d: ", j + 1);
			scanf("%d", &people[i].allowance[j]);
			people[i].weeklyAllowance += people[i].allowance[j];
		}
		fflush(stdin);
	}
	
	printf("Displaying all people and their weekly allowance: \n");
	for(i = 0; i < peopleSize; i++) {
		printf("Name: %s \nAge: %d \n", people[i].name, people[i].age);
		printf("Weekly allowance: %d\n", people[i].weeklyAllowance);
	}
	return 0;
}
