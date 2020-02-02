#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include <string>
#include "student.h"

class securityStudent : public Student {
public:
	virtual Degree getDegreeProgram();

private:
	Degree degreeType = SECURITY;
};

#endif#pragma once
