//Header file linkedQueue.h
//Edited by Marwa Hassan

#ifndef H_linkedQueue
#define H_linkedQueue
 
#include <iostream>
#include <cassert>

#include "queueADT.h"

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue as a 
// linked list.
//*************************************************************

template <class Type>
class LinkedQueue: public queueADT<Type>
{
private:
    struct nodeType
    {
        Type info;
        nodeType *next;
    };
    nodeType *queueFront; //pointer to the front of the queue
    nodeType *queueRear;  //pointer to the rear of the queue
    
public:
    const LinkedQueue<Type>& operator=
                    (const LinkedQueue<Type>&);
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty. 
      //Postcondition: Returns true if the queue is empty,
      //    otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full. 
      //Postcondition: Returns true if the queue is full,
      //    otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: queueFront = NULL; queueRear = NULL

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //    terminates; otherwise, the first element of the
      //    queue is returned. 

    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //    terminates; otherwise, the last element of the
      //    queue is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement is
      //    added to the queue.

    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first element
      //    is removed from the queue.

    LinkedQueue();
      //Default constructor

    LinkedQueue(const LinkedQueue<Type>& otherQueue);
      //Copy constructor

    ~LinkedQueue();
      //Destructor
      
      int size();
      //Function to return the number of elements in the list
      //Precondition: The queue exists.
      //Postcondition: The queue is left unchanged. An integer      representing total number of elements (nodes) is returned.

};

    //Default constructor
template<class Type>
LinkedQueue<Type>::LinkedQueue()
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
} //end default constructor


template<class Type>
bool LinkedQueue<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end 

template<class Type>
bool LinkedQueue<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template<class Type>
void LinkedQueue<Type>::initializeQueue()
{
    nodeType *temp;

    while(queueFront!= NULL)  //while there are elements left
                              //in the queue
    {
        temp = queueFront;  //set temp to point to the 
                            //current node
        queueFront = queueFront->next;  //advance first to
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }
    queueRear = NULL;  //set rear to NULL
}  //end initializeQueue

template<class Type>
void LinkedQueue<Type>::addQueue(const Type& newElement)
{
    nodeType *newNode;

    newNode = new nodeType;   //create the node

    newNode->info = newElement; //store the info
    newNode->next = NULL;  //initialize the next field to NULL
	
    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->next = newNode;
        queueRear = queueRear->next;
    }
}//end addQueue

template<class Type>
Type LinkedQueue<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info; 
} //end front

template<class Type>
Type LinkedQueue<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template<class Type>
void LinkedQueue<Type>::deleteQueue()
{
    nodeType *temp;
   
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the 
                            //first node
        queueFront = queueFront->next; //advance queueFront
        delete temp;    //delete the first node

        if (queueFront == NULL) //if after deletion the 
                                //queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cerr << "Cannot remove from an empty queue" << endl;
}//end deleteQueue

    //Destructor
template<class Type>
LinkedQueue<Type>::~LinkedQueue()
{
    nodeType *temp;

    while (queueFront != NULL)  //while there are elements 
                                //left in the queue
    {
        temp = queueFront;  //set temp to point to the 
                            //current node
        queueFront = queueFront->next;  //advance first to
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }
   
    queueRear = NULL;   // set rear to null
} //end destructor

template<class Type>
const LinkedQueue<Type>& LinkedQueue<Type>::operator=
								(const LinkedQueue<Type>& otherQueue)
{
    nodeType *newNode; //pointer to create a node
    nodeType *current; //pointer to traverse the list.
     
    if (this != &otherQueue) //avoid self-copy
    {
        if (queueFront != NULL)  //if the list is not empty, destroy the list
            initializeQueue();

        if (otherQueue.queueFront == NULL) //otherList is empty
        {
            queueFront = NULL;
            queueRear = NULL;
        }	
        else
        {
            current = otherQueue.queueFront;	//current points to the 
                                                //list to be copied

                //copy the front element
            queueFront = new nodeType;    //create the node
            queueFront->info = current->info;   //copy the info
            queueFront->next = NULL;    //set the next field of
                                        //the node to null
            queueRear = queueFront;     //make rear point to the first node
            current = current->next;    //make current point to the next
  		  							    //node of the list being copied

                //copy the remaining list
            while (current != NULL)
            {
                newNode = new nodeType;
                newNode->info = current->info;
                newNode->next = NULL;
                queueRear->next = newNode;
                queueRear = newNode;
                current = current->next;
            }//end while
        }//end else
    }//end else

    return *this; 
} //end assignment operator

	//copy constructor
template<class Type>
LinkedQueue<Type>::LinkedQueue(
                            const LinkedQueue<Type>& otherQueue) 
{
    nodeType *newNode; //pointer to create a node
    nodeType *current; //pointer to traverse the list

    if (otherQueue.queueFront == NULL) //otherList is empty
    {
        queueFront = NULL;
        queueRear = NULL;
    }
    else
    {
        current = otherQueue.queueFront;    //current points to the 
                                            //list to be copied

            //copy the first node
        queueFront = new nodeType;  //create the node
        queueFront->info = current->info; //copy the info
        queueFront->next = NULL;    //set the next field of
                                    //the node to null
        queueRear = queueFront;     //make rear point to the 
                                    //front node
        current = current->next;    //make current point to the
                                    //next node

            //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType;   //create a node
            newNode->info = current->info;  //copy the info
            newNode->next = NULL;       //set the next of
                                        //newNode to null
            queueRear->next = newNode;  //attach newNode after rear
            queueRear = newNode;    //make rear point to
                                    //the actual rear node
            current = current->next;   //make current point to
                                        //the next node
        }//end while
    }//end else
}//end copy constructor

template <class Type>
int LinkedQueue<Type>::size()
{
    nodeType* nodePtr = nullptr;
    
    int count = 0;  // store total size of list
    nodePtr = queueFront;   // start at front


    // if list is empty
    if (nodePtr == nullptr)
        count = 0;
    
    // traverse the list 
    // count each node until no nodes left    
    else
        while (nodePtr != nullptr)
        {
            count++;
            nodePtr = nodePtr -> next;
        }
        
        return count;
        
}



#endif

