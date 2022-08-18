#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack
{
    Node *head;
    Node *top;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // push operation
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        // O(1) operation
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }
    // pop operation
    int pop()
    {
        Node *delNode;
        delNode = top;
        int chk = -1;
        // if there is no element(underflow)
        if (head == NULL)
        {
            cout << "List is empty and stack underflow" << endl;
            return chk;
        }
        if (top == head) // only one element
        {
            head = top = NULL;
        }
        else // more than one element
        {
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }
    // empty, size, top
    void empty()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "List is not empty" << endl;
        }
    }

    int Top()
    {
        int chk;
        if (top == NULL)
        {
            cout << "List is empty and stack underflow" << endl;
            chk = -1;
        }
        else
        {
            chk = top->value;
        }

        return chk;
    }

    int size()
    {
        return count;
    }
};
