
#include <iostream>
//#include <sstream>
#include "roster.h"
using namespace std;

int main() {
	//cout << "Class Roster Program \n ";
	


	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Issam,Ahmed,iahme11@wgu.edu,31,31,29,30,SOFTWARE"};
	Roster test;
	
	test.add("test1", "test", "test", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
	test.add("test2", "test", "test", "John1989@gm ail.com", 20, 50, 50, 50, SOFTWARE);
	test.add("test3", "test", "test", "John1989@gm ail.com", 20, 30, 35, 40, SOFTWARE);
	test.add("test4", "test", "test", "John1989@gm ail.com", 20, 30, 35, 40, NETWORKING);
	test.add("test5", "test", "test", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
	
	


	test.printByDegreeProgram(2);
	

	return 0;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
	int inDaysToComplete[3] = { daysInCourse1 , daysInCourse2, daysInCourse3};
	if (degreeType == SECURITY) {
		classRosterArray[indexCounter] = new securityStudent(studentID, firstName, lastName, emailAddress, age, inDaysToComplete, degreeType);
		indexCounter++;
	}
	else if (degreeType == NETWORKING) {
		classRosterArray[indexCounter] = new networkStudent(studentID, firstName, lastName, emailAddress, age, inDaysToComplete, degreeType);
		indexCounter++;
	}
	else if (degreeType == SOFTWARE) {
		classRosterArray[indexCounter] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, inDaysToComplete, degreeType);
		indexCounter++;
	}
	else {
		cout << "Degree type not registered yet";
	}
};

void Roster::remove(string studentID) {
	bool idExist = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->getStudentID()) {
			idExist = true;
			classRosterArray[i] = NULL;
		}
	}
	if (!idExist) {
		cout << "Student ID was not found.";
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->print();
		}
		
	}
}

void Roster::printDaysInCourse(string studentID) {
	bool idExist = false;
	double total = 0.0;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->getStudentID()) {
			for (int j = 0; j < 3; j++) {
				total = total + classRosterArray[i]->getDaysToComplete()[j];
			}
			cout << studentID << " average days in class: " << (total / 3) << " days";
			idExist = true;
		}
	}
	if (!idExist) {
		cout << "Student ID was not found.";
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		bool valid = true;
		string curEmail = classRosterArray[i]->getEmailAddress();


	}
}

void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (degreeProgram == classRosterArray[i]->getDegreeType()) {
			classRosterArray[i]->print();
		}
	}
}


