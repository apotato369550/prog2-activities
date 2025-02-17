#include <stdio.h>

typedef struct {
	char firstName[20];
	char middleInitial;
	char lastName[20];
} Name;

typedef struct {
	char schoolName[50];
	char schoolAddress[50];
} School;

typedef struct {
	Name name;
	School school;
	int age;
	float height;
} Person;

int main() {
	Person person;
	
	printf("Enter person's first name: ");
	gets(person.name.firstName);
	printf("Enter person's middle initial: ");
	scanf(" %c", &person.name.middleInitial);
	fflush(stdin);
	printf("Enter person's last name: ");
	gets(person.name.lastName);
	
	printf("Enter person's age: ");
	scanf("%d", &person.age);
	printf("Enter person's height: ");
	scanf("%f", &person.height);
	
	fflush(stdin);
	printf("Enter person's school: ");
	gets(person.school.schoolName);
	printf("Enter person's school address: ");
	gets(person.school.schoolAddress);
	
	
	printf("Printing info about person: \n");
	printf("Person's full name: %s %c. %s\n", person.name.firstName, person.name.middleInitial, person.name.lastName);
	
	printf("Person's age: %d \t Person's height: %.2f\n", person.age, person.height);
	
	printf("Person's school: %s\n", person.school.schoolName);
	printf("School Address: %s\n", person.school.schoolAddress);
}
