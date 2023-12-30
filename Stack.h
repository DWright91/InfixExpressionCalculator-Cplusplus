// Dalton Wright
// CSCI 301 01
// Project #5
// Stack.h

#ifndef Stack_h
#define Stack_h

#include "StackInterface.h"
#include "PrecondViolatedExcep.h"
#include "Node.h"

template<class ItemType>
class Stack: public StackInterface<ItemType>
{
  private:
    Node<ItemType>* topPtr;

  public:
    Stack();
    Stack(const Stack<ItemType>& aStack);
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const throw(PrecondViolatedExcep);
};

#include "Stack.cpp"
#endif // End Stack.h
