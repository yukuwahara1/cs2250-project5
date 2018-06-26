//============================================================================
// Name        : Complex.cpp
// Author      : Yu Kuwahara
//============================================================================

#include "Complex.h"

//===========CONSTRUCTOR DEFINITIONS==========================================

// proviode three constructors
// constructor #1
Complex::Complex()
{
	// initialize the values of a and b
	_a = 0;
	_b = 0;
}

// constructor #2
Complex::Complex(double a)
{
	// give a number with a
	// set b = 0
	_a = a;
	_b = 0;
}

// constructor #3
Complex::Complex(double a, double b)
{
	// set both values
	_a = a;
	_b = b;
}

// constructor #4
// need to store the array of the complex number as string
Complex::Complex(double a, double b, string s)
{
	// set all the values
	_a = a;
	_b = b;
	_strVal = s;
}

//===========METHOD DEFINITIONS=================================================

// getter for the real part
double Complex::getRealPart()
{
	return _a;
}

// getter for the imaginary part
double Complex::getImaginaryPart()
{
	return _b;
}

// setter for the complex number as string
void Complex::setString(string s)
{
	_strVal = s;
}

// getter for the complex number as string
string Complex::getString()
{
	return _strVal;
}

// display the entire array as string
void Complex::displayString()
{
	cout << _strVal << "\n";
}

//================= OPERATOR OVERLOAD DEFINITIONS (BINARY)=====================

// addition, +
Complex Complex::operator + (const Complex &number)
{
	Complex add;

	add._a = _a + number._a;
	add._b = _b + number._b;
	
	return add;
}

// subtraction, -
Complex Complex::operator - (const Complex &number)
{
	Complex subtract;

	subtract._a = _a - number._a;
	subtract._b = _b - number._b;
	
	return subtract;
}

// multiplication, *
Complex Complex::operator * (const Complex &number)
{
	Complex multiplyFirst;
	Complex multiplySecond;
	Complex multiply;

	multiplyFirst._a = _a * number._a;
	multiplyFirst._b = _b * number._b;
	multiplySecond._a = _b * number._a;
	multiplySecond._b = _a * number._b;
	multiply._a = multiplyFirst._a - multiplyFirst._b;
	multiply._b = multiplySecond._a + multiplySecond._b;
	
	return multiply;
}

// 
Complex Complex::operator / (const Complex &number)
{
	Complex divide;

	divide._a = ((_a * number._a) + (_b * number._b)) / ((number._a)*(number._a) + (number._b)*(number._b));
	divide._b = ((_b * number._a) - (_a * number._b)) / ((number._a)*(number._a) + (number._b)*(number._b));
	
	return divide;
}

//================= OPERATOR OVERLOAD DEFINITIONS (UNARY)=====================

// ++prefix
Complex& operator ++ (Complex &number)
{
	++number._a;
	return number;
}

// suffix++
Complex& operator ++ (Complex &number, int)
{
	Complex first(number._a, number._b);
	number._a++;
	return number;
}

// --prefix
Complex& operator -- (Complex &number)
{
	number._a--;
	return number;
}

// sufffix--
Complex& operator -- (Complex &number, int)
{
	Complex first(number._a, number._b);
	number._a--;
	return number;
}
