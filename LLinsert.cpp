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

void insertAtSpecific(Node *&head, int pos, int val)
{
    int i = 0;
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);

    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int main()
{
    Node *head = NULL;
    int value, position;

    cout << "choice 1: Insertion at head" << endl
         << "choice 2: Insertion at tail" << endl
         << "choice 3: Insertion at specific"
         << endl
         << "choice 0: Exit" << endl;

    cout << "first value will automatically inserted at head" << endl;

    cout << "Next Choice" << endl;

    int choice;
    cin >> choice;
    int count = 0;

    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            count++;
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            count++;
            break;
        case 3:
            cout << "enter desired position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecific(head, position, value);
            break;
        default:
            break;
        }

        cout << "Next choice? (1:insertion at head, 2: insertion at tail, 3: insertion at specific)" << endl;
        cin >> choice;
    }

    cout << "actual linked list" << endl;
    display(head);

    // cout << "length of list is " << countLength(head) << endl;

    // cout << "after reversing linked list" << endl;
    // reversedListPrint(head);
}