#include "LinkedLists.h"

int main()
{
    singlyLinkedList myList;
    int choice;
    while (1)
    {
        //menu
        cout << "SINGLY LINKED LIST" << endl
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
singlyLinkedList::singlyLinkedList()
{
    head = nullptr;
}

//destructor
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

//member function for adding numbers to the end of the list
void singlyLinkedList::pushBack()
{
    //if the list doesn't exist, create it
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
    }
    //if the list does exist add a node to the end of the list
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

//member function for adding numbers to the beginning of the list
void singlyLinkedList::pushFront()
{
    //if the list doesn't exist, create it
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
    }
    //if the list does exist add a node to the beginning of the list
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

//member function for displaying the numbers in the list
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