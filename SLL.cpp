#include "LinkedLists.h"

int main()
{
    singlyLinkedList myList;
    int choice;
    while (1)
    {
        cout << "SIMPLE LINKED LIST" << endl
             << "MENU" << endl
             << "---------------" << endl;
        cout << "1. Display" << endl
             << "2. Push Front" << endl
             << "3. Push Back" << endl
             << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        //check for bad input
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number" << endl
                 << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                myList.display();
                break;
            case 2:
                myList.pushFront();
                break;
            case 3:
                myList.pushBack();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Not A Choice" << endl
                     << endl;
                break;
            }
        }
    }
    return 0;
}

singlyLinkedList::singlyLinkedList()
{
    head = nullptr;
}

singlyLinkedList::~singlyLinkedList()
{
    if (head)
    {
        SLLNode *current, *next;
        current = head;
        while (current)
        {
            next = current->nextNode;
            delete current;
            current = next;
        }
        head = nullptr;
    }
}

void singlyLinkedList::pushBack()
{
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
    }
    else
    {
        SLLNode *temp = head;
        while (temp->nextNode)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = new SLLNode;
        temp = temp->nextNode;
        cout << "ENTER Singly LL #: ";
        cin >> temp->data;
        cout << endl;
        temp->nextNode = nullptr;
    }
}

void singlyLinkedList::pushFront()
{
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
    }
    else
    {
        SLLNode *temp = head;
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = temp;
    }
}

void singlyLinkedList::display()
{
    SLLNode *temp = head;
    while (temp)
    {
        cout << temp->data << ", ";
        temp = temp->nextNode;
    }
    cout << endl
         << endl;
}