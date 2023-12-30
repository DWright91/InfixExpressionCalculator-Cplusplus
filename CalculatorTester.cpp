// Dalton Wright
// CSCI 301 01
// Project #5
// CalculatorTester.cpp

#include "InfixCalculator.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  char choice;             // To hold choice.

  // Do-while loop to let the user choose when to exit program.
  do
  {
    try
    {
      string expression;   // To hold string expression.

      cout << "This program tests an infix calculator, by evaluating single digit operations." << endl;
      cout << "Spaces are not allowed within the expression." << endl;
      cout << "Please enter an expression: ";
      cin >> expression;

      InfixCalculator theCalculator(expression);

      cout << "Expression result: " << theCalculator.calculate() << endl;
    }
    catch(PrecondViolatedExcep e)
    {
      cout << e.what() << endl;
    }
    catch(logic_error e)
    {
      cout << e.what() << endl;
    }

    cout << "To continue calculating please enter (Y/N): ";
    cin >> choice;

  }while(choice == 'Y' && choice != 'N');

  return 1;
}
