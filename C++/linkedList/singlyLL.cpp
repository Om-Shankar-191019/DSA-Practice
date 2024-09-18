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

    // cout << " \n i am done with print" << endl;
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
Node *reverseIterative(Node *head)
{
    Node *curr = head;
    Node *p = NULL;
    while (curr)
    {
        Node *t = curr->next;
        curr->next = p;
        p = curr;

        curr = t;
    }
    return p;
}

Node *segregateEvenOdd(Node *head)
{
    Node *evenHead = NULL;
    Node *oddHead = NULL;
    Node *e = NULL;
    Node *o = NULL;

    Node *curr = head;
    while (curr)
    {
        if (curr->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                e = curr;
            }
            else
            {
                e->next = curr;
                e = curr;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                o = curr;
            }
            else
            {
                o->next = curr;
                o = curr;
            }
        }
        curr = curr->next;
    }

    if (e)
    {
        e->next = oddHead;
        if (o)
        {
            o->next = NULL;
        }
        return evenHead;
    }
    else
    {
        if (o)
        {
            o->next = NULL;
        }
        return oddHead;
    }
}
int main()
{
    Node *nul = NULL;
    Node *t1 = new Node(17);
    Node *t2 = new Node(15);
    Node *t3 = new Node(8);
    Node *t4 = new Node(12);
    Node *t5 = new Node(5);
    Node *t6 = new Node(4);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;

    Node *result = segregateEvenOdd(t1);
    cout << endl;
    printList(result);
    // printList(t1);

    return 0;
}