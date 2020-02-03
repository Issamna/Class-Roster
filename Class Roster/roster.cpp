/*
C867 Performance Assessment
Issam Ahmed
000846138
2/2/2020
*/
#include <iostream>
#include <sstream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
	//introduction
	cout << "C867 - Scripting and Programming - Applications\n";
	cout << "Programing Language: C++\n";
	cout << "000846138\n";
	cout << "Issam Ahmed\n";
	cout << "---------------------\n";
	cout << "Class Roster Program \n";
	cout << "---------------------\n";

	//create instance
	Roster classRoster;
	
	//studentData Array
	const string studentData[] = 
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Issam,Ahmed,iahme11@wgu.edu,31,31,29,30,SOFTWARE"};
	
	//load data into instance
	for (int i = 0; i < 5; i++) {
		//change string input into usable string array
		stringstream ss(studentData[i]);
		string temp[9];
		for (int j = 0; j < 9; j++) {
			string tempString;
			getline(ss, tempString, ',');
			temp[j] = tempString;
		}
		Degree tempDegree;
		if (temp[8] == "SECURITY") {
			tempDegree = SECURITY;
		}
		else if (temp[8] == "NETWORK") {
			tempDegree = NETWORKING;
		}
		else if (temp[8] == "SOFTWARE") {
			tempDegree = SOFTWARE;
		}
		//add to instance
		classRoster.add(temp[0], temp[1], temp[2], temp[3], stoi(temp[4]), stoi(temp[5]), stoi(temp[6]), stoi(temp[7]), tempDegree);
	}
	//Print all
	classRoster.printAll();
	//invalid emails
	classRoster.printInvalidEmails();
	//all Average days
	cout << "\nAverage Days in Course\n";
	cout << "----------------------\n";
	for (int i = 0; i < 5; i++) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	//print by degree
	cout << "\nPrint By Degree - Software\n";
	cout << "----------------------\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	//remove A3 twice
	cout << "\nRemove A3\n";
	classRoster.remove("A3");
	cout << "\nRemove A3 again\n";
	classRoster.remove("A3");

	cout << "\n\n";
	return 0;
}

//add to instance array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
	//check if array full
	if (indexCounter > 4) {
		cout << "classRosterArray is full\n";
	}
	else {
		int inDaysToComplete[3] = { daysInCourse1 , daysInCourse2, daysInCourse3 };
		if (degreeType == SECURITY) {
			classRosterArray[indexCounter] = new securityStudent(studentID, firstName, lastName, emailAddress, age, inDaysToComplete);
			indexCounter++;
		}
		else if (degreeType == NETWORKING) {
			classRosterArray[indexCounter] = new networkStudent(studentID, firstName, lastName, emailAddress, age, inDaysToComplete);
			indexCounter++;
		}
		else if (degreeType == SOFTWARE) {
			classRosterArray[indexCounter] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, inDaysToComplete);
			indexCounter++;
		}
		else {
			cout << "Degree type not registered yet";
		}
	}
};

//remove from instance array
void Roster::remove(string studentID) {
	bool idExist = false; 
	//check if exist
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->getStudentID()) {
			//print if exist
			idExist = true;
			classRosterArray[i] = NULL;
		}
	}
	if (!idExist) {
		cout << "Student ID was not found.";
	}
}

//print all of instance data
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) { //check if for deleted instance
			classRosterArray[i]->print();
		}
	}
}

//print average days in a course
void Roster::printDaysInCourse(string studentID) {
	bool idExist = false;
	double total = 0;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL && studentID == classRosterArray[i]->getStudentID()) { 
			for (int j = 0; j < 3; j++) {
				total = total + classRosterArray[i]->getDaysToComplete()[j];
			}
			cout << studentID << " average days in class: " << (total / 3) << " days\n";
			idExist = true;
		}
	}
	if (!idExist) {
		cout << "Student ID was not found.";
	}
}

//print any invalid emails according to rubic
void Roster::printInvalidEmails() {
	cout << "\nInvalid Emails\n";
	cout << "--------------\n";
	for (int i = 0; i < 5; i++) {
		bool valid = false;
		string curEmail = classRosterArray[i]->getEmailAddress();
		if (curEmail.find(" ") == string::npos) {
			if (curEmail.find("@") != string::npos) {
				if (curEmail.find(".") != string::npos) {
					valid = true;
				}
			}
		}
		if (!valid) {
			cout << classRosterArray[i]->getStudentID() << " email " << curEmail << " is invalid.\n";
		}
	}
}

//print by degree choice
void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->print();
		}
	}
}

//deconstructor
Roster::~Roster() {
	cout << "Roster deconstructor called";
}

