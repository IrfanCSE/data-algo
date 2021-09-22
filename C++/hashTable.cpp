#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Entry
{
public:
    int Key;
    string Value;
    Entry(int key, string value)
    {
        Key = key;
        Value = value;
    }
};

class HashTable
{
private:
    list<Entry> *item;
    int size = 5;

public:
    HashTable();
    void Put(int key, string value);
    string Get(int key);
};

HashTable::HashTable()
{
    item = new list<Entry>[5];
}

void HashTable::Put(int key, string value)
{
    if (Get(key) != NULL)
    {
        Entry en = Entry(key, value);

        list<Entry>::iterator i;

        for (i = bucket.begin(); i != bucket.end(); i++)
        {
            Entry itm = *i;
            if (itm.Key == key)
                item[key].insert(i, en);
                return;
        }
    }
    int index = key % size;
    item[key].push_back(en);
}

string HashTable::Get(int key)
{
    int index = key % size;
    list<Entry> bucket = item[index];
    list<Entry>::iterator i;

    for (i = bucket.begin(); i != bucket.end(); i++)
    {
        Entry itm = *i;
        if (itm.Key == key)
            return itm.Value;
    }
    return NULL;
}

int main()
{
    HashTable h;
    // h.Put(0,"zero");
    h.Put(1, "one");
    h.Put(2, "two");

    cout << h.Get(3) << endl;

    return 0;
}
