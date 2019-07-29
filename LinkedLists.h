#include <iostream>

using namespace std;

struct SLLNode
{
    int data;
    SLLNode *nextNode;
};

class singlyLinkedList
{
private:
    SLLNode *head;

public:
    //constructors & destructor
    singlyLinkedList();
    ~singlyLinkedList();
    //functions
    void addNode();
    void display();
};

struct DLLNode
{
    DLLNode *previousNode;
    int data;
    DLLNode *nextNode;
};

class doublyLinkedList
{
private:
    DLLNode *head;

public:
    //constructors & destructor
    doublyLinkedList();
    ~doublyLinkedList();
    //functions
    void addNode();
    void display();
};