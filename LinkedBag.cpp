//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

/*
Author: Fariha Hossain
Course: CSCI-235
Instructor:
Assignment: Project 2: : Templates, Pointers, Arrays, and Linked-Lists

This is the source file. Over here we would implement the functions that has been declared in the Linkedbag.hpp file(header file).
There is a total of 5 parts in this project where we would create some method and modify other methods.

*/


#include "LinkedBag.h"
#include "Node.h"
#include <cstdlib>
#include <cstddef>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

//****************************************************
//this is a perimeter constructor where we set itemCount to 0 and headPtr to nullptr
//we are suppose to  create a bag from a given array of entries.
//to do so a for loop was created and the add function was called so that it can add the desired entries by the user
//******************************************
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount): itemCount(0), headPtr(nullptr)
{
   
   for(int i=0; i<entryCount; i++)
   {
      add(entries[i]);
   }

}


template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor



template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

//********************************************************************
//The main purpose was to revise the method getCurrentSize() so that it counts the number of nodes iteratively
//here we create a varibale that will counts the number of nodes in the linked list and we also create a new ptr
//With the help of the while loop it goes through the linklist until it reaches the nullptr 
//our counter variable that was created counts the number of node in the linked list and then returns the number of item in the linked list
//***************************************************************************

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	
   int count_nodes=0;

   Node<ItemType>*ptr4=headPtr;

   while(ptr4 != nullptr)
   {
      ptr4=ptr4->getNext();
      count_nodes++;
   }
      
   return count_nodes;
}  // end getCurrentSize

//***********************************************************************
//The purpose of this function was to create a method which will count and returns the number of nodes in the chain recursively.
//Since there is no perimeter for int getCurrentSizeRecursive(), a wapper function has been used  called temp_recur_count_func
//which passes a pointer in its paremeter
//this function would get the number of nodes in the linked list recursivley
//It will keep increasing by one (depending on the number of nodes in the linked list ) and will call the function again with the next node


//Now in the original int getCurrentSizeRecursive() that was supposed to be created, we simply call our temp_recur_count_func
//Over here we sent our wrapper function the headptr as the parameter
//********************************************************************


template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive()
{
   return temp_recur_count_func(headPtr);
}

template<class ItemType>
int LinkedBag<ItemType>::temp_recur_count_func(Node<ItemType>* currptr)
{
   if(currptr==nullptr)
   {
      return 0;
   }

   else
   {
      return 1+temp_recur_count_func(currptr->getNext());
   }
}

//************************************************
//The purpose of the add fuction was to modify it so that so that the new node is inserted at the end of the linked chain.
//For this modifcation, first a new node was created called nextNodePtr and then it was set to the new entry by using the setItem() function
//For this project some conditions were made to deal with different cases
//So in case, if there is no item in the linked chain then headptr is eventually assigned to the nextNodePtr that has been created with the newentry inside it
//the itemcount++ is used to increment and keep track of the number of items in the linked chain



//In another case, where there is existent item/data in the linked list, we create a another a pointer called temptr which points towards headptr
// then the temptr goes through a while loop and the getnext function to get to the last node
//Then the temptr is set to the nextnodeptr that was created at first carrying the entry from the user
//and nextNode is set to the nullptr
//we again, use the itemcount++ to increment and keep track of the number of items in the linked chain
//Since this is a bool function, it will return 1 when entry has been added to the Linked Chain
//********************************************************************


template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   
   Node<ItemType>* nextNodePtr = new Node<ItemType>(); 
   nextNodePtr->setItem(newEntry);

   Node<ItemType>* temp_ptr=headPtr; //pointing towards headptr

   if(temp_ptr==nullptr)
   {
      headPtr=nextNodePtr;
      itemCount++;
      
   }
   
  else
  {
     while(temp_ptr->getNext()!= nullptr)
   {
      temp_ptr=temp_ptr->getNext();
   }
     
   temp_ptr->setNext(nextNodePtr); 

   nextNodePtr->setNext(nullptr);

   
   itemCount++;
   
   
  }

  return true;
}  // end add

//***********************************************
//The purpose of this fuction was to delete the second node if headPtr is a pointer variable that points to the first node of a linked chain
//to avoid complication in case there is less than two nodes in the linked list, we create an if statment that only deletes the secod node when there is atleast two nodes or more
//For this one we also create another new pointer that will point towards the second node
//And will set the first node to be the third node
// We delete the ptr2 and set it to nullptr
//it is important to delete the new ptr created and set it to null ptr to avoid dangling point
//itemcount--- is used to decrement as we are removing an item and this helps to keep track of the item
//*****************************************************


template<class ItemType>
void LinkedBag<ItemType>:: deleteSecondNode()
{   
   if(itemCount>=2)
   {
      Node<ItemType>* ptr2 = headPtr->getNext();
      headPtr->setNext(ptr2->getNext());
      delete ptr2;
      ptr2=nullptr;

      itemCount--; 
   }
}





template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if

	return canRemoveItem;
}  // end remove

//*********************************************************************
//The purpose of this function was to create a method that will remove an entry from the bag in a pseudo-random fashion and returns it to the system.
//For this method, we have three cases 
//(1) if the first node is deleted
//(2)if the second node is deleted
//(3) if the middle node is deleted
//before dealing with the cases, we generate a random number using the random function


//First case where the node to be deleted is the first one
//a variable is created
// headnode item/data is stored in a variable using using the getitem() 
//Next, head is made the second node 
//then the variable were the data was stored is returned
//itemcount--- is used to keep track of the number of nodes/item in the linked list

//Second case where if the node to be deleted is the last one
//A new pointer is created that points to the headptr 
//by using a do while loop we go through the linkedlist until we reach the second to last node
//Again we create a new pointer that is used to store the last node
//Next, we set the first pointer we created in the begining to nullptr
//later, we store the value in the last node by using getItem() 
//it is then returned
////itemcount--- is used to keep track of the number of nodes/item in the linked list

//Third case where the node to be deleted is the middle node
//two new nodes are created which point to headptr
//by using a for loop we go through the linkedlist where the pointers (before and pos) before_ptr is always being one node before the pos_ptr.
//Next a variable is created to store the value in the node that is supposed to be deleted
//the before pointer is set to the next node using the setNext() and getNext()
//the pos pointer is set to nullptr and it is later deleted
//the stored variable is then returned and itemcount--- is used to keep track of the number of nodes in the linked list
//********************************************************************



template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom()
{
   int index;
   index = rand() % itemCount;

   if(index==0)
   {
      ItemType store_var=headPtr->getItem();
      headPtr=headPtr->getNext();
      return store_var;
      itemCount--;
   }

   else if(index==itemCount)
   {
      Node<ItemType>* before=headPtr;
      do{
         before=before->getNext();
      }
      while(before->getNext()->getNext() !=nullptr);
      Node<ItemType>* end_node=before->getNext();
      before->setNext(nullptr);
      ItemType store_last_val=end_node->getItem();
      return store_last_val;
      itemCount--;
      
   }

   else
   {
      Node<ItemType>* before_ptr=headPtr;
      Node<ItemType>* pos_ptr=headPtr;
      for(int i=0; i<index; i++)
      {
         before_ptr=pos_ptr;
         pos_ptr=pos_ptr->getNext();
      }

      ItemType store_var=pos_ptr->getItem();
      before_ptr->setNext(pos_ptr->getNext());
      pos_ptr->setNext(nullptr);
      delete pos_ptr;
      itemCount--;
      return store_var;
   }
}


template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo


