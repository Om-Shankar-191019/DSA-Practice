#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void printNodes(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{

    Node *t1 = new Node(10);
    Node *t2 = new Node(20);
    Node *t3 = new Node(30);
    Node *t4 = new Node(40);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;

    t2->prev = t1;
    t3->prev = t2;
    t4->prev = t3;

    // printNodes(t1);
    return 0;
}