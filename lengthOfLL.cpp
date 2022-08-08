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

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

int main()
{
    Node *head = NULL;
    int value;

    cout << "choice 1: Insertion at head" << endl
         << "choice 2: Insertion at tail" << endl
         << "choice 0: Exit" << endl;

    cout << "first value will automatically inserted at head" << endl;

    cout << "Next Choice" << endl;

    int choice;
    cin >> choice;
    int count = 0;

    while (choice != 0)
    {
        cout << "Enter the value: ";

        cin >> value;
        switch (choice)
        {
        case 1:
            insertAtHead(head, value);
            count++;
            break;
        case 2:
            insertAtTail(head, value);
            count++;
            break;
        default:
            break;
        }

        cout << "Next choice? (1:insertion at head, 2: insertion at tail)" << endl;
        cin >> choice;
    }

    cout << "actual linked list" << endl;
    display(head);

    cout << "length of list is " << countLength(head) << endl;

    cout << "after reversing linked list" << endl;
    reversedListPrint(head);
}