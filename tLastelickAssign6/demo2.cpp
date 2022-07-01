//*****************************************************************
//Name: Trevor Lastelick
//Class: COSC 2437 001
//Instructor: Marwa Hassan
//Assignment 6
//Date: 10/28/20
//Program Description: Initializes a linkedQueue object and adds a couple integers to it. Then cout's linkedQueue member function size() which returns number of nodes in that queue. 
//******************************************************************
#include <iostream>
#include "linkedQueue.h"

using namespace std;

int main()
{

    //LinkedQueue<int> q1;
    linkedQueue<int> q1;
    q1.addQueue(5);
    q1.addQueue(99);
    cout << q1.size();



    return 0;
}
