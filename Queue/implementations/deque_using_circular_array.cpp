// IMPLEMENTATION OF DEQUE USING CIRCULAR ARRAY
/*
  Operations on Deque:
    Mainly the following four basic operations are performed on queue:
    insetFront(): Adds an item at the front of Deque.
    insertRear(): Adds an item at the rear of Deque.
    deleteFront(): Deletes an item from front of Deque.
    deleteRear(): Deletes an item from rear of Deque.

    In addition to above operations, following operations are also supported
    getFront(): Gets the front item from queue.
    getRear(): Gets the last item from queue.
    isEmpty(): Checks whether Deque is empty or not.
    isFull(): Checks whether Deque is full or not.  
*/

#include <iostream>
using namespace std;

// Maximum size of array
#define MAX 100

// A structure represent a Deque
class Deque
{

    int arr[MAX];
    int front, rear, size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insertFront(int key);
    void insertRear(int key);
    void deleteFront();
    void deleteRear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};

// Checks whether Deque is full
bool Deque::isFull()
{

    return ((front == 0 && rear == size - 1) || front == rear + 1);
}

// Checks whether Deque is empty
bool Deque::isEmpty()
{

    return front == -1;
}

// Insert element at front
void Deque::insertFront(int key)
{

    if (isFull())
    {
        cout << "Overflow" << endl;
        return;
    }

    // if queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // front is at first position of queue
    else if (front == 0)
        front = size - 1;

    // decrement front by 1
    else
        front = front - 1;

    // insert current element into queue
    arr[front] = key;
}

// Function to insert element at rear end of Deque
void Deque::insertRear(int key)
{

    if (isFull())
    {
        cout << "Overflow" << endl;
        return;
    }

    // if queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // rear is at last position of queue
    else if (rear == size - 1)
        rear = 0;

    // increment raer end by 1
    else
        rear = rear + 1;

    // inser current element into Deque
    arr[rear] = key;
}

// delete element at front end of Deque
void Deque::deleteFront()
{

    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    // back to initial position
    else if (front == size - 1)
        front = 0;

    // increment front bay 1 to remove current front value from Deque
    else
        front = front + 1;
}

// Delete element at rear end of queue
void Deque::deleteRear()
{

    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return;
    }

    // deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}

// Returns front element of Deque
int Deque::getFront()
{

    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return -1;
    }

    return arr[front];
}

// Function return rear element of Deque
int Deque::getRear()
{

    if (isEmpty() || rear < 0)
    {
        cout << "Underflow" << endl;
        return -1;
    }

    return arr[rear];
}

// Driver
int main()
{

    Deque dq(5);

    cout << "Insert Element at rear end: 5" << endl;
    dq.insertRear(5);
    cout << "Insert Element at rear end: 10" << endl;
    dq.insertRear(10);

    cout << "Get rear element " << dq.getRear() << endl;
    dq.deleteRear();
    cout << "After deleting at rear " << dq.getRear() << endl;

    cout << "Insert Element at front end: 15" << endl;
    dq.insertRear(15);

    cout << "Get front element " << dq.getFront() << endl;
    dq.deleteFront();

    cout << "After deleting front " << dq.getFront() << endl;

    return 0;
}