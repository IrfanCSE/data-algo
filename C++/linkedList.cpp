
#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int value;
    Node *next;
    Node(int item)
    {
        value = item;
    }
};

//LinkedList
class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size = 0;
    void addLast(int item);
    void addFirst(int item);
    bool isEmpty();
    int indexOf(int item);
    bool contain(int item);
    void removeFirst();
    void removeLast();
    Node *previous(Node *node);
    void reverse();
    int Size();
    int *toArray();
    int FindKthNodeFromLast(int k);
    void printList(Node *node);
};

// Add item at last
void LinkedList::addLast(int item)
{
    Node *node = new Node(item);

    if (head == NULL)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    size++;
}

// add item to first
void LinkedList::addFirst(int item)
{
    Node *node = new Node(item);

    if (isEmpty())
    {
        head = tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    size++;
}

// is list empty?
bool LinkedList::isEmpty()
{
    return head == NULL;
}

// find node index number
int LinkedList::indexOf(int item)
{
    int index = 0;
    Node *current = head;
    while (current != NULL)
    {
        if (current->value == item)
            return index;
        else
        {
            current = current->next;
            index++;
        }
    }
    return -1;
}

// is list contain this item?
bool LinkedList::contain(int item)
{
    return indexOf(item) != -1;
}

// remove from first node
void LinkedList::removeFirst()
{
    if (isEmpty())
        return;

    if (head == tail)
    {
        head == tail == NULL;
        size = 0;
        return;
    }

    Node *second = head->next;
    head->next = NULL;
    head = second;
    size--;
}

// remove item from last
void LinkedList::removeLast()
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    if (head == tail)
    {
        head = tail = NULL;
        cout << "Empty list" << endl;
        size = 0;
        return;
    }

    Node *pre = previous(tail);

    tail = pre;
    tail->next = NULL;
    size--;
}

// make this linklist reverse.
// void LinkedList::reverse()
// {
//     if (isEmpty())
//     {
//         cout << "Empty list" << endl;
//         return;
//     }
//     if (head == tail)
//         return;

//     Node *prHead = head;
//     Node *pre;
//     Node *current = previous(tail);
//     Node *rHead = tail;
//     rHead->next = current;

//     while (current != prHead)
//     {
//         pre = previous(current);
//         current->next = pre;
//         current = pre;
//     }
//     tail = head;
//     head = rHead;
//     prHead->next = NULL;
// }

// [EFFICIENT] make this linklist reverse.
void LinkedList::reverse()
{
    if (isEmpty())
        return;

    if (head == tail)
        return;

    Node *current = head;
    tail = current;
    Node *next = current->next;

    while (next != NULL)
    {
        Node *temp = next->next;
        next->next = current;
        current = next;
        next = temp;
    }
    head->next = NULL;
    head = current;
}

// Find out previous value.
Node *LinkedList::previous(Node *node)
{
    Node *current = head;
    Node *previous;

    while (current != NULL)
    {
        if (current->next == node)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int LinkedList::Size()
{
    return size;
}

// make list as array
int *LinkedList::toArray()
{
    int *ary = new int[size];
    Node *current = head;
    for (int i = 0; i < size; i++)
    {
        ary[i] = current->value;
        current = current->next;
    }
    return ary;
}

// find Kth value from last
int LinkedList::FindKthNodeFromLast(int k)
{
    if (isEmpty())
    {
        cout << "Empty List" << endl;
        return -1;
    }

    // if we know the size
    if (k > size)
    {
        cout<<"excede the list size"<<endl;
        return -1;
    }

    Node* first = head;
    Node* second = head;

    for (int i = 0; i < k-1; i++)
    {
        second=second->next;
    }

    while (second!=tail)
    {
        first=first->next;
        second=second->next;
    }
    return first->value;    
}

// print
void LinkedList::printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->value << endl;
        node = node->next;
    }
}

int main()
{
    LinkedList list;
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addFirst(1);

    // int i = list.indexOf(1);
    // cout << "index: " << i << endl;

    // list.removeFirst();
    // list.removeLast();
    // list.removeLast();
    // list.removeLast();
    // list.removeLast();
    // list.removeLast();

    // if (list.contain(1))
    //     cout << "contain: true" << endl;
    // else
    // {
    //     cout << "contain: false" << endl;
    // }
    // list.reverse();
    list.printList(list.head);
    cout << "size is : " << list.size << endl;

    // int *ptr = list.toArray();
    // for (int i = 0; i < list.size; i++)
    // {
    //     cout << ptr[i] << " ";
    // }
    int value=list.FindKthNodeFromLast(1);
    cout<<" k th value is : "<<value<<endl;

    return 0;
}