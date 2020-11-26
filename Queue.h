// queue.h
// Declarartion of Queue class

#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class Queue:public Node{
    private:
        Node* frontPtr = nullptr;
        Node* backPtr = nullptr;
    public:
        // Constructor functions
        Queue():Node(){}
        Queue(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum):Node(rnum, nstr, natstr, snum, oppstr, yrnum){}
        
        // Destructor function
        ~Queue();

        //Accessor functions
        string showHead();
        string showTail();
        string showAll();

        // Mutator functions
        void enqueue(int, string, string, int, string, int);
        string dequeue();
};
#endif