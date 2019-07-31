#include "LinkedLists.h"

int main()
{
    doublyLinkedList myList;
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

//default constructor
doublyLinkedList::doublyLinkedList()
{
    head = nullptr;
}

//destructor
doublyLinkedList::~doublyLinkedList()
{
    if (head)
    {
        DLLNode *current;
        current = head;
        while (current)
        {
            if (current->previousNode)
            {
                delete current->previousNode;
            }
            if (!current->nextNode)
            {
                delete current;
                break;
            }
            current = current->nextNode;
        }
        head = nullptr;
    }
}

//member function for adding numbers to the end of the list
void doublyLinkedList::pushBack()
{
    if (!head)
    {
        head = new DLLNode;
        head->previousNode = nullptr;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
    }
    else
    {
        DLLNode *temp = head;
        while (temp->nextNode)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = new DLLNode;
        temp->nextNode->previousNode = temp;
        cout << "ENTER Doubly LL #: ";
        cin >> temp->nextNode->data;
        cout << endl;
        temp->nextNode->nextNode = nullptr;
    }
}

void doublyLinkedList::pushFront()
{
    if (!head)
    {
        head = new DLLNode;
        head->previousNode = nullptr;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
    }
    else
    {
        DLLNode *temp = head;
        head = new DLLNode;
        head->previousNode = nullptr;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = temp;
        temp->previousNode = head;
    }
}

void doublyLinkedList::display()
{
    DLLNode *temp = head;
    while (temp)
    {
        cout << temp->data << ", ";
        temp = temp->nextNode;
    }
    cout << endl
         << endl;
}
