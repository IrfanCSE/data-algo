#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{
    string str = "irfanul hasan";
    int len = str.length();
    stack<char> s(len);

    string r;

    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        r.append(1,s.pop());
    }

    cout << r << endl;
}