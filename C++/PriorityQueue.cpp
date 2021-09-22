#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int *ary;
    int size;
    int front = 0;
    int rear = 0;
    int count = 0;

public:
    PriorityQueue(int length);
    ~PriorityQueue();
    void enqueue(int item);
    int dequeue();
    int peak();
    void move(int item);
    bool isEmpty();
    bool isFull();
    void print();
};

PriorityQueue::PriorityQueue(int length)
{
    size = length;
    ary = new int[length];
}

PriorityQueue::~PriorityQueue()
{
    delete[] ary;
}

void PriorityQueue::enqueue(int item)
{
    if (isFull())
    {
        cout << "Queue Full" << endl;
        return;
    }
    
    if (isEmpty())
    {
        ary[rear] = item;
    }
    else
    {
        move(item);
    }

    rear = (rear + 1) % size;
    count++;
}

int PriorityQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Empty" << endl;
        return 0;
    }
    int item = ary[front];
    ary[front] = 0;
    front = (front + 1) % size;
    count--;
    return item;
}

int PriorityQueue::peak()
{
    return ary[front];
}

void PriorityQueue::move(int item)
{
    for (int i = rear; i >= 0; i--)
    {
        if (item > ary[i - 1])
        {
            ary[i] = item;
            break;
        }
        ary[i] = ary[i - 1];
    }
}

bool PriorityQueue::isEmpty()
{
    return count == 0;
}

bool PriorityQueue::isFull()
{
    return count == size;
}

void PriorityQueue::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;
}

int main()
{
    PriorityQueue pq(5);
    pq.enqueue(50);
    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(40);
    pq.enqueue(10);

    pq.dequeue();
    pq.dequeue();

    pq.enqueue(100);

    pq.print();

    cout<<pq.peak();
}