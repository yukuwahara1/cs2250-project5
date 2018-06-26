//============================================================================
// Name        : KuwaharaYuP5.cpp
// Author      : Yu Kuwahara
//============================================================================

#include "Complex.h" // this header file contains all the directives
#include <vector> // store the number of complex numbers in a vector

//=============NAMESPACE DEFINITIONS============================================

// need this for displaying the array of the complex number as string
// THIS WAS THE ONLY WAY WORKED AFTER TRYING MANY SOLUTIONS ON THE INTERNET

namespace util // use namespace and template to add the ability to erase trailing "0"s and "."s
{
	template <typename T> std::string to_string(const T& t)
	{
		std::string stringValue{ std::to_string(t) }; int offset{ 1 };

		// from the end of numbers when converting to string with to_string()
		if (stringValue.find_last_not_of('0') == stringValue.find('.'))
		{
			offset = 0;
		}

		// erase trailing "0"s and "."s
		stringValue.erase(stringValue.find_last_not_of('0') + offset, std::string::npos);

		return stringValue;
	}
}

//=============FUNCTION PROTOTYPES============================================

void appendString(vector<Complex> &, const int); // display the vector as string
void operateUnary(vector<Complex> &, const int, int &); // unary operation
void operateBinary(vector<Complex> &, int, int &); // binary operation

//=======MAIN=================================================================

int main()
{

	int compSize = 0; // declare a vairiable for the number of complex numbers the user wishes to use
	double a = 0; // use "double" instead of "int" in case the final answer has a decimal
	double b = 0; // a and b were passed as _a and _b in Complex.cpp
	int choice; // choice for the menu 1
	int option; // choice for the menu 2
	char decision; // choice for continuing the program or not
	bool continueProgram = true; // flag for the two cases, continue the program or not
	string s; // declare a string variable to display the vector

	// create an empty array to store the numbers the user entered
	vector <Complex> compNumber; // the vector type is the class, Complex

	cout << "Welcome to the complex number calculator! \n\n";

	// prompt the user for the number of complex numbers
	cout << "How many complex numbers would you like to work with?: ";
	cin >> compSize;

	// store the values of both a and b in the empty vector
	for (int i = 0; i < compSize; i++)
	{
		// prompt the user for the values of a
		cout << "What values would you like for a #" << i + 1 << ": ";
		cin >> a;

		// promp the user for the values of b
		cout << "What values would you like for b #" << i + 1 << ": ";
		cin >> b;

		// s stores "a + bi"
		s = util::to_string(a) + " + " + util::to_string(b) + "i";

		// fill up the empty array with the values
		compNumber.push_back(Complex(a, b, s));
	}

	//=====================MENU 1===============================================

	// use while loop to display the menu until the user chose to stop

	// and then prompt the user for choice
	// but we cannot use switch for all the choices since the user can type however much amount of complex numbers the user wants 
	while (continueProgram == true)
	{
		// display the menu from the complex numbers the user entered
		// This code sets _strVal to the proper format
		// then prints the string representation of the vector which is used as the menu
		appendString(compNumber, compSize);
		cout << "\n";

		// display the complex numbers like, 1) a + bi
		for (int i = 0; i < compSize; i++)
		{
			cout << i + 1 << ") ";
			// call the method in the class to display the menu
			compNumber[i].displayString();
		}

		// add "4) quit" option
		cout << compSize + 1 << ") quit\n" << endl;

		// promt the user to pick up one of the complex numbers or quit from the menu
		cout << "Which complex number would you like to work with?: ";
		cin >> choice;

		// error checking for the choice in number
		// when the user entered smaller than 0 or bigger than the number of vector + 1
		if (choice < 0 || choice >(compSize + 1))
		{
			cout << "You chose an invalid choice!";
			cout << "Please pick the valid choice from the menu!" << endl;
			cin >> choice;
			cin.ignore(); // clear the input buffer in the event of the invalid input
		}
		// when the user chose to 4) quit
		else if (choice == compSize + 1)
		{
			cout << "Thank you for using the complex number calculator!" << endl;
			cin.get(); // avoid exiting the whole window and keep the menu above shown
			exit(1); // stop showing the menu 
		}

		//=====================MENU 2===============================================

		cout << "\n";

		// after the user picked one complex number,
		// prompt the user if he wants unary or binary operation

		// display the menu
		cout << "1) unary \n";
		cout << "2) binary \n" << endl;
		cout << "What kind of operation would you like to use?: ";
		cin >> option;

		switch (option)
		{
		case 1: // when the user chose 1) unary, call the function
				operateUnary(compNumber, compSize, choice);
				continueProgram = false;
				break; 

		case 2: // when the user chose 2) binary, call the function
				operateBinary(compNumber, compSize, choice);
				continueProgram = false;
				break;

		default: // show the error message
				cout << "Please enter a valid choice! \n";
				cin >> choice;
				cin.ignore(); // clear the input buffer in the event of the invalid input

		}

		while (continueProgram == false)
		{
			cout << "\n";

			// ask the user if he wants to continue the program
			cout << "Would you like to continue (y / n)?: ";
			cin >> decision;

			// if the user chose yes,
			if (decision == 'y')
			{
				// continue the program
				continueProgram = true;
			}

			// if the user chose no,
			else if (decision == 'n')
			{
				// stop the program
				cout << "Thank you for choosing us! Please come back!" << endl;
				continueProgram = false;
			}

			// display an error message
			else
			{
				cout << "Please enter a valid choice!" << endl;
				cin >> decision;
				cin.ignore(); // clear the input buffer in the event of the invalid input
			}
		}
	}

	return 0;

}

//===========FUNCTION DEFINITIONS=============================================

// this function stores the string representation of the complex number
void appendString(vector<Complex> &compNumber, const int compSize)
{
	string s; // the whole complex number as string
	string s1; // the real part as string
	string s2; // the imaginary part as string

	for (int i = 0; i < compSize; i++) 
	{
		// store s1 and s2 as string for each set of the complex numbers
		s1 = util::to_string(compNumber[i].getRealPart());
		s2 = util::to_string(compNumber[i].getImaginaryPart());

		// if a and b are both negative
		if (compNumber[i].getImaginaryPart() < 0)
		{
			s2 = util::to_string(compNumber[i].getImaginaryPart()*-1);
			s = s1 + " - " + s2 + "i";
		}
		// if a and b are both positive or only b is positive
		else 
		{
			s = s1 + " + " + s2 + "i";
		}

		// call the setter of the vector as string for each set of the complex numbers
		compNumber[i].setString(s);
	}
}

//===========UNARY FUNCTION=============================================
// this function allows the user for unary operations
void operateUnary(vector<Complex> &compNumber, const int compSize, int &choice)
{
	int unary = 0; // choice for the unary operation menu
	int displayResult = 0; // the location to store the result
	double compFirst = 0; // the first complex number
	double compSecond = 0; // the second complex numebr
	Complex compResult(compFirst, compSecond); // declare a variable data type Complex to store the calculated result

	cout << "\n";

	// display the unary operation menu
	cout << "1) ++prefix\n";
	cout << "2) postfix++\n";
	cout << "3) --prefix\n";
	cout << "4) postfix--\n";
	cout << "5) quit" << endl;

	cout << "\n";

	// prompt the user for the choice of operation
	cout << "Which type of operation would you like to use?: ";
	cin >> unary;								

	// when the user chose to quit
	if (unary == 5) 
	{
		cout << "Thank you for using the complex number calculator!" << endl;
		cin.get(); // avoid exiting the whole window and keep the menu above shown
		exit(1); // stop showing the menu 
	}

	// error checking of the choice
	else if (unary > 5 || unary < 0) 
	{
		cout << "Please enter a valid choice! \n" << endl;
		cin >> unary;
		cin.ignore(); // clear the input buffer in the event of the invalid input
	}

	switch (unary) 
	{
	case 1: // when the user wants to use ++prefix

			cout << "\n";

			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// increment the real number
			compResult = compNumber[choice - 1] = ++compNumber[choice - 1];

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;

	case 2: // when the user wants to use postfix++

			cout << "\n";
			
			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// increment the real number
			compResult = compNumber[choice- 1] = compNumber[choice - 1]++;

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;

	case 3: // when the user wants to use --prefix

			cout << "\n";

			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// decrement the real number
			compResult = compNumber[choice - 1] = --compNumber[choice - 1];

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;

	case 4: // when the user wants to use postfix--

			cout << "\n";

			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// decrement the real number
			compResult = compNumber[choice - 1] = compNumber[choice - 1]--;

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;

	default: 
			cout << "\n";
			cout << "Please enter a valid choice! \n";
			cin >> choice;
			cin.ignore(); // clear the input buffer in the event of the invalid input
	}
}

//===========BINARY FUNCTION=============================================
// this function allows the user for binary operation
void operateBinary(vector<Complex> &compNumber, int compSize, int &choice)
{
	int binary = 0; // choice for the binary menu
	int nextChoice = 0; // the second complex number
	int displayResult = 0; // the location to store the result
	double compFirst = 0; // the first complex number
	double compSecond = 0; // the second complex numebr
	Complex compResult(compFirst, compSecond); // declare a variable data type Complex to store the calculated result

	cout << "\n";

	// display the binary operation menu
	cout << "1) + \n";
	cout << "2) - \n";
	cout << "3) * \n";
	cout << "4) / \n";
	cout << "5) quit \n";

	cout << "\n";

	// prompt the user for the choice
	cout << "Which type of binary operation would you like to use?: " ;
	cin >> binary;

	cout << "\n";

	// when the user chose to quit
	if (binary == 5)
	{
		cout << "Thank you for using the complex number calculator!" << endl;
		cin.get(); // avoid exiting the whole window and keep the menu above shown
		exit(1); // stop showing the menu 
	}

	// error checking of the choice
	else if (binary > 5 || binary < 0)
	{
		cout << "Please enter a valid choice! \n" << endl;
		cin >> binary;
		cin.ignore(); // clear the input buffer in the event of the invalid input
	}

	switch (binary) 
	{
	case 1: // when the user chose to add two complex numbers

			// display a menu to choose the second complex number or "quit"
			for (int i = 0; i < compSize; i++)
			{
				cout << i + 1 << ") ";
				compNumber[i].displayString();
			}

			// add "4) quit" option
			cout << compSize + 1 << ") quit\n" << endl;

			cout << "Which complex number would you like to work with next?: ";
			cin >> nextChoice;

			// error checking for the choice in number
			// when the user entered smaller than 0 or bigger than the number of vector + 1
			if (nextChoice <= 0 || nextChoice >(compSize + 1))
			{
				cout << "\n";
				cout << "Please enter a valid choice! \n";
				cin >> nextChoice;
				cin.ignore(); // clear the input buffer in the event of the invalid input
			}
			// when the user chose to 4) quit
			else if (nextChoice == compSize + 1)
			{
				cout << "Thank you for using the complex number calculator!" << endl;
				cin.get(); // avoid exiting the whole window and keep the menu above shown
				exit(1); // stop showing the menu 
			}

			cout << "\n";
			
			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// add the two complex numbers
			compResult = compNumber[choice - 1] + compNumber[nextChoice - 1];

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;

	case 2: // when the user chose to subtract two complex numbers

			// display a menu to choose the second complex number or "quit"
			for (int i = 0; i < compSize; i++)
			{
				cout << i + 1 << ") ";
				compNumber[i].displayString();
			}

			// add "4) quit" option
			cout << compSize + 1 << ") quit\n";

			cout << "\n";

			cout << "Which complex number would you like to work with next?: ";
			cin >> nextChoice;

			// error checking of the choice 
			// when the user entered smaller than 0 or bigger than the number of vector + 1
			if (nextChoice <= 0 || nextChoice >(compSize + 1))
			{
				cout << "\n";
				cout << "Please enter a valid choice! \n";
				cin >> nextChoice;
				cin.ignore(); // clear the input buffer in the event of the invalid input
			}
			// when the user chose to 4) quit
			else if (nextChoice == compSize + 1)
			{
				cout << "Thank you for using the complex number calculator!" << endl;
				cin.get(); // avoid exiting the whole window and keep the menu above shown
				exit(1); // stop showing the menu 
			}

			cout << "\n";

			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// subtract the two complex numbers
			compResult = compNumber[choice - 1] - compNumber[nextChoice - 1];

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;
		
	case 3: // when the user chose to multiply two complex numbers
			
			// display a menu to choose the second complex number or "quit"
			for (int i = 0; i < compSize; i++)
			{
				cout << i + 1 << ") ";
				compNumber[i].displayString();
			}
	
			// add "4) quit" option
			cout << compSize + 1 << ") quit\n" << endl;

			cout << "Which complex number would you like to work with next?: ";
			cin >> nextChoice;

			// error checking for the choice
			// when the user entered smaller than 0 or bigger than the number of vector + 1
			if (nextChoice <= 0 || nextChoice >(compSize + 1))
			{
				cout << "\n";
				cout << "Please enter a valid choice! \n";
				cin >> nextChoice;
				cin.ignore(); // clear the input buffer in the event of the invalid input
			}
			// when the user chose to 4) quit
			else if (nextChoice == compSize + 1)
			{
				cout << "Thank you for using the complex number calculator!" << endl;
				cin.get(); // avoid exiting the whole window and keep the menu above shown
				exit(1); // stop showing the menu 
			}

			cout << "\n";

			// prompt the user for the location of the result
			cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
			cin >> displayResult;

			// multiply the two complex numbers
			compResult = compNumber[choice - 1] * compNumber[nextChoice - 1];

			// store the result to where the user decided
			compNumber[displayResult - 1] = compResult;

			break;

		case 4: // when the user chose to devide two complex numbers

				// display a menu to choose the second complex number or "quit"
				for (int i = 0; i < compSize; i++)
				{
					cout << i + 1 << ") ";
					compNumber[i].displayString();
				}

				// add "4) quit" option
				cout << compSize + 1 << ") quit\n" << endl;

				cout << "Which complex number would you like to work with next?: ";
				cin >> nextChoice;

				// error checking of the choice
				// when the user entered smaller than 0 or bigger than the number of vector + 1
				if (nextChoice <= 0 || nextChoice >(compSize + 1))
				{
					cout << "\n";
					cout << "Please enter a valid choice! \n";
					cin >> nextChoice;
					cin.ignore(); // clear the input buffer in the event of the invalid input
				}
				// when the user chose to 4) quit
				else if (nextChoice == compSize + 1)
				{
					cout << "Thank you for using the complex number calculator!" << endl;
					cin.get(); // avoid exiting the whole window and keep the menu above shown
					exit(1); // stop showing the menu 
				}

				if (compNumber[nextChoice - 1].getRealPart() == 0 && compNumber[nextChoice - 1].getImaginaryPart() == 0)
				{
					cout << "You cannot divide anything by zero!";
					cin.get(); // avoid exiting the whole window and keep the menu above shown
					exit(1); // stop showing the menu 
				}

				cout << "\n";

				// prompt the user for the location of the result
				cout << "Where would you like to store the result from 1) to " << compSize << ") ?: ";
				cin >> displayResult;

				// devide the two complex numbers
				compResult = compNumber[choice - 1] / compNumber[nextChoice - 1];

				// store the result to where the user decided
				compNumber[displayResult - 1] = compResult;

				break;

		default: 
				cout << "Please enter a valid choice! \n";
				cin >> choice;
				cin.ignore(); // clear the input buffer in the event of the invalid input
	}
}