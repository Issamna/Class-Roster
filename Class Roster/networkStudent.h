#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
#include <string>
#include "student.h"

class networkStudent : public Student {
public:
	virtual Degree getDegreeProgram();

private:
	Degree degreeType = NETWORKING;
};

#endif