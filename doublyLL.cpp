#include <bits/stdc++.h>
using namespace std;

class DoublyNode
{
public:
    int val;
    DoublyNode *Prev;
    DoublyNode *Next;

    DoublyNode(int val)
    {
        this->val = val;
        Prev = NULL;
        Next = NULL;
    }
};

void insertAtHead(DoublyNode *&head, int val)
{
    // step one newNode create
    DoublyNode *newNode = new DoublyNode(val);
    // additional for doubly LL: update of head->prev
    head->Prev = newNode;
    // step3 update of newNode-> Next
    newNode->Next = head;
    // step4 update of head
    head = newNode;
}

void insertAtTail(DoublyNode *&head, int val)
{
    DoublyNode *newNode = new DoublyNode(val);
    // if the list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // if the list is not empty
    DoublyNode *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    // only line added for doubly LL
    newNode->Prev = temp;
}

void display(DoublyNode *n)
{
    while (n != NULL)
    {
        cout << n->val;
        if (n->Next != NULL)
            cout << " <--> ";
        n = n->Next;
    }
    cout << endl;
}

void displayRev(DoublyNode *&head)
{
    DoublyNode *temp = head;

    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    while (temp != NULL)
    {
        cout << temp->val;
        if (temp->Prev != NULL)
        {
            cout << " -->";
        }
        temp = temp->Prev;
    }

    cout << endl;
}

int main()
{
    DoublyNode *head = NULL;
    int value, pos;

    cout << "choice 1: insertion at Head" << endl
         << "choice 2: insertion at tail" << endl
         << "choice 0: Exit" << endl;

    cout << "next choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value ";
            cin >> value;
            insertAtTail(head, value);
            break;
        default:
            break;
        }

        display(head);
        cout << "Next choice: ";
        cin >> choice;
    }
}