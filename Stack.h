// Stack.h
// Declarartion of Stack class

#ifndef STACK_H
#define STACK_H

#include "node.h"

class Stack:public Node{
    private:
        Node* frontPtr = nullptr;
    public:
        // Constructor functions
        Stack():Node(){}
        Stack(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum):Node(rnum, nstr, natstr, snum, oppstr, yrnum){}
        
        // Destructor function
        ~Stack();

        //Accessor functions
        string showAll();

        // Mutator functions
        void push(int, string, string, int, string, int);
        string pop();
};
#endif