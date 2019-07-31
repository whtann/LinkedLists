#include "LinkedLists.h"

int main()
{
    singlyCircularLinkedList myList;
    myList.addNode();
    myList.addNode();
    myList.display();
}

singlyCircularLinkedList::singlyCircularLinkedList()
{
    head = nullptr;
    count = 0;
}

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

void singlyCircularLinkedList::addNode()
{
    if (!head)
    {
        head = new SLLNode;
        cout << "ENTER Singly LL #: ";
        cin >> head->data;
        head->nextNode = nullptr;
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
        cout << "ENTER Singly LL #: ";
        cin >> temp->data;
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
    }
    cout << endl;
}