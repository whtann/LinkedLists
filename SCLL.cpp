#include "LinkedLists.h"

int main()
{
    singlyCircularLinkedList myList;
    int choice;
    while (1)
    {
        //menu
        cout << "SIMPLE LINKED LIST" << endl
             << "MENU" << endl
             << "---------------" << endl;
        cout << "1. Display" << endl
             << "2. Push Front" << endl
             << "3. Push Back" << endl
             << "4. Display Loop" << endl
             << "5. Exit" << endl;
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
                myList.displayLoop();
                break;
            case 5:
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
singlyCircularLinkedList::singlyCircularLinkedList()
{
    head = nullptr;
    count = 0;
}

//destructor
singlyCircularLinkedList::~singlyCircularLinkedList()
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
        count = 0;
    }
}

//member function for adding numbers to the end of the list
void singlyCircularLinkedList::pushBack()
{
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly Circular LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = head;
        count = 1;
    }
    else
    {
        SLLNode *temp = head;
        int pos = 0;
        while (temp->nextNode && pos < count)
        {
            temp = temp->nextNode;
            pos++;
        }
        temp->nextNode = new SLLNode;
        temp = temp->nextNode;
        cout << "ENTER Singly Circular LL #: ";
        cin >> temp->data;
        cout << endl;
        temp->nextNode = head;
        count++;
    }
}

void singlyCircularLinkedList::pushFront()
{
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly Circular LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = head;
        count = 1;
    }
    else
    {
        SLLNode *temp = head;
        head = new SLLNode;
        cout << "ENTER Singly Circular LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = temp;
        int pos = 0;
        while (temp->nextNode && pos < count)
        {
            temp = temp->nextNode;
            pos++;
        }
        temp->nextNode = head;
        count++;
    }
}

void singlyCircularLinkedList::display()
{
    SLLNode *temp = head;
    int pos = 0;
    while (temp && pos < count)
    {
        cout << temp->data << ", ";
        temp = temp->nextNode;
        pos++;
    }
    cout << endl
         << endl;
}

void singlyCircularLinkedList::displayLoop()
{
    SLLNode *temp = head;
    int pos = 0;
    while (temp && pos < (count * 2))
    {
        cout << temp->data << ", ";
        temp = temp->nextNode;
        pos++;
    }
    cout << endl
         << endl;
}