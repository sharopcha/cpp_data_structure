// Circular queue implementation with arry

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    // initialize front and rear
    int rear, front;

    // circular Queue
    int size;
    int *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enqueue(int val);
    int deQueue();
    void displayQueue();
};

// Function to create circular Queue
void Queue::enqueue(int value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (front == -1)
    { // insert firts elemnt
        front = rear = 0;
        arr[rear] = value;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from circular queue
int Queue::deQueue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

// Function dispaying the elements of circular queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Elements in circular queue are: ";

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
}

// Driver
int main()
{
    Queue queue(5);

    queue.enqueue(14);
    queue.enqueue(22);
    queue.enqueue(13);
    queue.enqueue(-6);

    // dispalying elemnets present in circular queue
    queue.displayQueue();

    cout << "Dleted value: " << queue.deQueue() << endl;
    cout << "Deleted value: " << queue.deQueue() << endl;

    queue.displayQueue();

    return 0;
}