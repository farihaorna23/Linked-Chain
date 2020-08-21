//Author: Fariha Hossain

#include <iostream>
#include <cstring>
using namespace std;
#include "DoublyLinkedList.hpp"


int main()
{

   
   cout << "Creating first list" << endl;
   DoublyLinkedList<int>* list1 = new DoublyLinkedList<int>();
   // inset elements
   list1->insert(2, 1);
   list1->insert(4, 2);
   list1->insert(10, 3);
   list1->insert(15, 4);
   list1->insert(17, 5);
   list1->display();

   //cout<<"Removing from position 5"<<endl;
   //list1->remove(2);
   //list1->display();

   cout<<"Give the currentsize "<<endl;
   cout<<list1->getSize();

   //cout<<"Empty "<<endl;
   //list1->isEmpty();

   

   
   cout << "Creating copy of first list" << endl;
   DoublyLinkedList<int> list2(*list1);
   list2.display();

   cout << "tesing clear" << endl;
   list2.clear();

   list2.insert(7, 1);
   list2.insert(8, 2);
   list2.insert(78, 3);
   list2.insert(30, 4);
   list2.insert(40, 5);
   list2.insert(60, 6);
   list2.insert(10, 7);


   
   //list2.display();

   //cout << "value at index 4: " << list2.getAtPos(4)->getItem() << endl;
   //list2.display();

   //cout << "list in reverse" << endl;
   //list2.displayBackwards();

   //cout << "value at index 6: " << list2.getAtPos(6)->getItem() << endl;
   //list2.display();
   
   //cout << "Inter leaving two lists" << endl;
   //DoublyLinkedList<int>list3 = list1->interleave(list2);
   //list3.display();



  return 0;


}