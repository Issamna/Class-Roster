/*
C867 Performance Assessment
Issam Ahmed
000846138
2/2/2020
*/
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//contstuctor

Student::Student(string inStudentID, string inFirstName, string inLastName, string inEmailAddress, int inAge, int inDaysToComplete[3]) {
	studentID = inStudentID;
	firstName = inFirstName;
	lastName = inLastName;
	emailAddress = inEmailAddress;
	age = inAge;
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = inDaysToComplete[i];
	}
}

//deconstructor
Student::~Student() {
	//cout << "Student destructor is called" << endl;
}

//accessor methods
string Student::getStudentID() const {
	return studentID;
}

string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

string Student::getEmailAddress() const {
	return emailAddress;
}

int Student::getAge() const {
	return age;
}

int* Student::getDaysToComplete() {
	return daysToComplete;
}


//mutator methods
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToComplete(int inDaysToComplete[3]) {
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = inDaysToComplete[i];
	}
}

//print method
void Student::print() {
	cout << getStudentID() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {" << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}" << "\t";
}

