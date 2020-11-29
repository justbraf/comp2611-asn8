// AVLTree.h
// Declarartion of AVL Tree class

#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

class AVLTree{
    private:
        AVLNode* root;
        AVLNode* insertHelper(AVLNode*, int, string, string, int, string, int);
        AVLNode* deleteHelper(AVLNode*, int);
        string inorderHelper(AVLNode*);
        string preorderHelper(AVLNode*);
        string postorderHelper(AVLNode*);
        AVLNode* rotateRight(AVLNode*);
        AVLNode* rotateLeft(AVLNode*);
        AVLNode* rotateDoubleRight(AVLNode*);
        AVLNode* rotateDoubleLeft(AVLNode*);
        AVLNode* rotateLeftRight(AVLNode*);
        AVLNode* rotateRightLeft(AVLNode*);
        int calcHeight(AVLNode*);
        int calcBalance(AVLNode*);
        void purgeHelper(AVLNode*);

    public:
        // constructor
        AVLTree(){root = nullptr;}

        // deconstructor
        ~AVLTree(){purgeHelper(root);}
        
        // assessor functions
        AVLNode* getRoot(){return root;}
        string inorder(){return inorderHelper(root);}
        string preorder(){return preorderHelper(root);}
        string postorder(){return postorderHelper(root);}

        // mutator functions
        void resetRoot(){root = nullptr;}
        void insert(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){root = insertHelper(root, rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);}
        void remove(int rankRec){root = deleteHelper(root, rankRec);}
};
#endif