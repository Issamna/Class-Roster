#pragma once
#ifndef SOFTARESTUDENT_H
#define SOFTARESTUDENT_H

#include <iostream>
#include <string>
#include "student.h"

class softwareStudent : public Student {
public:
	using Student::Student;
	virtual Degree getDegreeProgram();

private:
	Degree degreeType = SOFTWARE;
};

#endif
