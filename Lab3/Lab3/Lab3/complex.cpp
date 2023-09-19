#include "complex.h"
// Constructors
complex::complex() {
	real_ = 0;
	complex_ = 0;
}

complex::complex(double real, double comp) {
	real_ = real;
	complex_ = comp;
}


// Operator overloads
complex complex::operator + (complex& number)
{
	complex result;
	result.real_ = this->real_ + number.real_;
	result.complex_ = this->complex_ + number.complex_;
	return result;
}

complex complex::operator - (complex& number)
{
	complex result;
	result.real_ = this->real_ - number.real_;
	result.complex_ = this->complex_ - number.complex_;
	return result;
}

complex complex::operator * (complex& number)	// Complex multiplication
{
	complex result;
	result.real_ = (this->real_ * number.real_) - (this->complex_ * number.complex_);
	result.complex_ = (this->real_ * number.complex_) + (this->complex_ * number.real_);
	return result;
}

complex complex::operator * (double& number)	// scalar multiplication
{
	complex result;
	result.real_ = (this->real_ * number);
	result.complex_ = (this->complex_ * number);
	return result;
}

complex complex::operator / (complex& number)	// Complex division
{
	complex result;
	result.real_ = ((this->real_ * number.real_) + (this->complex_ * number.complex_)) / ((number.real_ * number.real_) + (number.complex_ * number.complex_));
	result.complex_ = ((this->complex_ * number.real_) - (this->real_ * number.complex_)) / ((number.real_ * number.real_) + (number.complex_ * number.complex_));
	return result;
}

complex complex::operator / (double& number)	// scalar division
{
	complex result;
	result.real_ = (this->real_ / number);
	result.complex_ = (this->complex_ / number);
	return result;
}

bool complex::operator == (complex& number)
{
	return this->real_ == number.real_ && this->complex_ == number.complex_;
}


// Methods
double complex::getReal()
{
	return this->real_;
}

double complex::getComplex()
{
	return this->complex_;
}
