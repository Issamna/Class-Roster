
#include <iostream>
#include <string>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

class Roster {
public:
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	//void printByDegreeProgram(int degreeProgram);
	//void printInvalidEmails();
	//
	//~Roster();
	int indexCounter = 0;
	Student* classRosterArray[5];
};
