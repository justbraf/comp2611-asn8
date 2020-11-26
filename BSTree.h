// BSTree.h
// Declaration of Binary Search Tree Class

#ifndef BSTREE_H
#define BSTREE_H

#include "BSTNode.h"

class BSTree{
    private:
        BSTNode* root;
        BSTNode* insertHelper(BSTNode*, int, string, string, int, string, int);
        BSTNode* deleteHelper(BSTNode*, int);
        string inorderHelper(BSTNode*);
        string preorderHelper(BSTNode*);
        string postorderHelper(BSTNode*);
        void purgeHelper(BSTNode*);

    public:
        // constructor
        BSTree(){root = nullptr;}

        // deconstructor
        ~BSTree(){purgeHelper(root);}
        
        // assessor functions
        BSTNode* getRoot(){return root;}
        string inorder(){return inorderHelper(root);}
        string preorder(){return preorderHelper(root);}
        string postorder(){return postorderHelper(root);}

        // mutator functions
        void resetRoot(){root = nullptr;}
        void insert(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){root = insertHelper(root, rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);}
        void remove(int rankRec){root = deleteHelper(root, rankRec);}
};
#endif