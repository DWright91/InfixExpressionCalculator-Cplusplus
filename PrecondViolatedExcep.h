// Dalton Wright
// CSCI 301 01
// Project #5
// PrecondViolated.h


#ifndef _PRECOND_VIOLATED_EXCEPT
#define _PRECOND_VIOLATED_EXCEPT

#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error
{
  public:
    PrecondViolatedExcep(const string& message = "");
}; // End class PrecondViolatedExcep.

#include "PrecondViolatedExcep.cpp"
#endif // End PrecondViolatedExcep.h
