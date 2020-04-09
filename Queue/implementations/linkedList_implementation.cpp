// QUEUE - LINKED LIST IMPLEMENTATION
/*
   In a Queue data structure, we maintain two pointers, front and rear. The front points the first item of queue and rear points to last item.

    enQueue() This operation adds a new node after rear and moves rear to the next node.



    deQueue() This operation removes the front node and moves front to the next node. 
*/

#include <bits/stdc++.h>
using namespace std;

struct QNode
{
    int data;
    QNode *next;

    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue
{
    QNode *front, *rear;

    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(int x)
    {

        // create a new LL Node
        QNode *temp = new QNode(x);

        // if queue is epmty, then new node is front and rear
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        // add the new node at the end of the queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove a key from give queue q
    void deQueue()
    {

        // if queue is empty, return NULL
        if (front == NULL)
            return;

        // store prev front and move front one node ahead
        QNode *temp = front;
        front = front->next;

        // if front becomes NULL, then change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};

// Driver
int main()
{
    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.deQueue();

    cout << "Queue Front: " << q.front->data << endl;
    cout << "Queue Rear: " << q.rear->data << endl;
}