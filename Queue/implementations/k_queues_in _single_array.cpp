// IMPLEMENTATION OF k QUEUES IN A SINGLE ARRAY IN TIME AND SPACE EFFICIENT WAY

/*
    Create a data structure kQueues that represents k queues. Implementation of kQueues should use only one array, i.e., k queues should use the same array for storing elements. Following functions must be supported by kQueues.

    enqueue(int x, int qn) –> adds x to queue number ‘qn’ where qn is from 0 to k-1
    dequeue(int qn) –> deletes an element from queue number ‘qn’ where qn is from 0 to k-1
*/

#include <iostream>
#include <climits>
using namespace std;

class kQueues
{

    // array of size to store actual content to be stored in queue
    int *arr;

    // array of size k to store indexes of front elements of the queue
    int *front;

    // array of size k to store indexes of rear elements of queue
    int *rear;

    // array of size k to store next entry in all queues
    int *next;
    int n, k;

    // to store the begining index of the free list
    int free;

public:
    // constructor to create k queue in an array of size n
    kQueues(int k, int n);

    // a utility func to check if there is space available
    bool isFull()
    {
        return (free == -1);
    }

    void enqueue(int item, int qn);

    int dequeue(int qn);

    // to check whether qn is empty
    bool isEmpty(int qn)
    {
        return front[qn] == -1;
    }
};

kQueues::kQueues(int k1, int n1)
{

    // init n and k, allocate memory for all arrays
    k = k1, n = n1;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    next = new int[n];

    // init all spaces as free
    free = 0;
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1; //-1 is used to indicate end of free list
}

void kQueues::enqueue(int item, int qn)
{

    // overflow
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }

    int i = free; // store index of first free slot

    // update index of free slot to index of next slot in free list
    free = next[i];

    if (isEmpty(qn))
        front[qn] = i;
    else
        next[rear[qn]] = i;

    next[i] = -1;

    // update next of rear and then rear for queue number qn
    rear[qn] = i;

    // put item in array
    arr[i] = item;
}

int kQueues::dequeue(int qn)
{

    if (isEmpty(qn))
    {
        cout << "Queue underflow" << endl;
        return INT_MAX;
    }

    // find index of front item in qn
    int i = front[qn];

    // change top to store next of prev top
    front[qn] = next[i];

    // attach the prev front to the begining of free list
    next[i] = free;
    free = i;

    // return the prev front item
    return arr[i];
}

// Driver
int main()
{

    // create 3 queue in array of size 10
    int k = 3, n = 10;
    kQueues ks(k, n);

    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is: " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is: " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is: " << ks.dequeue(0) << endl;

    return 0;
}