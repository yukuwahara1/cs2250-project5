//============================================================================
// Name        : Complex.h
// Author      : Yu Kuwahara
//============================================================================

#pragma once // instead of "#ifndef" & "#define" at the beginning, & "#endif" at the end
#include <iostream>
#include <string>
using namespace std;

// create a class, Complex
class Complex
{

// all the data are recommended to be stored as private
// because they provide encapsulation, a language mechanism for restricting direct access to some of the object's components
private:

	double _a;
	double _b;
	string _strVal;

public:

// in this project all the memebr functions need to be in public
// make setter and getter appropriately

	//===================== CONSTRUCTORS ==============================

	// constructor #1
	Complex();

	// constructor #2
	Complex(double);

	// constructor #3
	Complex(double, double);

	// constructor 4
	Complex(double, double, string);

	//============ CLASS METHODS ======================================

	// getter for the real part
	double getRealPart();

	// getter for the imaginary part
	double getImaginaryPart();

	// setter for the complex number as string
	void setString(string);

	// method that returns the string representation of the number
	// getter for the complex number as string
	string getString();

	// to be used for displaying the array of the complex number as string purposes later
	void displayString();

	//============= BINARY OPERATOR OVERLOADS ==========================

	// add
	Complex operator + (const Complex &number);

	// subtract
	Complex operator - (const Complex &number);

	// multiply
	Complex operator * (const Complex &number);

	// devide
	Complex operator / (const Complex &number);

	//============= UNARY OPERATOR OVERLOADS =========================
	// THIS TIME ONLY "FRIEND" WORKED TO OVERLOAD UNARY OPERATIONS AFTER TRYING EXAMPLES ON THE INTERNET
	// NOT SURE SO NEED TO CHECK THE REASONS

	// increment as ++prefix
	friend Complex& operator ++ (Complex &number);

	// increment as suffix++
	friend Complex& operator ++ (Complex &number, int);

	// increment as --prefix
	friend Complex& operator -- (Complex &number);

	// increment as suffix--
	friend Complex& operator -- (Complex &number, int);
};
