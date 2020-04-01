/*
    Create a customized data structure which evaluates functions in O(1)

        Create a customized data structure such that it has functions :-
        GetLastElement();
        RemoveLastElement();
        AddElement()
        GetMin()
*/

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000;

class Stack
{
    int min;
    int size;

public:
    Stack()
    {
        min = 99999;
        size = -1;
    }

    vector<pair<int, int>> arr;
    int GetLastElement();
    int RemoveLastElement();
    int AddElement(int elem);
    int GetMin();
};

int Stack::AddElement(int elem)
{

    if (size > MAX)
    {
        cout << "Stack overflow, max size reached" << endl;
        return 0;
    }

    if (elem < min)
        min = elem;

    arr.push_back(make_pair(elem, min));
    size++;

    return 1;
}

int Stack::GetLastElement()
{

    if (size == -1)
    {
        cout << "Stack is empty. No elemnts in stack" << endl;
        return 0;
    }

    return arr[size].first;
}

int Stack::RemoveLastElement()
{

    if (size == -1)
    {
        cout << "Stack empty!!" << endl;
        return 0;
    }

    // updating minimum element
    if (size > 0 && arr[size - 1].second > arr[size].second)
    {
        min = arr[size - 1].second;
    }

    arr.pop_back();
    size -= 1;

    return 1;
}

int Stack::GetMin()
{

    if (size == -1)
    {
        cout << "Stack empty!!" << endl;
        return 0;
    }

    return arr[size].second;
}

// Driver
int main()
{
    Stack s;

    int success = s.AddElement(5);
    if (success == 1)
        ;
    cout << "5 inserted successfully" << endl;

    int success = s.AddElement(7);
    if (success == 1)
        ;
    cout << "7 inserted successfully" << endl;

    int success = s.AddElement(3);
    if (success == 1)
        ;
    cout << "3 inserted successfully" << endl;

    int min1 = s.GetMin();
    cout << "min element: " << min1 << endl;

    success = s.RemoveLastElement();
    if (success == 1)
        cout << "Removed successfully" << endl;

    int success = s.AddElement(2);
    if (success == 1)
        ;
    cout << "2 inserted successfully" << endl;

    int success = s.AddElement(9);
    if (success == 1)
        ;
    cout << "9 inserted successfully" << endl;

    int last = s.GetLastElement();
    cout << "Last element: " << last << endl;

    int success = s.AddElement(0);
    if (success == 1)
        ;
    cout << "0 inserted successfully" << endl;

    int min1 = s.GetMin();
    cout << "min element: " << min1 << endl;

    success = s.RemoveLastElement();
    if (success == 1)
        cout << "Removed successfully" << endl;

    int success = s.AddElement(11);
    if (success == 1)
        ;
    cout << "11 inserted successfully" << endl;

    int min1 = s.GetMin();
    cout << "min element: " << min1 << endl;

    return 0;
}