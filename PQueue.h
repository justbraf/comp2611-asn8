// PQueue.h
// Declarartion of Priority Queue class

#ifndef PQUEUE_H
#define PQUEUE_H

#include "node.h"

class PQueue:public Node{
    private:
        Node* frontPtr = nullptr;
        Node* backPtr = nullptr;
    public:
        // Constructor functions
        PQueue():Node(){}
        PQueue(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum):Node(rnum, nstr, natstr, snum, oppstr, yrnum){}
        
        // Destructor function
        ~PQueue();

        //Accessor functions
        string showHead();
        string showTail();
        string showAll();

        // Mutator functions
        void enqueue(int, string, string, int, string, int);
        string dequeue();
};
#endif