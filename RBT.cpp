// RBT.cpp
// Implementation of Red-Black Tree class

#include "RBT.h"
// #include <string>

// using namespace std;

void RBTree::rotateLeft(RBTNode* ptr){
    RBTNode* rightChild = ptr->getRightPtr();
    ptr->setRightPtr(rightChild->getLeftPtr());
    if (rightChild->getLeftPtr() != nullptr)
        rightChild->getLeftPtr()->setParentPtr(ptr);
    rightChild->setParentPtr(ptr->getParentPtr());
    if (ptr == root)
        root = rightChild;
    else {
        if (ptr == ptr->getParentPtr()->getLeftPtr())
            ptr->getParentPtr()->setLeftPtr(rightChild);
         else
            ptr->getParentPtr()->setRightPtr(rightChild);
    }
    rightChild->setLeftPtr(ptr);
    ptr->setParentPtr(rightChild);
}

void RBTree::rotateRight(RBTNode* ptr){
    RBTNode* leftChild = ptr->getLeftPtr();
    ptr->setLeftPtr(leftChild->getRightPtr());
    if (leftChild->getRightPtr() != nullptr)
        leftChild->getRightPtr()->setParentPtr(ptr);
    leftChild->setParentPtr(ptr->getParentPtr());
    if (ptr == root)
        root = leftChild;
    else {
        if( ptr == ptr->getParentPtr()->getRightPtr())
            ptr->getParentPtr()->setRightPtr(leftChild);
         else
            ptr->getParentPtr()->setLeftPtr(leftChild);
        }
    leftChild->setRightPtr(ptr);
    ptr->setParentPtr(leftChild);
}

// void RBTree::fixUp(RBTNode*){}
// string RBTree::inOrderHelper(RBTNode*){}
// string RBTree::preOrderHelper(RBTNode*){}
// string RBTree::postOrderHelper(RBTNode*){}
// void RBTree::deleteNode(RBTNode*){}
// RBTNode* RBTree::findNode(int){}
// RBTNode* RBTree::getMinimum(RBTNode*){}
// RBTNode* RBTree::getSuccessor(RBTNode*){}
// string RBTree::showLevels();
// void RBTree::insert(int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){root = insertHelper(root, rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);}
// void RBTree::remove(int rankRec){root = deleteHelper(root, rankRec);} 