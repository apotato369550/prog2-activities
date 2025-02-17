#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	int age;
} personInfo;

typedef struct {
	char course[20];
	int yearLevel;
} schoolInfo;

typedef struct {
	personInfo personDetails;
	schoolInfo schoolDetails;
	int id;
	int grades[5];
	int averageGrade;
} studentProfile;

typedef struct {
	studentProfile students[10];
	int count;
} record;

record getCourse(record studentList, char course[]);
record getYear(record studentList, int year);
studentProfile getInfo(record studentList, int id);
record getPassers(record studentList);
void calculateAverage(record *studentList);
void displayRecord(record record);


int main() {
	record studentList = {
		{
			{{"Patrick", 19}, {"CS", 3}, 111, {80, 80, 80, 80, 80}, 0},
			{{"John", 20}, {"CPE", 2}, 112, {60, 70, 80, 90, 100}, 0},
			{{"James", 18}, {"IT", 1}, 113, {60, 60, 70, 70, 75}, 0},
			{{"Ronald", 21}, {"CPE", 2}, 114, {40, 50, 50, 30, 70}, 0},
			{{"Gordon", 23}, {"CS", 1}, 115, {100, 90, 85, 95, 80}, 0},
			{{"Kim", 22}, {"IT", 2}, 116, {60, 70, 80, 90, 10}, 0},
		},
		6
	};
	record yearList;
	record courseList;
	record passedList;
	studentProfile searchedStudent;

	calculateAverage(&studentList);
	
	int year;
	int i;
	printf("Enter what year level to get: ");
	scanf("%d", &year);
	yearList = getYear(studentList, year);
	displayRecord(yearList);
	
	char course[50];
	printf("Enter what course to get: ");
	scanf("%s", course);
	courseList = getCourse(studentList, course);
	displayRecord(courseList);
	
	int id;
	printf("Enter student ID to search: ");
	scanf("%d", &id);
	searchedStudent = getInfo(studentList, id);
	printf("Student Name: %s\n", searchedStudent.personDetails.name);
	printf("Student ID: %d\n", searchedStudent.id);
	printf("Student Course: %s\n", searchedStudent.schoolDetails.course);
	printf("Student Grades: \n");
	for (i = 0; i < 5; i++) {
		printf("%d ", searchedStudent.grades[i]);
	}
	printf("\nStudent Average Grade: %d\n", searchedStudent.averageGrade);
	
	printf("Displaying passers: \n");
	passedList = getPassers(studentList);
	displayRecord(passedList);
	
	
	
	
	return 0;
}

record getCourse(record studentList, char course[]) {
	int i;
	record courseRecord;
	courseRecord.count = 0;
	for (i = 0; i < studentList.count; i++) {
		if (strcmp(studentList.students[i].schoolDetails.course, course) == 0) {
			courseRecord.students[courseRecord.count] = studentList.students[i];
			courseRecord.count++;
		}
	}
	return courseRecord;
}
record getYear(record studentList, int year) {
	int i;
	record yearRecord;
	yearRecord.count = 0;
	for (i = 0; i < studentList.count; i++) {
		if (studentList.students[i].schoolDetails.yearLevel == year) {
			yearRecord.students[yearRecord.count] = studentList.students[i];
			yearRecord.count++;
		}
	}
	return yearRecord;
}
studentProfile getInfo(record studentList, int id)  {
	int i;
	studentProfile searchedStudent;
	for (i = 0; i < studentList.count; i++) {
		if (studentList.students[i].id == id) {
			searchedStudent = studentList.students[i];
		}
	}
	return searchedStudent;
}
record getPassers(record studentList) {
	int i;
	record passers;
	passers.count = 0;
	for (i = 0; i < studentList.count; i++) {
		if (studentList.students[i].averageGrade >= 80) {
			passers.students[passers.count] = studentList.students[i];
			passers.count++;
		}
	}
	return passers;
}

void calculateAverage(record *studentList) {
	int i,j;
	for (i = 0; i < studentList->count; i++) {
		int sum = 0;
		for (j = 0; j < 5; j++) {
			sum += studentList->students[i].grades[j];
		}
		int average = sum / 5;
		studentList->students[i].averageGrade = average;
	}
}

void displayRecord(record record) {
	int i;
	for (i = 0; i < record.count; i++) {
		printf("--- Student %d --- \n", i + 1);
		printf("Name: %s\n", record.students[i].personDetails.name);
		printf("ID: %d\n", record.students[i].id);
		printf("Course: %s\n", record.students[i].schoolDetails.course);
		printf("Year Level: %d\n", record.students[i].schoolDetails.yearLevel);
		printf("Average Grade: %d\n", record.students[i].averageGrade);
		
	}
}
