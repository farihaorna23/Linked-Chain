//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */


/*
Author: Fariha Hossain
Course: CSCI-235
Instructor:
Assignment: Project 2: : Templates, Pointers, Arrays, and Linked-Lists

This is the header file. Here we would declare all the data members and methods.

*/

#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   int temp_recur_count_func(Node<ItemType>* currptr);// the warpper function
   
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag(); // Destructor should be virtual
   LinkedBag(ItemType entries[], int entryCount); // the parameter constructor. This creates a bag from a given array of entries.
   int getCurrentSize() const;//keeps track of the number of nodes in the linked chain
   bool isEmpty() const;
   bool add(const ItemType& newEntry);//to add new nodes in the linked chain
   bool remove(const ItemType& anEntry);
   void clear();
   void deleteSecondNode();// method will delete the second node of the chain.
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
   int getCurrentSizeRecursive();//counts and returns the number of nodes in the chain recursively.
   ItemType removeRandom();//method that removes an entry from the bag in a pseudo-random fashion and returns it to the system.
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif