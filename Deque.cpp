// Deque.cpp
// Implementation of Deque class

#include "Deque.h"

// Destructor function
Deque::~Deque(){
    while (frontPtr != nullptr) {
        Node* tmpPtr = frontPtr;
        frontPtr = frontPtr->getNext();
        delete tmpPtr;
    }
}

// Accessor functions
string Deque::showHead(){
    if (frontPtr == nullptr) {
        return "Deque is empty";
    }
    return frontPtr->getRecord();
}
string Deque::showTail(){
    if (backPtr == nullptr) {
        return "Deque is empty";
    }
    return backPtr->getRecord();
}
string Deque::showAll(){
    if (frontPtr == nullptr) {
        return "Deque is empty";
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
void Deque::push_front(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
    // check if the Deque is full
    if (frontPtr - 1 == backPtr && frontPtr != nullptr){
        __throw_out_of_range("Deque is full");
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
        newPtr->setNext(frontPtr);
        frontPtr = newPtr;
    }
    
}
void Deque::push_back(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
    // check if the Deque is full
    if (frontPtr - 1 == backPtr && frontPtr != nullptr){
        __throw_out_of_range("Deque is full");
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
string Deque::pop_front(){
    if (frontPtr == nullptr) {
        return "Deque is empty";
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
string Deque::pop_back(){
    if (backPtr == nullptr) {
        return "Deque is empty";
    }
    string record = backPtr->getRecord();
    if (frontPtr == backPtr){
        delete backPtr;
        backPtr = frontPtr = nullptr;
    }
    else {
        Node* tmpPtr = frontPtr;
        while (tmpPtr->getNext() != backPtr){
            tmpPtr = tmpPtr->getNext();
        }
        tmpPtr->setNext(nullptr);
        delete backPtr;
        backPtr = tmpPtr;
    }
    return record;
}