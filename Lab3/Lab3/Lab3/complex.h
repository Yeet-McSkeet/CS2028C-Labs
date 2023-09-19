#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
class complex
{
private:
	double real_;		// numbers have a real and complex component
	double complex_;

public:

	// Constructors
	complex();
	complex(double real, double comp);
	
	// Operator Overloads
	complex operator + (complex& number);
	complex operator - (complex& number);
	complex operator * (complex& number);	// 2 complex
	complex operator * (double& number);	// scalar
	complex operator / (complex& number);	// 2 complex
	complex operator / (double& number);	// scalar
	bool operator == (complex& number);
	friend std::ostream& operator << (std::ostream& out, complex& number);

	// Methods
	double getReal();
	double getComplex();
};

#endif