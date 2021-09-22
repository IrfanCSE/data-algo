#include <iostream>
#include "stack.cpp"
// #include <bits/stdc++.h>
using namespace std;

class StackQueue
{
private:
    stack<int> *sPush;
    stack<int> *sPop;

public:
    StackQueue();
    ~StackQueue();
    void enqueue(int item);
    int dequeue();
    int peak();
    bool isEmpty();
    void print();
};

StackQueue::StackQueue()
{
    sPush = new stack<int>(5);
    sPop = new stack<int>(5);
}

StackQueue::~StackQueue()
{
    delete sPush;
    delete sPop;
}

void StackQueue::enqueue(int item)
{
    sPush->push(item);
}

int StackQueue::dequeue()
{
    while (!sPush->isEmpty())
    {
        sPop->push(sPush->peek());
        sPush->pop();
    }

    int value = sPop->peek();
    sPop->pop();
    return value;
}

int StackQueue::peak()
{
    while (!sPush->isEmpty())
    {
        sPop->push(sPush->peek());
        sPush->pop();
    }

    return sPop->peek();
}

bool StackQueue::isEmpty()
{
    return sPush->isEmpty() && sPop->isEmpty();
}

void StackQueue::print()
{
    while (!sPush->isEmpty())
    {
        sPop->push(sPush->peek());
        sPush->pop();
    }
    while (!sPop->isEmpty())
    {
        cout << sPop->peek() << " ";
        sPop->pop();
    }
}

int main()
{
    StackQueue sq;
    sq.enqueue(10);
    sq.enqueue(20);
    sq.enqueue(30);
    sq.enqueue(40);
    sq.enqueue(50);
    sq.enqueue(60);
    sq.dequeue();
    sq.dequeue();
    sq.dequeue();
    sq.dequeue();
    sq.enqueue(70);
    // sq.enqueue(80);

    // int top = sq.dequeue();
    // cout << "top : " << top << endl;

    // top = sq.dequeue();
    // cout << "top : " << top << endl;

    // top = sq.peak();
    // cout << "top : " << top << endl;

    sq.print();
}