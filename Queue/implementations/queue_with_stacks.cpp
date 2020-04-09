// Implementing queue using two stacks
// METHOD 1
/*
    enQueue(q, x):

    While stack1 is not empty, push everything from stack1 to stack2.
    Push x to stack1 (assuming size of stacks is unlimited).
    Push everything back to stack1.
    Here time complexity will be O(n)

    deQueue(q):

    If stack1 is empty then error
    Pop an item from stack1 and return it
*/

#include <bits/stdc++.h>
using namespace std;

/*
struct Queue
{

    stack<int> s1, s2;

    void enQueue(int x)
    {

        // move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // push item into s1
        s1.push(x);

        // push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {

        // if first stack is empty
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }

        // return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};
*/

// METHOD 2
/*
    enQueue(q,  x)
    1) Push x to stack1 (assuming size of stacks is unlimited).
    Here time complexity will be O(1)

    deQueue(q)
    1) If both stacks are empty then error.
    2) If stack2 is empty
        While stack1 is not empty, push everything from stack1 to stack2.
    3) Pop the element from stack2 and return it.
    Here time complexity will be O(n)
*/

struct Queue
{

    stack<int> s1, s2;

    // enqueue an item to the queue
    void enQueue(int x)
    {

        // pushitem into the first stack
        s1.push(x);
    }

    // dequeue an item from the queue
    int deQueue()
    {

        // if both stacks are empty
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }

        // if s2 is empty, move elements from s1
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());

                s1.pop();
            }
        }

        // return the top item from s2
        int x = s2.top();
        s2.pop();

        return x;
    }
};

// Driver
int main()
{
    Queue queue;

    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);

    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;

    return 0;
}