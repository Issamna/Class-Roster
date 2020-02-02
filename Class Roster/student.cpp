#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//contstuctor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int inDaysToComplete[3], Degree degreeType) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = inDaysToComplete[i];
	}
	this->degreeType = degreeType;
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

Degree Student::getDegreeType() {
	return degreeType;
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

void Student::setDegreeType(Degree degreeType) {
	this->degreeType = degreeType;
}

void Student::print() {


	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t";
	cout << getEmailAddress() << "\t";
	cout << getAge() << "\t";
	cout << daysToComplete[0] << " " << daysToComplete[1] << " " << daysToComplete[2] << " " << "\t";
	cout << getDegreeType() << "\t";
}

Degree Student::getDegreeProgram() {
	return degreeType;
}
/*
int main() {
	int test[3] = { 1,2,3 };
	Student t1("A1", "John", "Smith", "John1989@gm ail.com", 22, test, SECURITY);
	return 0;
}
*/