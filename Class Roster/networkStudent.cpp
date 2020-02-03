/*
C867 Performance Assessment
Issam Ahmed
000846138
2/2/2020
*/
#include <iostream>
#include <string>
#include "networkStudent.h"
using namespace std;

//accessor method
Degree networkStudent::getDegreeProgram() {
	return degreeType;
}

//print method
void networkStudent::print() {
	cout << getStudentID() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t\t";
	cout << "daysInCourse: {" << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}" << "\t";
	cout << "Degree Type: NETWORKING" << endl;
}
