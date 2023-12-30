// Dalton Wright
// CSCI 301 01
// Project #5
// Stack.cpp
#include "Stack.h"

////////////////////////////////////////////////////////////////////////////////
//                            Default Constructor
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
Stack<ItemType>::Stack() : topPtr(NULL)
{
}


////////////////////////////////////////////////////////////////////////////////
//                               Constructor
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& aStack)
{
  Node<ItemType>* origStack = aStack.topPtr;

  if(origStack == NULL)
  {
    topPtr = NULL;
  }
  else
  {
    topPtr = new Node<ItemType>();
    topPtr-> setItem(origStack->getItem());

    Node<ItemType>* newChainPtr = topPtr;

    origStack = origStack->getNext();

    while(origStack != NULL)
    {
      ItemType nextItem = origStack->getItem();
      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
      newChainPtr->setNext(newNodePtr);
      newChainPtr = newChainPtr->getNext();
      origStack = origStack->getNext();
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                            Function isEmpty
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
  if(topPtr == NULL)                                                            // topPtr == nullptr?
  {
    return true;
  }
  else
  {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////////
//                              Function push
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newEntry)
{
  Node<ItemType>* newPtr = new Node<ItemType>(newEntry, topPtr);
  topPtr = newPtr;
  newPtr = NULL;

  return true;
}

////////////////////////////////////////////////////////////////////////////////
//                              Function pop
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
bool Stack<ItemType>::pop()
{
  if(!isEmpty())
  {
    Node<ItemType>* ptrToDelete = topPtr;
    topPtr = topPtr->getNext();

    ptrToDelete->setNext(NULL);
    delete ptrToDelete;
    ptrToDelete = NULL;                                                         // ptrToDelete = nullptr?

    return true;
  }
  else
  {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////////
//                              Function peek
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(PrecondViolatedExcep)
{
  if(isEmpty())
  {
    throw(PrecondViolatedExcep("Peek() called with empty stack"));
  }

  return topPtr->getItem();
}
