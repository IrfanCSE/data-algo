#include <iostream>
using namespace std;

template <class Type>
class stack
{
private:
    int count = 0;
    int stackSize = 5;
    Type *ary;

public:
    stack();
    stack(int size);
    ~stack();
    void push(Type item);
    Type pop();
    Type peek();
    bool isEmpty();
    void print();
};

template <class Type>
stack<Type>::stack()
{
    ary = new Type[5];
}

template <class Type>
stack<Type>::stack(int size)
{
    ary = new Type[size];
    stackSize = size;
}

template <class Type>
stack<Type>::~stack()
{
    delete[] ary;
}

template <class Type>
void stack<Type>::push(Type item)
{
    ary[count++] = item;
}

template <class Type>
Type stack<Type>::pop()
{
    return ary[--count];
}

template <class Type>
Type stack<Type>::peek()
{
    return ary[count - 1];
}

template <class Type>
void stack<Type>::print()
{
    for (int i = 0; i < count; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;
}

template <class Type>
bool stack<Type>::isEmpty()
{
    return count <= 0;
}

//comment out cz of use on another file

// int main()
// {
//     stack s(5);
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.pop();
//     s.pop();
//     s.push(10);
//     s.push(20);
//     // int top=s.pop();
//     // top=s.pop();
//     // s.pop();
//     int top=s.peek();

//     s.print();
//     cout<<"top value: "<<top<<endl;
// }