#include <bits/stdc++.h>
using namespace std;

char startCh[] = {'(', '{', '['};
char endCh[] = {')', '}', ']'};

enum targetBrack{start,end};

// find char index position
template <typename type>
int findIndex(type value, targetBrack target)
{
    for (int i = 0; i < 3; i++)
    {
        if (target == start)
        {
            if (startCh[i] == value)
            {
                return i;
            }
        }
        else
        {
            if (endCh[i] == value)
            {
                return i;
            }
        }
    }
    return -1;
}

// is it first brack
bool startBrac(char ch)
{
    for (int i = 0; i < 3; i++)
    {
        if (ch == startCh[i])
            return true;
    }
    return false;
}

// is it second brack
bool endBrac(char ch)
{
    for (int i = 0; i < 3; i++)
    {
        if (ch == endCh[i])
            return true;
    }
    return false;
}

int main()
{
    string str = "[(a+b)*({a*(a+c)}+2)]";
    int len = str.length();
    stack<char> s;

    for (int i = 0; i < len; i++)
    {
        if (startBrac(str[i]))
        {
            s.push(str[i]);
        }

        if (endBrac(str[i]) && (findIndex<char>(str[i],targetBrack::end) == findIndex<char>(s.top(), targetBrack::start)))
        {
            s.pop();
        }
    }

    if (s.empty())
    {
        cout << "Balance Bracket" << endl;
    }
    else
    {
        cout << "Not Balance Bracket" << endl;
    }
}