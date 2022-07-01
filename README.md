# Queues
Fun with Queues

1.Add the member functionsizeinboth ofthe provided queue implementations; queueType.hand linkedQueue.h. The function returns the number of elements in the queue.Demonstratethe function(this cannot be done in the same driver program; use demo1.cpp& demo2.cpp).

2.Write the program queuesFun.cppthat uses the modified LinkedQueueclass in part 1. The programincludes the following functions:

a.Template function nElement(LinkedQueue<T>&q, int n) that returns and removes the n'th element in queue q. 

b.Template function isEqualQueuesthat receives two queues; q1 and q2. The function returns true if the queues are the same and false otherwise. The function should leave the queues unchanged. 

c.Template function divide(q,q1,q2) that copies the 1st half of q into q1 and the 2nd half into q2, leaving the original queue unchanged. You may assume that q always has an even number of elements.

d. Template recursive function append(q1, q2) that appends q2 at the end of q1. q2 should be empty after calling the function.

