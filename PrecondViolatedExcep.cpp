// Dalton Wright
// CSCI 301 01
// Project #5
// PrecondViolatedExcep.cpp

#include "PrecondViolatedExcep.h"

////////////////////////////////////////////////////////////////////////////////
//                      Function PrecondViolatedExcep
////////////////////////////////////////////////////////////////////////////////
PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception: " + message)
{
}  // End constructor.

// End PrecondViolatedExcep.cpp
