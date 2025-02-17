#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	int age;
} person;

typedef struct {
	person personList[10];
	int count;
} personRecord;

void displayPersonRecord(personRecord record);
void insertLast(personRecord *record, person insert);
void deleteLast(personRecord *record);
void insertFirst(personRecord *record, person insert);
void deleteFirst(personRecord *record);
void insertAtIndex(personRecord *record, person insert, int index);
void deleteAtIndex(personRecord *record, int index);
void deleteAllOccurences(personRecord *record, person deletePerson);

int main() {
	printf("Welcome to person record adder!!!");
	int input = 1;
	char name[20];
	int age = 0;
	personRecord record;
	person insert;
	int index = 0;
	record.count = 0;
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Display ADT\n");
	printf("2 - Insert Last\n");
	printf("3 - Delete Last \n");
	printf("4 - Insert First\n");
	printf("5 - Delete First \n");
	printf("6 - Insert at Index\n");
	printf("7 - Delete at Index \n");
	printf("8 - Delete all occurences \n");
	while (input != 0) {
		
		scanf("%d", &input);
		switch (input) {
			case 0:
				printf("Exiting program...\n");
				break;
			case 1:
				printf("Displaying personRecord: \n");
				displayPersonRecord(record);
				break;
			case 2:
				printf("Inserting last... \n");
				printf("Enter name of person to insert: ");
				scanf("%s", name);
				printf("Enter age of  person to insert: ");
				scanf("%d", &age);
				strcpy(insert.name, name);
				insert.age = age;
				insertLast(&record, insert);
				break;
			case 3:
				printf("Deleting last...\n");
				deleteLast(&record);
				break;
			case 4:
				printf("Inserting first... \n");
				printf("Enter name of person to insert: ");
				scanf("%s", name);
				printf("Enter age of  person to insert: ");
				scanf("%d", &age);
				strcpy(insert.name, name);
				insert.age = age;
				insertFirst(&record, insert);
				break;
			case 5:
				printf("Deleting first...\n");
				deleteFirst(&record);
				break;
			case 6:
				printf("Inserting at index... \n");
				printf("Enter name of person to insert: ");
				scanf("%s", name);
				printf("Enter age of  person to insert: ");
				scanf("%d", &age);
				printf("Enter index to insert at: ");
				scanf("%d", &index);
				strcpy(insert.name, name);
				insert.age = age;
				insertAtIndex(&record, insert, index);
				break;
			case 7:
				printf("Deleting at index...\n");
				printf("Enter index to delete at: ");
				scanf("%d", &index);
				deleteAtIndex(&record, index);
				break;
			case 8:
				printf("Deleting all occurrences of person... \n");
				printf("Enter name of person to insert: ");
				scanf("%s", name);
				printf("Enter age of  person to insert: ");
				scanf("%d", &age);
				strcpy(insert.name, name);
				insert.age = age;
				deleteAllOccurences(&record, insert);
				break;
		}
	}
}

void displayPersonRecord(personRecord record) {
	if (record.count <= 0) {
		printf("personRecord is empty! \n");
	} else {
		for (int i = 0; i < record.count; i++) {
			printf("[%d] Name: %s --- Age: %d\n", i, record.personList[i].name, record.personList[i].age);
		}
	}
}

void insertLast(personRecord *record, person insert) {
	if (record->count >= 10) {
		printf("Record is full! Cancelling insert...\n");
		return;
	}
	record->personList[record->count] = insert;
	record->count++;
	printf("Person successfully recorded!\n");
}

void deleteLast(personRecord *record) {
	if (record->count == 0) {
		printf("Record is already empty...\n");
	} else {
		record->count--;
		printf("Person successfully deleted!\n");
	}
}
 
void insertFirst(personRecord *record, person insert) {
	if (record->count >= 10) {
		printf("Record is full! Cancelling insert...\n");
		return;
	}
	for (int i = record->count; i > 0; i--) {
		record->personList[i] = record->personList[i - 1];
	}
	record->personList[0] = insert;
	record->count++;
	printf("Person successfully recorded!\n");
}

void deleteFirst(personRecord *record) {
	if (record->count == 0) {
		printf("Record is already empty...\n");
	} else {
		for (int i = 0; i < record->count; i++) {
			record->personList[i] = record->personList[i + 1];
		}
		record->count--;
		printf("Person successfully deleted!\n");
	}
}
 
void insertAtIndex(personRecord *record, person insert, int index) {
	if (record->count >= 10) {
		printf("Record is full! Cancelling insert...\n");
		return;
	}
	if (index > record->count) {
		printf("Index too high! Inserting at next nearest index...\n");
		insertLast(record, insert);
		return;
	}
	for (int i = record->count; i > index; i--) {
		record->personList[i] = record->personList[i - 1];
	}
	record->personList[index] = insert;
	record->count++;
	printf("Person successfully recorded!\n");
}

void deleteAtIndex(personRecord *record, int index) {
	if (index > record->count) {
		printf("Index too high! Deleting at next nearest index...\n");
		deleteLast(record);
		return;
	}
	if (record->count == 0) {
		printf("Record is already empty...\n");
	} else {
		for (int i = index; i < record->count; i++) {
			record->personList[i] = record->personList[i + 1];
		}
		record->count--;
		printf("Person successfully deleted!\n");
	}
}

void deleteAllOccurences(personRecord *record, person deletePerson) {
	if (record->count == 0) {
		printf("Record is already empty...\n");
	} else {
		for (int i = record->count - 1; i >= 0; i--) {
			if (strcmp(record->personList[i].name, deletePerson.name) == 0 && record->personList[i].age == deletePerson.age) {
				deleteAtIndex(record, i);
			}
		}
		printf("Deleted all instances of person!\n");
	}
}

