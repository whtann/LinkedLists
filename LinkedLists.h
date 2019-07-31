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
    //constructor & destructor
    doublyLinkedList();
    ~doublyLinkedList();
    //functions
    void addNode();
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
    void addNode();
    void display();
};