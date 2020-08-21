//Author: Fariha Hossain

#include <iostream>
using namespace std;
#include "LinkedBag.h"
#include "BagInterface.h"

int main()
{
    LinkedBag<int> obj;

    cout<<obj.add(5)<<endl;
    cout<<obj.add(10)<<endl;
    cout<<obj.add(15)<<endl;
    //cout<<obj.add(20)<<endl;

    /*vector<int> obj2;
   
    obj2=obj.toVector();

    for(int i=0; i<obj2.size(); i++)
    {
        cout<<obj2[i]<<endl;
    }

    obj.deleteSecondNode();

    obj2=obj.toVector();

    for(int i=0; i<obj2.size(); i++)
    {
        cout<<obj2[i]<<endl;
    }
    
    */

    cout<<obj.getCurrentSize()<<endl;

    cout<<obj.getCurrentSizeRecursive()<<endl;


    int arr [] = {1,2,3,4};



    cout<<obj.removeRandom()<<endl;

    LinkedBag <int> ll(arr, 4);
    vector<int> obj2;
   
    obj2=ll.toVector();

    for(int i=0; i<obj2.size(); i++)
    {
        cout<<obj2[i]<<endl;
    }





    
   

    
    
    return 0;
}
