// node.cpp
// Implementation of node class

#include "node.h"

// constructor functions
Node::Node(){}
Node::Node(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum){
    setRank(rnum);
    setName(nstr);
    setnationality(natstr);
    setScore(snum);
    setOpponent(oppstr);
    setYear(yrnum);
    setNext(nullptr);
}

// Accessor functions
string Node::getRecord(){
    return to_string(getRank()) + "\t" + getName() + "\t" + getNationality() + "\t" + to_string(getScore()) + "\t" + getOpponent() + "\t" + to_string(getYear());
}