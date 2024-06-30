#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// remove duplicates from sorted linked list.
void removeDuplicates(Node *head)
{
    Node *curr = head;
    Node *p = NULL;

    if (curr == NULL || curr->next == NULL)
    {
        return;
    }

    p = curr;
    curr = curr->next;

    while (curr)
    {
        if (curr->data != p->data)
        {
            p->next = curr;
            p = curr;
            curr = curr->next;
        }
        else
        {
            Node *temp = curr;
            curr = curr->next;
            delete (temp);
        }
    }
    p->next = NULL;
}
int main()
{
    Node *t1 = new Node(10);
    Node *t2 = new Node(20);
    Node *t3 = new Node(30);
    Node *t4 = new Node(40);
    Node *t5 = new Node(50);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;

    removeDuplicates(t1);
    cout << endl;
    printList(t1);
    return 0;
}