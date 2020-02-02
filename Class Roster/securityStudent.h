#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class securityStudent : public Student {
public:
	using Student::Student;
	virtual Degree getDegreeProgram();
	
	

private:
	Degree degreeType = SECURITY;
};

#endif
