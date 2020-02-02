#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;


class Student {
public:
	//constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int inDaysToComplete[3], Degree degreeType);
	//deconstructor
	~Student();
	//accessor methods
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysToComplete();
	Degree getDegreeType();
	//mutator methods
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(int inDaysToComplete[3]);
	void setDegreeType(Degree degreeType);
	//other required methods
	virtual void print();
	virtual Degree getDegreeProgram();

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	Degree degreeType;
};



#endif