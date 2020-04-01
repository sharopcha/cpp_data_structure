/*
    How to implement a stack which will support following operations in O(1) time complexity?
        1) push() which adds an element to the top of stack.
        2) pop() which removes an element from top of stack.
        3) findMiddle() which will return middle element of the stack.
        4) deleteMiddle() which will delete the middle element.
*/

// Implement a stack that supports findMiddle() and dleteMiddle() in O(1) time

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// A dubly linked list node
class DLLNode
{
public:
    DLLNode *prev;
    DLLNode *next;
    int data;
};

/* The stack is implemented using Doubly Linked List. It maintains pointer to head node, pointer to middle node and count of nodes */

class myStack
{
public:
    DLLNode *head;
    DLLNode *mid;
    int count;
};

// Function to create the stack data structure
myStack *createStack()
{
    myStack *ms = new myStack();
    ms->count = 0;
    return ms;
}

// A function to push an element to the stack
void push(myStack *ms, int new_data)
{
    // Allocate DLLNode and put in data
    DLLNode *new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;

    // since we're adding at the begining, prev is always NULL
    new_DLLNode->prev = NULL;

    // link the old list off the new DLLNode
    new_DLLNode->next = ms->head;

    // increment the count of the stack
    ms->count += 1;

    // change the mid pointer in to cases
    //  1. Linked List is empty
    //  2. Number of nodes in LInked List is odd
    if (ms->count == 1)
    {
        ms->mid = new_DLLNode;
    }
    else
    {
        ms->head->prev = new_DLLNode;

        // update mid if ms->count is even
        if (!(ms->count & 1))
            ms->mid = ms->mid->prev;
    }

    // move head to pint to the new DLLNode
    ms->head = new_DLLNode;
};

// Function to pop element from the stack
int pop(myStack *ms)
{

    // stack underflow
    if (ms->count == 0)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;

    // if Linked List doesn't become empty, update prev of new head as Null
    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;

    // update the mid pointer when we have odd number of elements in the stack.
    // move down the mid pointer
    if ((ms->count) & 1)
        ms->mid = ms->mid->next;

    free(head);

    return item;
}

// Function for finding middle of the stack
int findMiddle(myStack *ms)
{

    if (ms->count == 0)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return ms->mid->data;
}

// Driver code
int main()
{

    myStack *ms = createStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;

    return 0;
}