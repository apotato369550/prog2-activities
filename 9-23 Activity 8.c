#include <stdio.h>

struct PersonInfo {
	int age;
	float height;
	char name[50];
};

int main() {
	struct PersonInfo person;
	
	printf("Enter the age of the person: ");
	scanf("%d", &person.age);
	
	printf("Enter the height of the person: ");
	scanf("%f", &person.height);
	
	fflush(stdin);
	printf("Enter the name of the person: ");
	gets(person.name);
	
	printf("Here is your info: \n");
	printf("Name: %s\n", person.name);
	printf("Age: %d\n", person.age);
	printf("Height: %.2f", person.height);
}
