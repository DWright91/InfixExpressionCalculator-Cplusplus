// Dalton Wright
// CSCI 301 01
// Project #5
// InfixCalculator.cpp

#include <iostream>
#include "InfixCalculator.h"
////////////////////////////////////////////////////////////////////////////////
//                           Default Constructor
////////////////////////////////////////////////////////////////////////////////
InfixCalculator::InfixCalculator() : postfix("")
{
}

////////////////////////////////////////////////////////////////////////////////
//                             Constructor
////////////////////////////////////////////////////////////////////////////////
InfixCalculator::InfixCalculator(const string& infixExpression) : postfix("")
{
  convertToPostfix(infixExpression);
}

////////////////////////////////////////////////////////////////////////////////
//                         Function convertToPostfix
////////////////////////////////////////////////////////////////////////////////
bool InfixCalculator::convertToPostfix(const string& expression)
{
  int length = expression.length();
  Stack<char> aStack;
  int isBalanced = 1;

  if(!checkIfValid(expression))
  {
    throw(PrecondViolatedExcep("The expression entered is invalid."));
  }

  for(int i = 0; i < length; i++)
  {
    if(expression[i] < 58 && expression[i] > 47)
    {
      postfix = postfix + expression[i];
    }
    else if(expression[i] == '(')
    {
      aStack.push(expression[i]);
      isBalanced -= 1;
    }
    else if(expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-')
    {
      int inputLevel;
      int stackLevel;
      bool precedence = false;

      while(!aStack.isEmpty() && aStack.peek() != '(' && !precedence)
      {
        if(expression[i] == '+' || expression [i] == '-')
        {
          inputLevel = 0;
        }
        else
        {
          inputLevel = 1;
        }

        if(aStack.peek() == '+' || aStack.peek() == '-')
        {
          stackLevel = 0;
        }
        else
        {
          stackLevel = 1;
        }

        if(inputLevel > stackLevel)
        {
          precedence = true;
        }

        postfix = postfix + aStack.peek();
        aStack.pop();
      }

      aStack.push(expression[i]);
    }
    else if(expression[i] == ')')
    {
      isBalanced += 1;
      while(aStack.peek() != '(')
      {
        postfix = postfix + aStack.peek();
        aStack.pop();
      }

      aStack.pop();
    }
  }

  while(!aStack.isEmpty())
  {
    postfix = postfix + aStack.peek();
    aStack.pop();
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////
//                          Function calculate
////////////////////////////////////////////////////////////////////////////////
int InfixCalculator::calculate() throw(std::logic_error)
{
  Stack<int> aStack;
  int length = postfix.length();

  for(int i = 0; i < length; i++)
  {
    if(postfix[i] < 58 && postfix[i] > 47)
    {
      aStack.push(convertToInteger(postfix[i]));
    }
    else if(postfix[i] == '+')
    {
      int number1 = aStack.peek();
      aStack.pop();

      int number2 = aStack.peek();
      aStack.pop();

      aStack.push(number1 + number2);
    }
    else if(postfix[i] == '-')
    {
      int number1 = aStack.peek();
      aStack.pop();

      int number2 = aStack.peek();
      aStack.pop();

      aStack.push(number2 - number1);
    }
    else if(postfix[i] == '/')
    {
      int number1 = aStack.peek();
      aStack.pop();

      int number2 = aStack.peek();
      aStack.pop();

      if(number1 == 0)
      {
        throw(std::logic_error("Cannot divide by 0."));
      }
      aStack.push(number2 / number1);
    }
    else if(postfix[i] == '*')
    {
      int number1 = aStack.peek();
      aStack.pop();

      int number2 = aStack.peek();
      aStack.pop();

      aStack.push(number1 * number2);
    }
  }

  return aStack.peek();
}

////////////////////////////////////////////////////////////////////////////////
//                        Function convertToInteger
////////////////////////////////////////////////////////////////////////////////
int InfixCalculator::convertToInteger(const char& aChar)
{
  return ((int)aChar - 48);
}

////////////////////////////////////////////////////////////////////////////////
//                           Function checkIfValid
////////////////////////////////////////////////////////////////////////////////
bool InfixCalculator::checkIfValid(const string& infix)
{
  bool isValid = true;
  bool lastWasNumber = false;
  int length = infix.length();
  int parenthesisBalance = 0;
  int inputBalance = 0;


  for(int i = 0; i < length; i++)
  {
    if(infix[i] < 58 && infix[i] > 47 && !lastWasNumber)                        // Less than 9 and greater than 0: ASCII code.
    {
      inputBalance++;
      lastWasNumber = true;
    }
    else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
    {
      inputBalance++;
      lastWasNumber = false;
    }
    else if(infix[i] == '(')
    {
      parenthesisBalance--;
      lastWasNumber = false;
    }
    else if(infix[i] == ')')
    {
      parenthesisBalance++;
      lastWasNumber = false;
    }
    else
    {
      isValid = false;
    }
  }

  inputBalance = inputBalance % 2;  // Checks if numbers-input is even or odd.

  if(inputBalance == 0 || parenthesisBalance != 0)
  {
    isValid = false;
  }

  return isValid;
}
