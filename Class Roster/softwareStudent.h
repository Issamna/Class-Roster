#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
#include <string>
#include "student.h"

class softwareStudent : public Student {
public:
	using Student::Student;
	Degree getDegreeProgram();
	void print();

private:
	Degree degreeType = SOFTWARE;
};

#endif
