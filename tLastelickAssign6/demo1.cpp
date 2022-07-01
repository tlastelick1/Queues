//*****************************************************************
//Name: Trevor Lastelick
//Class: COSC 2437 001
//Instructor: Marwa Hassan
//Assignment 6
//Date: 10/28/20
//Program Description: Driver program tests queueType member frunction size(). First, initializes a queueType object and adds a couple integers to it. Then cout's member function size() which returns number of elements in a queue.
//******************************************************************
#include <iostream>
#include "queueType.h"

using namespace std;

int main()
{

    //LinkedQueue<int> q1;
    queueType<int> q1;
    q1.addQueue(5);
    q1.addQueue(99);
    cout << q1.size();



    return 0;
}
