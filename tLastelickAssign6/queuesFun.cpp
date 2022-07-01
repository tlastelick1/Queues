//*****************************************************************
//Name: Trevor Lastelick
//Class: COSC 2437 001
//Instructor: Marwa Hassan
//Assignment 6
//Date: 10/28/20
//Program Description: 
//Removes the nTH element (7th) from queue q and returns it to integer n and cout's n. 
//Checks if queue q2 is identical to queue q3 and couts "True" (because it is identical, else would cout false, because it is false)
//Divides the queue q1 in half (does not actually manipulate q1) and adds the first half, one by one, to the queue q2. Takes the second half of q and adds it to q3 one by one. 
//Appends the elements in queue q3 to the rear of q2 one by one. q3 is empty after function runs. q2 has doubled in size.
//*********************************************************************
#include <iostream>
#include "LinkedQueue.h"

using namespace std;

template<class Type>
int nElement(LinkedQueue<Type> &, int);

template <class Type>
bool isEqualQueues(LinkedQueue<Type> q1, LinkedQueue<Type> q2);

template <class Type>
void divide(LinkedQueue<Type> q, LinkedQueue<Type> &q1, LinkedQueue<Type> &q2);

template <class Type>
void append(LinkedQueue<Type>& q1, LinkedQueue<Type>& q2);

int main()
{
    int n = 0;
    LinkedQueue<int> q;
    q.addQueue(5);
    q.addQueue(99);
    q.addQueue(999);
    q.addQueue(55);
    q.addQueue(22);
    q.addQueue(51);
    q.addQueue(777);
   
   LinkedQueue<int> q1 = q;
   q1.deleteQueue();
   
   LinkedQueue<int> q2;
   LinkedQueue<int> q3;
   
   // testing nElement function
   // removes 7th item in list
   // returns 777 to n
   cout << "Removing the 7th item in queue q" << endl;
   n = nElement(q, 7);
   cout << "The contents of that item are: " << n << endl;
   
   // testing isEqualQueues function
   // true because both are empty
   if (isEqualQueues(q2, q3))
    cout << "True, both queues are equal" << endl;
   else
    cout << "False, both queues are not equal" << endl; 
    // testing divide function
    // will put the first 3 elements of q1 into q2
    // will put the latter 3 elements of q1 into q3
    // q1 will still have size = 6
    divide(q1, q2, q3);
   
    // testing append function
    // will append the elements in q2 to q3 one by one
    // q2 will have size = 0. q3 will have size = 6.
   
   
   
    append(q2, q3);
    cout << "q2 size = " << q2.size() << endl;
    cout << "q3 size = " << q3.size() << endl;


    return 0;
}

//Function to remove and return the nTH element in argument q
//Precondition: The queue exists and is not empty.
//Postcondition: If queue is empty program terminates; Otherwise each element leading to and including n is deleted. Only n is returned.
template<class Type>
int nElement(LinkedQueue<Type> &q, int n)
{
   int num =0;
   
   //if n is bigger than list size
   if (n>q.size())
    {
    cout << "Error. List is only " << q.size() << " big." << endl;
    cout << "Returning ";
    }

   // This condition is not necessary. Will be solved by for statement.
   // if first node is the one 
   // else if (n==1)
   // {
   //  num = q.front();
   //  q.deleteQueue();
   // }
   
   else
    {
    // stop at node requestd by user, deleting all nodes up until then. Assign requested node to num, then delete it.
    for (int i=0; i<n; i++)
    {
        num = q.front();
        q.deleteQueue();
    }
    
    }
    return num;
}   

// Function that returns true if queues are the same, false otherwise
// Precondition: Both queues exist. 
// Postcondition: Returns true if both queues are identical, false otherwise.
template <class Type>
bool isEqualQueues(LinkedQueue<Type> q1, LinkedQueue<Type> q2)
{
    // create copies of q1 and q2 to manipulate
    LinkedQueue<Type> q11 = q1;
    LinkedQueue<Type>  q22 = q2;
    
    bool equal = true; // flag
    
    // not equal if size's of lists are different
    if (q11.size() != q22.size())
        equal = false;
    
    // traverse entire list
    for (int i=0; i<q11.size(); i++)
    {
        // if both nodes are equal. 
        // delete those nodes and move onto the next nodes
        if (q11.front() == q22.front())
        {
            q11.deleteQueue();
            q22.deleteQueue();
        }
        
        // if at any point both nodes are false
        // set flag to false and return it
        else
        {
            equal = false;
            return equal;
        }        

    } // end for   
    return equal;
}
// Function that copies first half of q into q1 and the second half of q into q2
//Precondition: q must have an even number of elements and q1 and q2 must be empty.
//Postcondition: If q1 or q2 were not empty than error message otherwise q remains unchanged and q1 recieves first half of elements in q and q2 recieves second half of elements in q. 

template <class Type>
void divide(LinkedQueue<Type> q, LinkedQueue<Type> &q1, LinkedQueue<Type> &q2)
{
    // So original q list does not get manipulated
    // Is not actually needed as long as argument in header does not point to memory via &
    //LinkedQueue<Type> copyQ = q;
    
    // if either q1 or q2 is not an even list
    if (q1.size() != 0 )
        cout << "Error. q1 is not an empty queue. " << endl;
    
    else if (q2.size() != 0)
        cout << "Error. q2 is not an empty queue. " << endl;
    
    else
    {
    int firstSize = q.size()/2; // first half size of q
    // add first half of q list into q1
    for(int i=0; i<firstSize; i++)
    {
        q1.addQueue(q.front());
        q.deleteQueue();
    }
    
    // add second half of q list into q2
    int secondSize = q.size(); // updated size after first cycle has ran
    for (int i=0; i<secondSize; i++)
    {
        q2.addQueue(q.front());
        q.deleteQueue();
    }
    
    } //end else
       
}

//Function that appends q2 to q1.
//Precondition: two queues, one must be filled, but both can be filled. 
//Postcondition: appends q2 to q1. q2 is empty by the end of the function.
template <class Type>
void append(LinkedQueue<Type>& q1, LinkedQueue<Type>& q2)
{
    // base case
    // if only one element left in q2
    // function stops after this execution
    if (q2.size() == 1)
    {
        q1.addQueue(q2.front());
        q2.deleteQueue();
    }
    
    // check if the second queue does not have any values
    // if true then just return with error message.
    else if (q2.size() == 0)
        cout << "Error. Did not append any elements because the second queue did not have any values." << endl;
    // general case
    // append q2 to q1
    // run the function again until only 1 element left in q2
    else
    {
        q1.addQueue(q2.front());
        q2.deleteQueue();
        append(q1, q2);
    }

}
