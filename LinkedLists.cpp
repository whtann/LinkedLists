#include "LinkedLists.h"

int main()
{
    singlyLinkedList myList;
    myList.addNode();
    myList.addNode();
    myList.display();
    doublyLinkedList myDLList;
    myDLList.addNode();
    myDLList.addNode();
    myDLList.display();
    return 0;
}

singlyLinkedList::singlyLinkedList()
{
    head = nullptr;
}

singlyLinkedList::~singlyLinkedList()
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

void singlyLinkedList::addNode()
{
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
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
        temp->nextNode = nullptr;
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
    cout << endl;
}

doublyLinkedList::doublyLinkedList()
{
    head = nullptr;
}

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

void doublyLinkedList::addNode()
{
    if (!head)
    {
        head = new DLLNode;
        head->previousNode = nullptr;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
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
        temp->nextNode->nextNode = nullptr;
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
    cout << endl;
}