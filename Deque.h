// Deque.h
// Declarartion of Deque class

#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"

class Deque:public Node{
    private:
        Node* frontPtr = nullptr;
        Node* backPtr = nullptr;
    public:
        // Constructor functions
        Deque():Node(){}
        Deque(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum):Node(rnum, nstr, natstr, snum, oppstr, yrnum){}
        
        // Destructor function
        ~Deque();

        //Accessor functions
        string showHead();
        string showTail();
        string showAll();

        // Mutator functions
        void push_front(int, string, string, int, string, int);
        void push_back(int, string, string, int, string, int);
        string pop_front();
        string pop_back();
};
#endif