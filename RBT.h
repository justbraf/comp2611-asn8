// RBT.h
// Declaration of Red-Black Tree class

#ifndef RBT_H
#define RBT_H

#include "RBTNode.h"
// #include <string>

// using namespace std;

class RBTree{
    private:
        RBTNode* root;
        void rotateLeft( RBTNode*);
        void rotateRight(RBTNode*);
        // void fixUp(RBTNode*);
        // string inorderHelper(RBTNode*);
        // string preorderHelper(RBTNode*);
        // string postorderHelper(RBTNode*);
        // void deleteHelper(RBTNode*);
        // RBTNode* findNode(int);
        // RBTNode* getMinimum(RBTNode*);
        // RBTNode* getSuccessor(RBTNode*);

    public:
        // constructor function
        RBTree(){ root = nullptr; }

        // deconstructor
        // ~RBT();

        // assessor functions
        // RBTNode* getRoot(){return root;}
        // string inorder(){return inorderHelper(root);}
        // string preorder(){return preorderHelper(root);}
        // string postorder(){return postorderHelper(root);}
        // string showLevels();

        // mutator functions
        // void insert(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){root = insertHelper(root, rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);}
        // void remove(int rankRec){root = deleteHelper(root, rankRec);}    
};

#endif