#include "LinkedLists.h"

int main()
{
    doublyCircularLinkedList myList;
    int choice;
    cout << endl;
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
doublyCircularLinkedList::doublyCircularLinkedList()
{
    head = nullptr;
    count = 0;
}

//destructor
doublyCircularLinkedList::~doublyCircularLinkedList()
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
        count = 0;
    }
}

//member function for adding numbers to the end of the list
void doublyCircularLinkedList::pushBack()
{
    if (!head)
    {
        head = new DLLNode;
        head->previousNode = head;
        cout << "ENTER Doubly Circular LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = head;
        count = 1;
    }
    else
    {
        DLLNode *temp = head;
        int pos = 0;
        while (temp->nextNode && pos < count - 1)
        {
            temp = temp->nextNode;
            pos++;
        }
        temp->nextNode = new DLLNode;
        temp->nextNode->previousNode = temp;
        cout << "ENTER Doubly Circular LL #: ";
        cin >> temp->nextNode->data;
        cout << endl;
        temp->nextNode->nextNode = head;
        head->previousNode = temp->nextNode;
        count++;
    }
}

void doublyCircularLinkedList::pushFront()
{
    if (!head)
    {
        head = new DLLNode;
        head->previousNode = nullptr;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = nullptr;
        count = 1;
    }
    else
    {
        DLLNode *temp = head;
        head = new DLLNode;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
        cout << endl;
        head->nextNode = temp;
        temp->previousNode = head;
        int pos = 0;
        while (temp->nextNode && pos < count - 1)
        {
            temp = temp->nextNode;
            pos++;
        }
        head->previousNode = temp;
        temp->nextNode = head;
        count++;
    }
}

void doublyCircularLinkedList::display()
{
    DLLNode *temp = head;
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

void doublyCircularLinkedList::displayLoop()
{
    DLLNode *temp = head;
    int pos = 0;
    while (temp && pos < (count * 2))
    {
        cout << temp->data << ", ";
        temp = temp->nextNode;
        pos++;
    }
    cout << endl
         << "Printing backwards" << endl;
    //resetting node to previous node
    temp = temp->previousNode;
    while (temp && pos > 0)
    {
        cout << temp->data << ", ";
        temp = temp->previousNode;
        pos--;
    }

    cout << endl
         << endl;
}