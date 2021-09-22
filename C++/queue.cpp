#include <bits/stdc++.h>
using namespace std;

void Reverse(queue<int> *q)
{
    stack<int> s;
    while (!q->empty())
    {
        s.push(q->front());
        q->pop();
    }
    while (!s.empty())
    {
        q->push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> *q=new queue<int>();
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    
    int a;
    Reverse(q);
    cout << "Reverse: " << endl;
    while (!q->empty())
    {
        a = q->front();
        cout << a << " ";
        q->pop();
    }

    delete q;
}