/*
    Create a data structure kStacks that represents k stacks. Implementation of kStacks should use only one array, i.e., k stacks should use the same array for storing elements. Following functions must be supported by kStacks.

push(int x, int sn) –> pushes x to stack number ‘sn’ where sn is from 0 to k-1
pop(int sn) –> pops an element from stack number ‘sn’ where sn is from 0 to k-1
*/

// Implementation of k stacks in a single array in time and space efficient way
#include <bits/stdc++.h>
using namespace std;

// A class to represent k sutacks in a single array of size n
class kStacks
{

    int *arr;  // arry of size n to store actual content to be stored in stacks
    int *top;  // array of size k to store indexes of top elements of stacks
    int *next; // array of size n to store next entry in all stacks
    int n, k;
    int free; // to store begining index of free list

public:
    // constructor to create k stacks in an array of size n
    kStacks(int k, int n);

    // a utility function to check if there is space availble
    bool isFull() { return (free == -1); }

    // to push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int item, int sn);

    // to pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int sn);

    // to check wheter stack number 'sn' is empty or not
    bool isEmpty(int sn) { return (top[sn] == -1); }

    // test all members of an arry
    void testAllElementsInArray(int n);
};

// Constructor to create k stacks in an array of size n
kStacks::kStacks(int k1, int n1)
{

    // initializen and k, and allocate memory for all arrys
    k = k1;
    n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];

    // initialize all stacks as empty
    for (int i = 0; i < k; i++)
    {
        top[i] = -1;
    }

    // initialize all spaces as free
    free = 0;
    for (int i = 0; i < k; i++)
    {
        next[i] = i + 1;
        next[n - 1] = -1; // -1 is used to indicate end of free list
    }
}

void kStacks::testAllElementsInArray(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " member of the arry" << arr[i] << endl;
    }
}

// To push an item in stack number 'sn' where sn is from 0 to k-1
void kStacks::push(int item, int sn)
{

    // overflow check
    if (isFull())
    {
        cout << "Stack overflow" << endl;
    }

    int i = free; // store index of first free slot

    // update index of free slot to indicate of next slot in free list
    free = next[i];

    // update next of top and then top for stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;

    // put the item in array
    arr[i] = item;
}

// To pop an from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{

    // underflow check
    if (isEmpty(sn))
    {
        cout << "Stack inderflow" << endl;
        return INT_MAX;
    }

    // find index of top item in stack number 'sn'
    int i = top[sn];

    top[sn] = next[i]; //change top to store next of previous top

    // attach the previous top to the begining of free list
    next[i] = free;
    free = i;

    // return the prev top item
    return arr[i];
}

// Driver
int main()
{

    // create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);

    // put some items in stack number 2
    ks.push(45, 2); // x
    ks.push(15, 2); // v

    // put some items in stack number 1
    ks.push(17, 1);
    ks.push(39, 1);
    ks.push(49, 1);

    // put some items in stack number 0
    ks.push(11, 0);
    ks.push(7, 0);
    ks.push(9, 0);

    cout << "poped element from stack 2 is: " << ks.pop(2) << endl;
    cout << "poped element from stack 1 is: " << ks.pop(1) << endl;
    cout << "poped element from stack 0 is: " << ks.pop(0) << endl;
    // cout << "poped element from stack 3 is: " << ks.pop(3) << endl;

    ks.testAllElementsInArray(n);

    return 0;
}