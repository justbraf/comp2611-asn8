// BSTNode.h
// Declaration of Binary Search Tree Node Class

#ifndef BSTNODE_H
#define BSTNODE_H

#include <string>

using namespace std;

class BSTNode{
    private:
        int rank;
        string name;
        string nationality;
        int score;
        string opponent;
        int year;
        BSTNode* leftPtr;
        BSTNode* rightPtr;

    public:
        // constructor
        BSTNode(){
            rank = 0;
            name = "";
            nationality = "";
            score = 0;
            opponent = "";
            year = 0;
            leftPtr = rightPtr = nullptr;
        }
        BSTNode(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum){
            setRank(rnum);
            setName(nstr);
            setnationality(natstr);
            setScore(snum);
            setOpponent(oppstr);
            setYear(yrnum);
            leftPtr = rightPtr = nullptr;
        }

        // assessor functions
        int getRank() { return rank; }
        string getName() { return name; }
        string getNationality(){ return nationality; }
        int getYear() { return year; }
        int getScore() { return score; }
        string getOpponent() { return opponent; }
        BSTNode* getLeftPtr(){return leftPtr;}
        BSTNode* getRightPtr(){return rightPtr;}
        string getRecord(){return to_string(getRank()) + "\t" + getName() + "\t" + getNationality() + "\t" + to_string(getScore()) + "\t" + getOpponent() + "\t" + to_string(getYear());};

        // mutator functions
        void setRank(int num) { rank = num; }
        void setName(string str) { name = str; }
        void setnationality(string str) { nationality = str; }
        void setYear(int yr) { year = yr; }
        void setScore(int totscore) { score = totscore; }
        void setOpponent(string oppTeam){ opponent = oppTeam; }
        void setLeftPtr(BSTNode* lPtr){leftPtr = lPtr;}
        void setRightPtr(BSTNode* rPtr){rightPtr = rPtr;}
};
#endif