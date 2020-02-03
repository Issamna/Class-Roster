/*
C867 Performance Assessment
Issam Ahmed
000846138
2/2/2020
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;


class Student {
public:
	//constructor
	Student(string, string, string, string, int, int*);
	//deconstructor
	~Student();
	//accessor methods
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysToComplete();
	//mutator methods
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(int inDaysToComplete[3]);
	//other required methods
	virtual void print();
	virtual Degree getDegreeProgram() = 0;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
};



#endif