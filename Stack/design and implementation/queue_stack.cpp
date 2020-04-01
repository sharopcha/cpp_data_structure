/* 
    Implement Queue using Stacks

    We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and operations on them.

    A queue can be implemented using two stacks. Let queue to be implemented be q and stacks used to implement q be stack1 and stack2. q can be implemented in two ways:

*/

// Implement Queue using two stacks with costly enQueue()

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
// METHOD 1

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements form s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push items into s1
        s1.push(x);

        // Push everything back to s1
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
            cout << "Q is empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

*/

/*
// METHOD 2

struct Queue
{
    stack<int> s1, s2;

    // Enque an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stack are empty
        if (s1.empty() && s2.empty())
        {
            cout << "Q is empty" << endl;
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
*/

// Implement Queue using one stack and recursive call stack
struct Queue
{
    stack<int> s;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty())
        {
            cout << "Q is empty";
            exit(0);
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return the popped item
        if (s.empty())
            return x;

        // recursive call
        int item = deQueue();

        // push popped item back to the stack
        s.push(x);

        // return the result of deQueue() call
        return item;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl; //1
    cout << q.deQueue() << endl; //2
    cout << q.deQueue() << endl; //3

    return 0;
}
