/*
    Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.
*/

/*
    Push(x) : Inserts x at the top of stack.

    If stack is empty, insert x into the stack and make minEle equal to x.
    If stack is not empty, compare x with minEle. Two cases arise:
    If x is greater than or equal to minEle, simply insert x.
    If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.


    Pop() : Removes an element from top of stack.

    Remove element from top. Let the removed element be y. Two cases arise:
    If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
    If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
*/

#include <bits/stdc++.h>
using namespace std;

struct MyStack
{

    stack<int> s;
    int minElement;

    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty" << endl;
        else
            cout << "Minimum element in the stack is: "
                 << minElement << endl;
    }

    void peek()
    {
        if (s.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        int top = s.top(); // top element

        cout << "Top element is: ";

        // If top < minElement that means minElement stores value of top
        (top < minElement) ? cout << minElement : cout << top;
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top MOst Element Removed: ";
        int top = s.top();
        s.pop();

        // Minimum will change as the minimum element of the stack is being removed
        if (top < minElement)
        {
            cout << minElement << endl;
            minElement = (2 * minElement) - top;
        }
        else
        {
            cout << top << endl;
        }
    }

    void push(int x)
    {
        if (s.empty())
        {
            minElement = x;
            s.push(x);
            cout << "Number inserted: " << x << endl;
        }

        if (x < minElement)
        {
            s.push((2 * x) - minElement);
            minElement = x;
        }
        else
        {
            s.push(x);
            cout << "Number inserted: " << x << endl;
        }
    }
};

// Driver
int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
    s.getMin();

    return 0;
}