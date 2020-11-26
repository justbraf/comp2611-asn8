// node.h
// Declaration of node class

#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node
{
    private:
        int rank;
        string name;
        string nationality;
        int score;
        string opponent;
        int year;
        Node* next;

    public:
        // Constructor functions
        Node();
        Node(int, string, string, int, string, int);
        
        //Accessor functions
        int getRank() { return rank; }
        string getName() { return name; }
        string getNationality(){ return nationality; }
        int getYear() { return year; }
        int getScore() { return score; }
        string getOpponent() { return opponent; }
        Node* getNext() { return next; }
        string getRecord();
        
        //Mutator functions
        void setRank(int num) { rank = num; }
        void setName(string str) { name = str; }
        void setnationality(string str) { nationality = str; }
        void setYear(int yr) { year = yr; }
        void setScore(int totscore) { score = totscore; }
        void setOpponent(string oppTeam){ opponent = oppTeam; }
        void setNext(Node* ptr) { next = ptr;}
};
#endif