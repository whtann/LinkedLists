#include "LinkedLists.h"

int main()
{
    singlyLinkedList myList;
    myList.addNode();
    myList.addNode();
    myList.display();
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