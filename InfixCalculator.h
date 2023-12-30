// Dalton Wright
// CSCI 301 01
// Project #5
// InfixCalculator.h

#ifndef InfixCalculator_h
#define InfixCalculator_h

#include <string>
#include "Stack.h"
using namespace std;

class InfixCalculator
{
  private:
    string postfix; // To hold the postfix expression.
    int convertToInteger(const char& aChar);
    bool checkIfValid(const string& infix);

  public:
    InfixCalculator();
    InfixCalculator(const string& infixExpression);
    bool convertToPostfix(const string& infix);
    int calculate() throw(std::logic_error);
};

#include "InfixCalculator.cpp"
#endif // End InfixCalculator.h
