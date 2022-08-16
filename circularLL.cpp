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

struct Test
{
    int position[1000];
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    // if the list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // if the list is not empty
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

void display(Node *head)
{

    if (head == NULL)
    {
        cout << "empty LL" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->value;
        temp = temp->Next;
        if (temp != head)
            cout << " -> " << endl;
    } while (temp != head);

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

    do
    {
        count++;
        temp = temp->Next;
    } while (temp != head);

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

int searchByValUnq(Node *&head, int key)
{
    Node *temp = head;
    int count = 0;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }

    return count;
}

void searchValDup(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if (flag == 0)
        cout << "the search value is not yet in the list" << endl;
    else
    {
        position[0] = k;
        cout << "the valie is found at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
        cout << endl;
    }
}

Test searchByValDupReturn(Node *&head, int key)
{
    Node *temp = head;
    int size;
    Test T;
    int k = 1;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }

    T.position[0] = k;
    return T;
}

void searchByValUnqSpecific(Node *&head, int searchVal, int value)
{
    // step 1 search the position of the value
    int pos;
    pos = searchByValUnq(head, searchVal);
    // step 2 insert the value to the specific position
    insertAtSpecific(head, pos + 1, value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode = temp;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = delNode->Next;
        head = delNode->Next;
        delete delNode;
        // head = temp->Next;
        // int deleted = temp->value;
        // delete temp;
    }
    else
    {
        cout << "No value in linked list" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
        display(head);
    }
    else
    {
        // head is null
        if (temp == NULL)
        {
            cout << "No value in linked list";
            display(head);
        }
        // head is tail
        deletionAtHead(head);
    }
}

void deletionAtSpecificPos(Node *&head, int pos)
{
    Node *temp = head;

    if (temp != NULL && pos <= countLength(head))
    {
        if (pos == 1)
            deletionAtHead(head);
        else if (pos == countLength(head))
            deletionAtTail(head);

        else
        {
            int i = 1;
            while (i < pos - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        // position is out of range
        if (pos > countLength(head))
        {
            cout << "position is out of bound" << endl;
        }
        // LL is null
        else
        {
            cout << "no value in linked list" << endl;
        }
    }
}

void deletionBySpecVal(Node *&head, int val)
{
    // find the position of the value
    int pos = searchByValUnq(head, val);

    if (pos != -1)
    {
        deletionAtSpecificPos(head, pos);
    }
    else
    {
        cout << "value is not found so can't delete" << endl;
    }
}

int main()
{
    Node *head = NULL;
    int value, position;

    cout << "choice 1: Insertion at head" << endl
         << "choice 2: Insertion at tail" << endl
         << "choice 3: Deletion of head"
         << endl
         << "choice 0: Exit" << endl;

    cout << "Next Choice" << endl;
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            deletionAtHead(head);
            break;

        default:
            break;
        }

        cout << "Next choice? (1:insertion at head, 2: insertion at tail, 3: insertion at specific)" << endl;
        cin >> choice;
    }

    cout << "actual linked list" << endl;
    display(head);
}