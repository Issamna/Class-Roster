/*
C867 Performance Assessment
Issam Ahmed
000846138
2/2/2020
*/
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class securityStudent : public Student {
public:
	using Student::Student;
	Degree getDegreeProgram();
	void print();

private:
	Degree degreeType = SECURITY;
};

#endif
