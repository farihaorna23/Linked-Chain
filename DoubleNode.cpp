//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.cpp 
    Listing 4-2 */


/*
Author: Fariha Hossain
Course: CSCI-235
Instructor: Prof. Wole Oyekoya
Assignment: Project 3: : Doubly-Linked List
Puprose: This is part 1 of the project. This is the source file. 
Over here we would implement the functions that has been declared in the DoubleNode.hpp file(header file).

*/    


#include "DoubleNode.hpp"
//#include <cstddef>

//default constructor
template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : next(nullptr), prev(nullptr) 
{
} // end default constructor


//perimeter constructor. It sets an item sent as a parameter to a node. 
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType item_) : item(item_), next(nullptr), prev(nullptr) 
{
} // end constructor


// method that gets the item from the node. It returns private data members item
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const 
{
   return item;
} // end getItem


// a method that gives a pointer to the next node. It returns private data members next
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext()
{
   return next;
}

//a mthod that gives a pointer to the previous node. It returns private data members prev
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() 
{
   return prev;
}

//a method that sets the next address of a Double Node. The private data member *next is set to nextNodePtr
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr) 
{
   next = nextNodePtr;
} // end setNext

//a method that sets the previous address of a Double Node. The private data member *prev is set to prevNodePtr
template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* prevNodePtr) 
{
   prev = prevNodePtr;
} // end setNext

// a method that sets the item in a Double Node. The private data member item is set to anItem which is in the paramter
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem) 
{
   item=anItem;
}
