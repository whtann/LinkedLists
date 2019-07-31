#include "LinkedLists.h"

int main()
{
    doublyLinkedList myDLList;
    myDLList.addNode();
    myDLList.addNode();
    myDLList.display();
    return 0;
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
