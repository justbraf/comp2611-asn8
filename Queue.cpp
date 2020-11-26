// queue.cpp
// Implementation of Queue class

#include "Queue.h"

// Constructor functions
// Queue::Queue():Node();
// Queue::Queue(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum):Node(rnum, nstr, natstr, snum, oppstr, yrnum){}

// Destructor function
Queue::~Queue(){
    while (frontPtr != nullptr) {
        Node* tmpPtr = frontPtr;
        frontPtr = frontPtr->getNext();
        delete tmpPtr;
    }
}

// Accessor functions
string Queue::showHead(){
    if (frontPtr == nullptr) {
        return "Queue is empty";
    }
    return frontPtr->getRecord();
}
string Queue::showTail(){
    if (backPtr == nullptr) {
        return "Queue is empty";
    }
    return backPtr->getRecord();
}
string Queue::showAll(){
    if (frontPtr == nullptr) {
        return "Queue is empty";
    }
    string records;
    Node* tmpPtr = frontPtr;
    // cycle through all pointers until the end is reached
    while (tmpPtr != nullptr){
        records += tmpPtr->getRecord() + "\n";
        tmpPtr = tmpPtr->getNext();
    }
    return records;
}

// Mutator functions
void Queue::enqueue(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
    // check if the queue is full
    if (frontPtr - 1 == backPtr && frontPtr != nullptr){
        __throw_out_of_range("Queue is full");
    }
    // create a new node with record data
    Node* newPtr = new Node(rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);
    // if front pointer is null then so is back pointer. Add the first record
    if (frontPtr == nullptr){
        frontPtr = newPtr;
        backPtr = newPtr;
    }
    // insert new record at the back
    else {
        backPtr->setNext(newPtr);
        backPtr = newPtr;
    }
    
}
string Queue::dequeue(){
    if (frontPtr == nullptr) {
        return "Queue is empty";
    }
    Node* tmpPtr = frontPtr;
    frontPtr = frontPtr->getNext();
    if (frontPtr == nullptr){
        backPtr = frontPtr;
    }
    string record = tmpPtr->getRecord();
    delete tmpPtr;
    return record;
}