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
 	
 	person myPersonInfo;
 	school mySchool;
 	emergency myEmergency;
 	
 	// school info
 	mySchool.idNum = 21103565;
 	strcpy(mySchool.schoolName, "University of San Carlos");
 	mySchool.yearLvl = 1;
 	
 	// emergency contact info
 	strcpy(myEmergency.contactPerson.personName.fName, "Neil John");
 	myEmergency.contactPerson.personName.MI = 'C';
 	strcpy(myEmergency.contactPerson.personName.lName, "Yap");
 	myEmergency.contactPerson.age = 49;
 	myEmergency.contactPerson.height = 5.8;
 	myEmergency.mobileNumber = 101202303;
 	strcpy(myEmergency.relationship, "Father");
 	
 	// student info
 	printf("Enter person's first name: ");
 	gets(myPersonInfo.personName.fName);
 	printf("Enter person's middle initial: ");
 	scanf(" %c", &myPersonInfo.personName.MI);
 	fflush(stdin);
 	printf("Enter person's last name: ");
 	gets(myPersonInfo.personName.lName);
 	printf("Enter person's age: ");
 	scanf(" %d", &myPersonInfo.age);
 	printf("Enter person's height: ");
 	scanf(" %f", &myPersonInfo.height);
 	
 	info myInfo = {myPersonInfo, mySchool, myEmergency};
 	record myRecord = {myInfo};
 	
 	// display student record
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
