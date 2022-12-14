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
        head = temp->Next;
        int deleted = temp->value;
        delete temp;
        cout << deleted << " deleted perfectly" << endl;
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
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
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

Node *reverseNonRec(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (head == NULL)
    {
        cout << "the list is empty" << endl;
        return head;
    }
    Node *next = head->Next;
    int i = 1;
    while (true)
    {
        cout << "situation " << i << endl;
        current->Next = prev; // ok
        prev = current;       // ok
        current = next;       //
        if (current == NULL)
        {
            break;
        }
        next = next->Next;
        display(prev);
        i++;
    }
    return prev;
}

Node *reverseRec(Node *&head)
{
    // base call
    if (head == NULL || head->Next == NULL)
        return head;
    // recursive call
    Node *newHead = reverseRec(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return newHead;
}

int findMid(Node *&head)
{
    // case 1: if head is empty
    if (head == NULL)
    {
        return -1;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    return slow->value;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;

    while (temp->Next != NULL)
    {
        if (count == pos)
            startNode = temp;
        temp = temp->Next;
        count++;
    }

    temp->Next = startNode;
}

bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;

        // check
        if (slow->Next == fast->Next)
            return true;
    }
    return false;
}

void removeCycle(Node *&head)
{
    if (head == NULL)
    {
        cout << "No value in linked list" << endl;
    }
    Node *slow = head;
    Node *fast = head;
    do
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    } while (slow != fast);

    // step 2: re initialization of fast
    fast = head;

    while (fast->Next != slow->Next)
    {
        slow = slow->Next;
        fast = fast->Next;
    }

    slow->Next = NULL;
}

int main()
{
    Node *head = NULL;
    int value, position;

    cout << "choice 1: Insertion at head" << endl
         << "choice 2: Insertion at tail" << endl
         << "choice 3: Insertion at specific position"
         << endl
         << "choice 4: search a value for unique list"
         << endl
         << "choice 5: search a value for duplicate list"
         << endl
         << "choice 6: Insertion after a specific value for unique list"
         << endl
         << "choice 7: Deletion at head"
         << endl
         << "choice 8: Deletion at tail"
         << endl
         << "choice 9: Deletion at specific position"
         << endl
         << "choice 10: Deletion by a specific value"
         << endl
         << "choice 11: Reversal of a List Non Recursive"
         << endl
         << "choice 12: Reversal of a List Non Recursive"
         << endl
         << "choice 13: Find Mid of Linked List(slow fast pointer method)"
         << endl
         << "choice 14: Make a cycle at kth position"
         << endl
         << "choice 15: Detect a cycle in linked list"
         << endl
         << "choice 16: Delete a cycle in linked list"
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
            cout << "enter desired position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecific(head, position, value);
            break;
        case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValUnq(head, value);
            if (position != -1)
            {
                cout << "the number is at position " << position << endl;
            }
            else
            {
                cout << "the number not found" << endl;
            }
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            Test T;
            T = searchByValDupReturn(head, value);
            if (T.position[0] == 1)
                cout << "the search value is not yet in the list" << endl;
            else
            {
                int size = T.position[0];
                cout << "the number is found at position ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << endl;
            }

            break;
        case 6:
            cout << "Enter the value to search ";
            int searchVal;
            cin >> searchVal;
            cout << "Enter the value to insert ";
            cin >> value;
            searchByValUnqSpecific(head, searchVal, value);

        case 7:
            deletionAtHead(head);
            display(head);
            break;
        case 8:
            deletionAtTail(head);
            display(head);
            break;
        case 9:
            cout << "Enter the position to delete ";
            cin >> value;
            if (head == NULL)
            {
                cout << "no value in the linked list" << endl;
            }
            deletionAtSpecificPos(head, value);
            display(head);
            break;
        case 10:
            cout << "Enter the position to delete ";
            cin >> value;
            deletionBySpecVal(head, value);
            break;

        case 11:
            head = reverseNonRec(head);
            cout << "Linked list reversed in Non-recursive way, new link is" << endl;
            display(head);
            break;

        case 12:
            head = reverseRec(head);
            cout << "Linked list reversed in recursive way, new link is" << endl;
            display(head);
            break;
        case 13:
            int mid;
            mid = findMid(head);
            if (mid == -1)
            {
                cout << "the list is empty" << endl;
            }
            else
            {
                cout << "Mid value is " << mid << endl;
            }

            break;
        case 14:
            cout << "Enter the position to create cycle " << endl;
            int pos;
            cin >> pos;
            makeCycle(head, pos);
            break;

        case 15:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if (cycleStatus)
                cout << "Cycle available" << endl;
            else
            {
                cout << "No cycle " << endl;
            }
        case 16:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if (cycleStatus)
                removeCycle(head);
            else
            {
                cout << "No cycle " << endl;
            }
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