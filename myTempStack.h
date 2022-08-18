#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *next;
    Node *prev;
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

// Stack <float> st;

template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // push operation
    void push(S val)
    {
        Node<S> *newNode = new Node<S>(val);
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
    S pop()
    {
        Node<S> *delNode;
        delNode = top;
        S chk;
        // if there is no element(underflow)
        if (head == NULL)
        {
            cout << "stack underflow" << endl;
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
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    S Top()
    {
        S chk;
        if (top == NULL)
        {
            cout << "List is empty and stack underflow" << endl;
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
