// Dalton Wright
// CSCI 301 01
// Project #5
// Node.h

#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
  private:
   ItemType        item;      // Data item.
   Node<ItemType>* next;      // Pointer to the next node.

 public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
}; // End Node.

#include "Node.cpp"
#endif // End Node.h
