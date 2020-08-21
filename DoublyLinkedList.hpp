//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */



/*
Author: Fariha Hossain
Course: CSCI-235
Instructor: Prof. Wole Oyekoya
Assignment: Project 3: :  Doubly-Linked List

Purpose: This is part 2 of the project. Here we define a class DoublyLinkedList. 
This is the header file for DoublyLinkedList.cpp. Here we would declare all the data members and methods.

*/

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "DoubleNode.hpp"
#include <iostream>
using namespace std;

template<class ItemType>
class DoublyLinkedList 
{
private:
   DoubleNode<ItemType>* headPtr; // Pointer to first node
   
   int itemCount;           // Current count of bag items
     
   
public:
   DoublyLinkedList(); //Deafult 
   DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag); // Copy constructor
   ~DoublyLinkedList(); //Destructor
   bool insert(const ItemType& item, const int& position); // method that inserts item at index position in our list 
   bool remove(const int& position);//method that removes the node at index position
   int getSize() const; //method which returns the number of the nodes in the list
   DoubleNode<ItemType> *getHeadPtr() const;//method which returns a copy of the hearPtr
   DoubleNode<ItemType> *getAtPos(const int& pos) const;//method which returns a pointer to the node located at pos
   bool isEmpty() const;//method which returns whether the list is empty
   void clear();//method which clears the list
   void display() const;//method which prints the contents of the list in order
   void displayBackwards() const;//method which prints the contents of the list backwards.
   DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list); //method which alters the calling list to be the interleaved list of the original and parameter lists

}; // end of DoublyLinkedList hpp file

#include "DoublyLinkedList.cpp"
#endif