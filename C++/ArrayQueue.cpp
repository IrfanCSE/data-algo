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
    ary[rear] = item;
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
    PriorityQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    // cout << "Front : " << q.dequeue() << endl;
    // q.enqueue(50);
    // q.enqueue(60);
    // q.enqueue(70);
    cout << "Front : " << q.dequeue() << endl;
    cout << "Front : " << q.dequeue() << endl;
    cout << "Front : " << q.dequeue() << endl;
    // cout << "Front : " << q.dequeue() << endl;
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    // q.enqueue(200);
    // q.enqueue(300);
    // q.enqueue(400);
    // cout << "Front : " << q.dequeue() << endl;
    // cout << "Front : " << q.dequeue() << endl;
    // cout << "Front : " << q.dequeue() << endl;
    // cout << "Front : " << q.dequeue() << endl;
    // cout << "Front : " << q.dequeue() << endl;


    q.print();

    cout<<"Top value : "<<q.peak()<<endl;
}