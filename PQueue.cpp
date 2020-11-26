// PQueue.cpp
// Implementation of Priority Queue class

#include "PQueue.h"

// Destructor function
PQueue::~PQueue(){
    while (frontPtr != nullptr) {
        Node* tmpPtr = frontPtr;
        frontPtr = frontPtr->getNext();
        delete tmpPtr;
    }
}

// Accessor functions
string PQueue::showHead(){
    if (frontPtr == nullptr) {
        return "Priority Queue is empty";
    }
    return frontPtr->getRecord();
}
string PQueue::showTail(){
    if (backPtr == nullptr) {
        return "Priority Queue is empty";
    }
    return backPtr->getRecord();
}
string PQueue::showAll(){
    if (frontPtr == nullptr) {
        return "Priority Queue is empty";
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
void PQueue::enqueue(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
    // check if the Pqueue is full
    if (frontPtr - 1 == backPtr && frontPtr != nullptr){
        __throw_out_of_range("Priority Queue is full");
    }
    // create a new node with record data
    Node* newPtr = new Node(rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);
    // if front pointer is null then so is back pointer. Add the first record
    if (frontPtr == nullptr){
        frontPtr = newPtr;
        backPtr = newPtr;
    }
    else {
        // insert new record at the front if it's less than and equal to the front->rank
        if (frontPtr->getRank() > newPtr->getRank()){
            newPtr->setNext(frontPtr);
            frontPtr = newPtr;
        }
        else {
            // insert new record in order based on its rank
            Node* tmpPtr = frontPtr;
            if (tmpPtr->getNext() == nullptr){
                tmpPtr->setNext(newPtr);
            }
            else {
                while (tmpPtr->getNext() != nullptr){
                    if (tmpPtr->getNext()->getRank() <= newPtr->getRank()){
                        tmpPtr = tmpPtr->getNext();
                    }
                    else {
                        break;
                    }
                }
                
                newPtr->setNext(tmpPtr->getNext());
                tmpPtr->setNext(newPtr);
                while (tmpPtr->getNext() != nullptr){
                    tmpPtr = tmpPtr->getNext();
                }
                backPtr = tmpPtr;
            }
        }
    }
    
}
string PQueue::dequeue(){
    if (frontPtr == nullptr) {
        return "Priority Queue is empty";
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