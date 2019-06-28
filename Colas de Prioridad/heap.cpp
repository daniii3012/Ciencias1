#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "heap.h"
using namespace std;

int main()
{
    BinaryHeap<int> h;
    while (1)
    {
        cout<<"1) Insert Element"<<endl;
        cout<<"2) Print Heap"<<endl;
        cout<<"3) Atender"<<endl;
        cout<<"4) Exit"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        	
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            h.Insert(element);
            system("cls");
            break;
        case 2:
        	system("cls");
            cout<<"Displaying elements of Hwap:  ";
            h.DisplayHeap();
            break;
        case 3:
        	
            cout<<"Atender: ";
            h.DeleteMin();
            system("cls");
            break;
        case 4:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    return 0;
}
