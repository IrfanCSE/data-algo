#include <bits/stdc++.h>

using namespace std;

int main()
{
    string target;
    string subject;

    cout << "Target : ";
    cin >> subject;
    
    cout << "Remove : ";
    cin >> target;
    
    string setValue = "";
    int len = subject.length();
    int lenA = target.length();

    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (target[i] != subject[j])
            {
                setValue += subject[j];
            }
        }
        subject = setValue;
        setValue = "";
    }

    cout << subject << "\t";

    return 0;
}