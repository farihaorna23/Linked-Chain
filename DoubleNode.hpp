//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.h 
    Listing 4-1 */


/*
Author: Fariha Hossain
Course: CSCI-235
Instructor: Prof. Wole Oyekoya
Assignment: Project 3: Doubly-Linked List
Purpose: This is part 1 of the project where we would define a class DoubleNode that is capable of holding an item of any arbitrary type ItemType.
This is the header file of DoubleNode. Here we would declare all the data members and methods.
*/

#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

template<class ItemType>
class DoubleNode
{
private:
   ItemType        item; // A data item
   DoubleNode<ItemType>* next; // Pointer to next node
   DoubleNode<ItemType>* prev; // Pointer to previous node
   
   
public:
   DoubleNode(); //Default constructor
   DoubleNode(ItemType item_);//perimeter constructor
   ItemType getItem() const ;//a method that gives the item in a node
   DoubleNode* getNext();//a method that gives a pointer to the next node
   DoubleNode* getPrev();// a method that gives a pointer to the previous node
   void setNext(DoubleNode<ItemType>* nextNodePtr);//this methods sets the next address of a Double Node
   void setPrev(DoubleNode<ItemType>* prevNodePtr);//this methods sets the previous adresss of a Double Node
   void setItem(const ItemType& anItem);//this method set the item of a Double node

   
}; // end of Double Node hpp file

#include "DoubleNode.cpp"
#endif