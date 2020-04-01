/*
    Implement a stack using a single queue

        // x is the element to be pushed and s is stack
    push(s, x) 
    1) Let size of q be s. 
    1) Enqueue x to q
    2) One by one Dequeue s items from queue and enqueue them.
    
    // Removes an item from stack
    pop(s)
    1) Dequeue an item from q  
*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{

    queue<int> q;

public:
    void push(int val);
    void pop();
    int top();
    bool empty();
};

void Stack::push(int val)
{

    // get prev size of queue
    int size = q.size();

    // push current element
    q.push(val);

    // pop (or dequeue) all prev elems and put them after curr elm
    for (int i = 0; i < size; i++)
    {
        // this adds fron elem into rear of queue
        q.push(q.front());

        // delete front elem
        q.pop();
    }
}

void Stack::pop()
{
    if (q.empty())
        cout << "No elements" << endl;
    else
        q.pop();
}

int Stack::top()
{
    return (q.empty()) ? -1 : q.front();
}

bool Stack::empty()
{
    return (q.empty());
}

// Driver
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;

    return 0;
}