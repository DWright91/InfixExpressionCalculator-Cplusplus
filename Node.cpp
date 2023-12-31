// Dalton Wright
// CSCI 301 01
// Project #5
// Node.cpp

#include "Node.h"
#include <cstddef>

////////////////////////////////////////////////////////////////////////////////
//                         Default Constructor
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
Node<ItemType>::Node() : next(NULL)
{
} // End default constructor.

////////////////////////////////////////////////////////////////////////////////
//                            Constructor
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(NULL)
{
} // End constructor.

////////////////////////////////////////////////////////////////////////////////
//                            Constructor
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
} // End constructor.

////////////////////////////////////////////////////////////////////////////////
//                          Function setItem
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
} // End setItem.

////////////////////////////////////////////////////////////////////////////////
//                           Function setNext
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
  next = nextNodePtr;
} // End setNext.

////////////////////////////////////////////////////////////////////////////////
//                           Function getItem
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
  return item;
} // End getItem.

////////////////////////////////////////////////////////////////////////////////
//                            Function getNext
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
  return next;
} // End getNext.
