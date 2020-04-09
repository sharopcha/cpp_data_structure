// Queue ca be implemented using one user stack and on Function Call Stack
/*
    enQueue(x)
    1) Push x to stack1.

    deQueue:
    1) If stack1 is empty then error.
    2) If stack1 has only one element then return it.
    3) Recursively pop everything from the stack1, store the popped item 
        in a variable res,  push the res back to stack1 and return res
*/

#include <bits/stdc++.h>
using namespace std;

struct Queue
{

    stack<int> s;

    // enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }

    // dequeue an item from the queue
    int deQueue()
    {

        if (s.empty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return the poped item
        if (s.empty())
            return x;

        int item = deQueue();

        // push popped item back to the satck
        s.push(x);

        // return the result of deQueue() call
        return item;
    }
};

// Driver
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}