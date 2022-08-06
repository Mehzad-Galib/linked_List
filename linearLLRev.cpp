#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    // created constructor
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    // step one newNode create
    Node *newNode = new Node(val);
    // step2 update of newNode-> Next
    newNode->Next = head;
    // step3 update of head
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl;
}

void reversedListPrint(Node *head)
{
    if (head == NULL)
        return;

    reversedListPrint(head->Next);

    cout << head->value << " ";
}

int main()
{
    Node *head = NULL;

    cout << "choice 1: insertion at head" << endl
         << "choice 2: insertion at tail" << endl
         << "choice 3: exit" << endl;

    cout << "first value will automatically inserted at head" << endl;

    int choice = 1;

    while (choice == 1 || choice == 2)
    {
        cout << "Enter the value: ";
        int n;
        cin >> n;
        if (choice == 1)
        {
            insertAtHead(head, n);
        }
        else if (choice == 2)
        {
            insertAtTail(head, n);
        }

        cout << "Next choice? (1:insertion at head, 2: insertion at tail)" << endl;
        cin >> choice;
    }

    cout << "actual linked list" << endl;
    display(head);

    cout << "after reversing linked list" << endl;
    reversedListPrint(head);
}