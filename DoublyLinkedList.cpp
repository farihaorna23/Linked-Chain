

#include "DoublyLinkedList.hpp"
#include <iostream>
#include <cstring>

/*
Author: Fariha Hossain
Course: CSCI-235
Instructor: Prof. Wole Oyekoya
Assignment: Project 3: : Doubly-Linked List

Purpsose: This is part 2 of the project. This is the source file.
Over here we would implement the functions that has been declared in the DoublyLinkedList.hpp file(header file).

*/




template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0) //default constructor
{
}  // end default constructor

//This method makes a deep copy 
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
    DoubleNode<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original list
   
   //the origChainPtr points towards the original list
   
   if (origChainPtr == nullptr)
   {
       headPtr = nullptr;  // Original bag is empty; so copy is empty as well
   }
   
   else
   {
      // Copy first node
      //sets the item from the orginal list to the copy version
      //the first node's prev address is always nullptr. So we will set its address to nullptr
      headPtr = new DoubleNode<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      headPtr->setPrev(nullptr);
      
      // Copy remaining nodes
      DoubleNode<ItemType>* newChainPtr = headPtr;      // Points to the node in the copy version (the current node)
      DoubleNode<ItemType>* PrevChainPtr = headPtr;     //Points to the node before newchainPtr 
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer for the original list. Moves to the next node.
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original list
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item and has a pointer called newDoubleNodePtr pointing towards it
         DoubleNode<ItemType>* newDoubleNodePtr = new DoubleNode<ItemType>(nextItem);
         

         //the newChainPtr points towards the node before newDoubleNodeptr
         //So newChianPtr's next address should be set to newDoubleNodeptr
         //And the PrevChainPtr points towards the node before newChainPtr
         //so newChainPtr's prev address should be set to PrevChainPtr
         newChainPtr->setNext(newDoubleNodePtr);
         newChainPtr->setPrev(PrevChainPtr);
         

         // Advance pointer. Pointer points to nodes in the copy version. Moves along the list
         newChainPtr = newChainPtr->getNext(); 

         //Adavnce pointers. Pointer which follows behind newchainPtr and moves along the list in the copy version
         PrevChainPtr=PrevChainPtr->getNext();
         
         // Advance pointers. origchainPtr which points towards the original chain and  moves along  the original list
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);   // Flag end of new chain
   }  // end if
}  // end copy constructor

//Destructor
template<class ItemType>
DoublyLinkedList<ItemType>:: ~DoublyLinkedList()
{
    //Because the clear method removes each nodees and deallocates the node as it removes, the destructor simply calls the clear method
    clear(); 
}



//This method inserts item at index position in list
//There are different cases for this method
template<class ItemType>
bool DoublyLinkedList<ItemType>:: insert(const ItemType& item, const int& position)
{
    //precondition
    bool ableToInsert= (position >= 1) && (position <= itemCount+1);

    if(ableToInsert)
    {
        //new node created with the new item and newdoublenode pointer poiting towards it
        DoubleNode<ItemType> *newDoubleNodePtr= new DoubleNode<ItemType> (item);


        //when there is an empty chain and the user wants to insert a new node 
        if(position==1) 
        {       
            //std::cout<<"Inserting at the begin"<<std::endl;
            if(headPtr==nullptr)
            {
                //the first node's previous address is always nullptr
                //so we set its previous addrdess to nullptr
                //since there is no node after the newly inserted node
                //its next address is set to nullptr
                //the headptr is now pointing to the first node
                newDoubleNodePtr->setPrev(nullptr);
                newDoubleNodePtr->setNext(nullptr);
                headPtr=newDoubleNodePtr;
                


            }
            
            else{

            //when there is already one node present in the first poistion and the user wants to insert another node into the first position
            
            //Since newly created node is going to be the inserted before the first node and become the NEW first node
            //setting the prev address of the (soon-to be former) first node to the adress of the newly created node
            headPtr->setPrev(newDoubleNodePtr);
            //the next address of the newly created node is set to the headptr which has the address of the former first node
            newDoubleNodePtr->setNext(headPtr);
            //the previous address of the first node should always be null. So setting the NEW first node's previous address to nullptr
            newDoubleNodePtr->setPrev(nullptr);
            //the headptr is poiting towards the new first node
            headPtr= newDoubleNodePtr;
            }
            
        }

        //when the user wants to add a node at the end of the list
        else if(position==itemCount+1)
        {
            //std::cout<<"Inserting at the end"<<std::endl;
            
            //lastnodeptr is created and it points towards the first node like the headptr
            DoubleNode<ItemType>*lastnodePtr= headPtr;

            while(lastnodePtr->getNext() != nullptr)
            {
                //traverse until it reaches the last node
                lastnodePtr=lastnodePtr->getNext();
                

            }


                //lastnodeptr is pointing towards the last node
                //newDoubleNodePtr pointing towards the newly created node that will be inserted at the end
                //we have to update/set the last node's next address from nullptr to the address of the newly inserted node
                //since newly inserted node is going to be the NEW last node
                //we have to set the newDoubleNodePtr'prev to the address of the lastnodeptr and
                //set the newDoubleNodePtr's next address to nullptr (as it is now the last node)
                lastnodePtr->setNext(newDoubleNodePtr);
                newDoubleNodePtr->setPrev(lastnodePtr);
                newDoubleNodePtr->setNext(nullptr);

        }

        else
        {
            
            //when the user wants to insert a node in the middle
            
            //std::cout<<"Inserting at the middlle"<<std::endl;
            int i=1;
        
            //a pointer pointing to the same node as the headptr 
            DoubleNode<ItemType>*tempPtr= headPtr;

            //traverse through the list and stops at the node which is before the position where the user wants to insert the new node
            while(i != position-1) 
            {
                tempPtr= tempPtr->getNext();
                i++;
            }
           
           //the newDoubleNodePtr is poiting towards the node which is meant to be inserted
           //we need to update its previous and next address 
           //the temptr is pointing towards the node which is before the node that is meant to be inserted
           //we set the prev address of the newly inserted node with the address of the node that is before it and temptr is poiting towards it
           //then we set the next address of the newly inserted node with the address of the node that is after the newly inserted node
           //the temptr is pointing towards the node which has the address of the node that comes after the newly inserted node
           newDoubleNodePtr->setPrev(tempPtr);
           newDoubleNodePtr->setNext(tempPtr->getNext());
           
           //now we have to update the address of the two nodes that were linked together before the new node was inserted
           //the before and after node of the new inserted node must have the address of the newly inserted node
           //the after node's previous address should have the address of the newly inserted node
           //the before node's next address should have the address of the newly inserted node
           //we can set the address of the before node's next address to the address of the newly inserted node
           //now we have to update the address of the after node's previous address
           //the newly insered node's next address has the address of the after node
           //so we can access the after node through the newDoubleNodePtr and set its previous address to the address of the newly inserted node
        
           tempPtr->setNext(newDoubleNodePtr);
           newDoubleNodePtr->getNext()->setPrev(newDoubleNodePtr);
        }
    
    itemCount++; // we increase the number of items in the list
    
    }

    return ableToInsert;  //returns ableToInsert     

}


//This method removes the node at index position
//It also has different cases
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    //precondition
    bool ableToRemove= (position >= 1) && (position <= itemCount+1);
    
    //tempPtr pointing towards the first node like the headptr
    //it will point to the node that is meant to be deleted
    DoubleNode<ItemType>*tempPtr= headPtr;

    if(ableToRemove)
    {
        //if the user wants to remove the first node
        if(position==1)
        {   
            //the headptr always points towards the first node
            //to remove the first node, we set the headptr to point towards the second node
            //also since the first node's prev is always null
            //we use headptr that is now pointing towards the second node to set its previous address to nullptr
            //to break the connection of the former first node with the NEW first node, we also set tempPtr's next address to nullptr        
            
            headPtr=headPtr->getNext();
            headPtr->setPrev(nullptr);
            tempPtr->setNext(nullptr);

            
        }
        
        //if the user wants to remove the last node
        else if(position==itemCount)
        {
            //traverse until it reaches the last node
            while(tempPtr->getNext() != nullptr)
            {
                tempPtr=tempPtr->getNext();
            }

            //the temptr is pointing towards the last node which is meant to be removed
            //in order to break the conncetion between the last node and the node before it
            //we have to set the before's node next address to nullptr
            //the tempPtr's previous address has the address of the before node
            //we can use tempPtr to access the before node and set its next address to nullptr
            //finally we set the previous address of the former last node to nullptr
            tempPtr->getPrev()->setNext(nullptr);
            tempPtr->setPrev(nullptr);            
        }

        else
        {

            //when the user wants to remove a node from the middle
            
            int i=1;

            //traverse until temptr reaches the node that is meant to be deleted
            while(i<position) 
            {
                tempPtr=tempPtr->getNext();
                i++;
            }
            
            //we need to update the adress of the before and after node of the deleted node
            //the before node's next address would have the adreess of the after node
            //the after node's prev address would have the adress of the before node
            //the temptr is still pointing towards the node which is meant to be deleted and  which is in between the before and the after node
            //the node that is supposed to be deleted has both the address of the before and after node
            //the deleted node's previous address has the address of the before node
            //the deleted node's next has the address of the after node
            //so using the tempPtr, we can access those address and update the address of the before and after node
            tempPtr->getPrev()->setNext(tempPtr->getNext());
            tempPtr->getNext()->setPrev(tempPtr->getPrev());
        }
        

        //At the end, we need to deallocate the tempPtr and set it to nullptr
        tempPtr->setNext(nullptr);
        delete tempPtr;
        tempPtr=nullptr;

        itemCount--;//decrease the count of item numbers
    }

    return ableToRemove; //return ableToRemove
}

//This method returns the number of the nodes in the list
template<class ItemType>
int DoublyLinkedList<ItemType>:: getSize() const
{
    return itemCount; 
}

//This method return a copy of the hearPtr
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
    return headPtr;
}

//This method returns a pointer to the node located at pos
template<class ItemType>
DoubleNode<ItemType>*DoublyLinkedList<ItemType>::getAtPos(const int& pos) const
{
    //tempPtr points towards the first node like the headptr
        DoubleNode<ItemType>*tempPtr= headPtr;
    
    //the precondition
    if((pos >= 1) && (pos <= itemCount))
    {
        //traverse through the list until it reaches the desired position
        for(int i=1; i<pos; i++)
        {
            tempPtr=tempPtr->getNext();
        }
    }

//returns the tempPtr which is the pointer to the node located at pos
return tempPtr;
}



//This method returns whether the list is empty
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return itemCount==0;
}

template<class ItemType>
void DoublyLinkedList<ItemType>:: clear()
{
    //itemCount is set to 0
    itemCount=0;

    //deleteptr pointing towards the first node like the headptr
    DoubleNode<ItemType>*deleteptr=headPtr;
    
    //the headpointer traverse through the list
    //the deleteptr follows while deleting each node
    while(headPtr != nullptr)
    {
        headPtr=headPtr->getNext();
        delete deleteptr;
        deleteptr=headPtr;
    }

    delete deleteptr;
    //deleting the deleteptr
}




//This method prints the contents of the list in order
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    //new pointer is created which points towards the first node like headptr
    DoubleNode<ItemType>* displayPtr= headPtr;

    //the displayptr will traverse until it reaches the last node
    //it will print out the item inside each node as it moves along the list
    while(displayPtr->getNext() != nullptr)
    {
        std::cout<<displayPtr->getItem()<<" ";
        displayPtr= displayPtr->getNext();
    }

    std::cout<<displayPtr->getItem()<<std::endl;
    
}

//This method prints the contents of the list backwards.
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    //new pointer is created which points towards the first node like headptr
    //It will eventually point to the last node after traversing
    DoubleNode<ItemType>*tailPtr= headPtr;

    string myresult= "";
    
    //traverse until it reaches the last node
    while(tailPtr->getNext() != nullptr)
    {        
        tailPtr=tailPtr->getNext();
    }
    
    //now reverse the list by traverseing back from the tailptr by using getPrev()
    //and print the items inside each node as it traverse back along the list
    while(tailPtr !=nullptr)
    {
        myresult +=tailPtr->getItem();
        myresult+=" ";
        tailPtr=tailPtr->getPrev();
    }

    //take out last space of the string
    cout<<myresult.substr(0, myresult.length()-1);
    cout<<endl;

}

//This method alters the calling list to be the interleaved list of the original and parameter lists
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
    
    
    //originalptr points towards the headptr of the original list
    DoubleNode<ItemType>*original_ptr=headPtr;
    //by calliing the getHeadPtr, the a_list_para pointer point towards the head of the paramter's list
    DoubleNode<ItemType>*a_list_para=a_list.getHeadPtr();
    
    //a new list is created where we would insert the items from the original list and parameter list
    DoublyLinkedList<ItemType>*newPtr= new DoublyLinkedList();    
   
   //so while neither list is equal to nullptr

    do 
    {
        
        //the new list would call the insert function to add items from original list and then parameter list
        newPtr->insert(original_ptr->getItem(), newPtr->getSize()+1);
        newPtr->insert(a_list_para->getItem(), newPtr->getSize()+1);
        //pointers that keeps on moving along the list
        original_ptr=original_ptr->getNext();
        a_list_para=a_list_para->getNext();
    }
    while((original_ptr!= nullptr) && (a_list_para !=nullptr));//precondition


    //in case if there is any leftover items in the original list
    //call the insert function to add items from the original list
    //and move along the list
    while(original_ptr!= nullptr)
    {
        newPtr->insert(original_ptr->getItem(),newPtr->getSize()+1);
        original_ptr=original_ptr->getNext();
    }

    //in case if there is any leftover items in the parameter list
    //call the insert function to add items from the parameter list
    //and move along the list
    while(a_list_para!=nullptr)
    {
        newPtr->insert(a_list_para->getItem(), newPtr->getSize()+1);
        a_list_para=a_list_para->getNext();
    }

    //the list is returned
    return *newPtr;
}


