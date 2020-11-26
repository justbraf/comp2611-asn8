// Stack.cpp
// Implementation of Stack class

#include "Stack.h"

// Destructor function
Stack::~Stack(){
    while (frontPtr != nullptr) {
        Node* tmpPtr = frontPtr;
        frontPtr = frontPtr->getNext();
        delete tmpPtr;
    }
}

// Accessor functions
string Stack::showAll(){
    if (frontPtr == nullptr) {
        return "Stack is empty";
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
void Stack::push(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
    // create a new node with record data
    Node* newPtr = new Node(rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);
    // if front pointer is null then add the first record
    if (frontPtr == nullptr){
        frontPtr = newPtr;
    }
    // insert new record at the front
    else {
        newPtr->setNext(frontPtr);
        frontPtr = newPtr;
    }
    
}
string Stack::pop(){
    if (frontPtr == nullptr) {
        return "Stack is empty";
    }
    Node* tmpPtr = frontPtr;
    frontPtr = frontPtr->getNext();
    string record = tmpPtr->getRecord();
    delete tmpPtr;
    return record;
}