#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char fName[50];
	char MI;
} name;

typedef struct {
	name personName;
	int age;
} personInfo;

personInfo* getAbove18(personInfo people[], int peopleSize, int *above18Count);

int main() {
	int i;
	personInfo people[5] = {
		{{"Patrick", 'M'}, 28},
		{{"Gran", 'M'}, 29},
		{{"Chiz", 'M'}, 16},
		{{"Josh", 'M'}, 30},
		{{"John", 'M'}, 12}
	};
	
	int above18Count = 0;
	personInfo *peopleAbove18 = getAbove18(people, 5, &above18Count);
	
	printf("The following people are above 18: \n");
	for (i = 0; i < above18Count; i++) {
		printf("%s - %d \n", peopleAbove18[i].personName.fName, peopleAbove18[i].age);
	}
	
	return 0;
}

personInfo* getAbove18(personInfo people[], int peopleSize, int *above18Count) {
	int i;
	for (i = 0; i < peopleSize; i++) {
		if (people[i].age >= 18) {
			*above18Count += 1;
		}
	}
	personInfo *peopleAbove18 = malloc(sizeof(personInfo) * (*above18Count));
	int peopleCounter = 0;
	for (i = 0; i < peopleSize; i++) {
		if (people[i].age >= 18) {
			peopleAbove18[peopleCounter] = people[i];
			peopleCounter += 1;
		}
	}
	return peopleAbove18;
}
