#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
	char fName[50];
	char MI;
	char lName[50];
}name;
 
typedef struct{
	name personName;
	int age;
	float height;
}person;
 
typedef struct{
	person contactPerson;
	int mobileNumber;
	char relationship[50];
 
}emergency;
 
typedef struct{
	int idNum;
	char schoolName[50];
	int yearLvl;
}school;
 
typedef struct{
	person personInfo;
	school schoolInfo;
	emergency emergencyContactInfo;
}info;
 
typedef struct{
	info studentInfo;
}record;
 
int main(){
 	record myRecord;
 	
 	myRecord.studentInfo.schoolInfo.idNum = 21103565;
 	strcpy(myRecord.studentInfo.schoolInfo.schoolName, "University of San Carlos");
 	myRecord.studentInfo.schoolInfo.yearLvl = 1;
 	
 	strcpy(myRecord.studentInfo.emergencyContactInfo.contactPerson.personName.fName, "Neil John");
 	myRecord.studentInfo.emergencyContactInfo.contactPerson.personName.MI = 'C';
 	strcpy(myRecord.studentInfo.emergencyContactInfo.contactPerson.personName.lName, "Yap");
 	
 	myRecord.studentInfo.emergencyContactInfo.contactPerson.age = 49;
 	myRecord.studentInfo.emergencyContactInfo.contactPerson.height = 5.8;
 	
 	myRecord.studentInfo.emergencyContactInfo.mobileNumber = 1234567;
 	strcpy(myRecord.studentInfo.emergencyContactInfo.relationship, "Father");
 	
 	printf("Enter person's first name: ");
 	gets(myRecord.studentInfo.personInfo.personName.fName);
 	
 	printf("Enter person's middle initial: ");
 	scanf(" %c", &myRecord.studentInfo.personInfo.personName.MI);
 	
 	fflush(stdin);
 	printf("Enter person's last name: ");
 	gets(myRecord.studentInfo.personInfo.personName.lName);
 	
 	printf("Enter person's age: ");
 	scanf(" %d", &myRecord.studentInfo.personInfo.age);
 	
 	printf("Enter person's height: ");
 	scanf(" %f", &myRecord.studentInfo.personInfo.height);
 	
 	printf("Displaying Student Record: \n");
 	
 	printf("Complete Name: %s %c. %s\n", myRecord.studentInfo.personInfo.personName.fName, myRecord.studentInfo.personInfo.personName.MI, myRecord.studentInfo.personInfo.personName.lName);
 	printf("Age: %d \t Height: %.2f\n", myRecord.studentInfo.personInfo.age, myRecord.studentInfo.personInfo.height);
 	
 	printf("\nSchool Info: \n");
 	printf("School Name %s\n", myRecord.studentInfo.schoolInfo.schoolName);
 	printf("ID Number: %d\n", myRecord.studentInfo.schoolInfo.idNum);
 	printf("Year Level: %d\n", myRecord.studentInfo.schoolInfo.yearLvl);
 	
 	printf("Emergency contact info: \n");
 	printf("Full Name of Contact: %s %c. %s\n", myRecord.studentInfo.emergencyContactInfo.contactPerson.personName.fName, myRecord.studentInfo.emergencyContactInfo.contactPerson.personName.MI, myRecord.studentInfo.emergencyContactInfo.contactPerson.personName.lName);
 	printf("Relationship: %s\n", myRecord.studentInfo.emergencyContactInfo.relationship);
 	printf("Age of contact: %d \t Height of Contact: %.2f\n", myRecord.studentInfo.emergencyContactInfo.contactPerson.age, myRecord.studentInfo.emergencyContactInfo.contactPerson.height);
 	printf("Contact Number: %d", myRecord.studentInfo.emergencyContactInfo.mobileNumber);
 	
}
