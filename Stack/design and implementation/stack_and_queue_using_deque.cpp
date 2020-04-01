/*
    Deque also known as double eneded queue, as name suggests is a special kind
    of queue in which insertions and deletions can be done at the last as well
    as at the beginning.

    A link-list representation of deque is such that each node points to the next
    node as well as the previous node. So that insertion and deletions take constant
    time at both the beginning and the last.

            DEQUE               STACK             QUEUE
        size()                 size()           size()
        isEmpty()              isEmpty()        isEmpty()
        Insert_First()           --               --
        Insert_Last()          push()           enqueue()
        Remove_First()           --             dequeue()
        Remove_Last()          pop()              --
       
*/

#include <bits/stdc++.h>
using namespace std;

// structure for a node of deque
struct DQueNode
{
    int value;
    DQueNode *next;
    DQueNode *prev;
};

// implementation of deque class
class deque1
{
private:
    // pointers to head and tail of deque
    DQueNode *head;
    DQueNode *tail;

public:
    // constructor
    deque1()
    {
        head = tail = NULL;
    }

    // if list is empty
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    // count number of nodes in list
    int size()
    {
        // if list is empty
        if (!isEmpty())
        {
            DQueNode *temp = head;
            int len = 0;

            while (temp != NULL)
            {
                len++;
                temp = temp->next;
            }

            return len;
        }

        return 0;
    }

    // insert at the first position
    void insert_first(int element)
    {

        // allocating node of DQueNode type
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if the element is first element
        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    // insert at last position of deque
    void insert_last(int element)
    {

        // allocating node of DQueNode type
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if element is the first element
        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    // remove element at the first position
    void remove_first()
    {

        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
            return;
        }

        cout << "List is empty" << endl;
    }

    // remove element at the first position
    void remove_last()
    {

        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);

            return;
        }

        cout << "List is empty" << endl;
    }

    // display the elements in deque
    void display()
    {

        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = head;

            while (temp != NULL)
            {
                cout << temp->prev << " ";
                temp = temp->next;
            }

            cout << endl;
            return;
        }

        cout << "List is empty" << endl;
    }
};

// Class to implement stack using deque
class Stack : public deque1
{
public:
    // push to psuh element at top of stack
    // using insert at lat function of deque
    void push(int element)
    {
        insert_last(element);
    }

    // pop to remove elemnt at top of stack
    // using remove at last function of deque
    void pop()
    {
        remove_last();
    }
};

// Calss to implement queue using deque
class Queue : public deque1
{
public:
    // enqueue to insert element at last
    // using insert at last function of deque
    void enqueue(int element)
    {
        insert_last(element);
    }

    // dequeue to remove elemnet from first
    // using remove at first function of deque
    void dequeue()
    {
        remove_first();
    }
};

// Driver
int main()
{

    // obj of stack
    Stack stk;

    // push 8 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();

    // obj Queue
    Queue queue;

    // insert 12 and 13 in queue
    queue.enqueue(12);
    queue.enqueue(13);
    cout << "Queue: ";
    queue.display();

    // delete an element from queue
    queue.dequeue();
    cout << "Queue: ";
    queue.display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << queue.size() << endl;

    return 0;
}