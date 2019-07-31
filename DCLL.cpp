#include "LinkedLists.h"

int main()
{
    doublyCircularLinkedList myDLList;
    myDLList.addNode();
    myDLList.addNode();
    myDLList.display();
    return 0;
}

doublyCircularLinkedList::doublyCircularLinkedList()
{
    head = nullptr;
    count = 0;
}

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

void doublyCircularLinkedList::addNode()
{
    if (!head)
    {
        head = new DLLNode;
        head->previousNode = nullptr;
        cout << "ENTER Doubly LL #: ";
        cin >> head->data;
        head->nextNode = nullptr;
        count = 1;
    }
    else
    {
        DLLNode *temp = head;
        int pos = 0;
        while (temp->nextNode && pos < count)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = new DLLNode;
        temp->nextNode->previousNode = temp;
        cout << "ENTER Doubly LL #: ";
        cin >> temp->nextNode->data;
        temp->nextNode->nextNode = head;
        head->previousNode = temp->nextNode;
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
    }
    cout << endl;
}