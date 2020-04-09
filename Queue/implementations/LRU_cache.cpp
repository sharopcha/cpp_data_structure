// LRU CAHCE IMPLEMENTATION
/*
  We are given total possible page numbers that can be referred. We are also given cache (or memory) size (Number of page frames that cache can hold at a time). The LRU caching scheme is to remove the least recently used frame when the cache is full and a new page is referenced which is not there in cache.  
*/

// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//     (iterator) to each key in a hash map.

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

    // store keys of cache
    list<int> dq;

    int csize;

    // store reference of key in cache
    unordered_map<int, list<int>::iterator> ma;
    // maximum capacity of cache
    int size;

public:
    LRUCache(int);
    void refer(int);
    void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
    csize = n;
}

// Refers key x within the LRU cache
void LRUCache::refer(int x)
{

    // if not present in cache
    if (ma.find(x) == ma.end())
    {
        // cache is full
        if (dq.size() == csize)
        {
            // delete leaset recently used element
            int last = dq.back();

            // pops the last element
            dq.pop_back();

            // earse the last
            ma.erase(last);
        }
    }
    // present in cache
    else
        dq.erase(ma[x]);

    // update reference
    dq.push_front(x);
    ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display()
{

    // Iterate in the deque and print all the lements in it
    for (auto it = dq.begin(); it != dq.end(); it++)
        cout << (*it) << " ";

    cout << endl;
}

// Driver
int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);

    ca.display();

    return 0;
}