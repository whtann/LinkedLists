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
    void pushBack();
    void pushFront();
    void display();
};

class singlyCircularLinkedList
{
private:
    SLLNode *head;
    int count;

public:
    //constructors & destructor
    singlyCircularLinkedList();
    ~singlyCircularLinkedList();
    //functions
    void pushBack();
    void pushFront();
    void displayLoop();
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
    //constructor & destructor
    doublyLinkedList();
    ~doublyLinkedList();
    //functions
    void pushBack();
    void pushFront();
    void display();
};

class doublyCircularLinkedList
{
private:
    DLLNode *head;
    int count;

public:
    //constructor & destructor
    doublyCircularLinkedList();
    ~doublyCircularLinkedList();
    //functions
    void pushBack();
    void pushFront();
    void displayLoop();
    void display();
};