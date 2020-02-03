/*
C867 Performance Assessment
Issam Ahmed
000846138
2/2/2020
*/

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
#include <string>
#include "student.h"

class networkStudent : public Student {
public:
	using Student::Student;
	Degree getDegreeProgram();
	void print();
private:
	Degree degreeType = NETWORKING;
};

#endif
