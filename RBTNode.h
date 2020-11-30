// RBTNode.h
// Declaration of Red-Black Tree Node class

#ifndef RBTNODE_H
#define RBTNODE_H

#include <string>

using namespace std;

class RBTNode{
	private:
		int rank;
        string name;
        string nationality;
        int score;
        string opponent;
        int year;
        int height;
        string colour;
        RBTNode* leftPtr;
        RBTNode* rightPtr;
        RBTNode* parentPtr;

	public:
		// constructor functions
		RBTNode(){
			rank = 0;
            name = "";
            nationality = "";
            score = 0;
            opponent = "";
            year = 0;
			leftPtr = rightPtr = parentPtr = nullptr;
			colour = "RED";
		}
		RBTNode(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum){
            setRank(rnum);
            setName(nstr);
            setnationality(natstr);
            setScore(snum);
            setOpponent(oppstr);
            setYear(yrnum);
            leftPtr = rightPtr = parentPtr = nullptr;
            colour = "RED";
        }

		// assessor functions
        int getRank() { return rank; }
        string getName() { return name; }
        string getNationality(){ return nationality; }
        int getYear() { return year; }
        int getScore() { return score; }
        string getOpponent() { return opponent; }
        RBTNode* getLeftPtr(){ return leftPtr; }
        RBTNode* getRightPtr(){ return rightPtr; }
        RBTNode* getParentPtr(){ return parentPtr; }
        string getColour(){ return colour;}
        string getRecord(){return to_string(getRank()) + "\t" + getName() + "\t" + getNationality() + "\t" + to_string(getScore()) + "\t" + getOpponent() + "\t" + to_string(getYear());};

        // mutator functions
        void setRank(int num) { rank = num; }
        void setName(string str) { name = str; }
        void setnationality(string str) { nationality = str; }
        void setYear(int yr) { year = yr; }
        void setScore(int totscore) { score = totscore; }
        void setOpponent(string oppTeam){ opponent = oppTeam; }
        void setLeftPtr(RBTNode* lPtr){ leftPtr = lPtr; }
        void setRightPtr(RBTNode* rPtr){ rightPtr = rPtr; }
        void setParentPtr(RBTNode* pPtr){ parentPtr = pPtr; }
        void setColour(string col){ colour = col;}
	
};

#endif