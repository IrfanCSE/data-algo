#include <iostream>
using namespace std;

// Array main class
class Array
{
private:
    int *items;
    int count;
    int initLength;

public:
    Array(int length);
    void Insert(int value);
    void RemoveAt(int index);
    void Print();
    void Size();
    void FindAt(int index);
    int IndexOf(int value);
};

// impliment constractor
Array::Array(int length)
{
    initLength = length;
    items = new int[length];
    count = 0;
}

// print full array
void Array::Print()
{
    for (int i = 0; i < count; i++)
    {
        cout << items[i] << endl;
    }
}

// insert a value.
void Array::Insert(int value)
{
    if (initLength == count)
    {
        initLength = count * 2;
        int *newItems = new int[initLength];
        for (int i = 0; i < count; i++)
        {
            newItems[i] = items[i];
        }
        items = newItems;
    }
    items[count] = value;
    count++;
}

// delete a value.
void Array::RemoveAt(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "Can't Remove index " << index << endl;
        return;
    }

    for (int i = index; i < count; i++)
    {
        items[i] = items[i + 1];
    }
    count--;
}

// find a value from index
void Array::FindAt(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "Invalid index " << index << endl;
        return;
    }
    cout << "The value is : " << items[index] << endl;
}

// Find index of a value
int Array::IndexOf(int value)
{
    for (int i = 0; i < count; i++)
    {
        if (items[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// Find Size of array.
void Array::Size()
{
    cout << "Array Size : " << count << endl;
}

// Main Program.
int main()
{
    Array ary(3);

    ary.Insert(2);
    ary.Insert(3);
    ary.Insert(4);
    ary.Insert(5);
    ary.Insert(1);

    ary.RemoveAt(1);

    ary.FindAt(1);
    int i = ary.IndexOf(5);
    if(i>=0){
        cout<<"index is: "<<i<<endl;
    }
    else
    {
        cout<<"index not found"<<endl;
    }

    ary.Print();
    ary.Size();
}