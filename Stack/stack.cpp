#include <iostream>

using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];

    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    bool push(int x)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack is full" << endl;
            return false;
        }
        else
        {
            a[++top] = x;
            cout << x << " Pushed into stack" << endl;
            return true;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "There is nothing to pop from the stack" << endl;
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return a[top];
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " Popped from stack" << endl;
    cout << s.peek() << " Peeked from stack" << endl;
    cout << s.isEmpty() << endl;

    return 0;
}