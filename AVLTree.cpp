// AVLTree.cpp
// Implementation of AVL Tree class

#include "AVLTree.h"

AVLNode* AVLTree::insertHelper(AVLNode* ptr, int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
    if (ptr == nullptr){
        ptr = new AVLNode(rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);
    }
    else {
        if (rankRec >= ptr->getRank()) {
            ptr->setRightPtr(insertHelper(ptr->getRightPtr(), rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec));
            if (calcBalance(ptr) == -2){
                if(rankRec > ptr->getRightPtr()->getRank())
                    ptr = rotateDoubleRight(ptr);
                else
                    ptr = rotateRightLeft(ptr);
            }
        }
        else {
            ptr->setLeftPtr(insertHelper(ptr->getLeftPtr(), rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec));
            if (calcBalance(ptr) == 2){
                if(rankRec < ptr->getLeftPtr()->getRank())
                    ptr = rotateDoubleLeft(ptr);
                else
                    ptr = rotateLeftRight(ptr);
            }
        }
        
    }
    ptr->setHeight(calcHeight(ptr));
    return ptr;
}

AVLNode* AVLTree::deleteHelper(AVLNode* ptr, int rankRec){
    AVLNode* successorPtr;

    // AVL is empty
    if (ptr == nullptr){
        return nullptr;
    }

    if (rankRec > ptr->getRank()){
        ptr->setRightPtr(deleteHelper(ptr->getRightPtr(), rankRec));
        if (calcBalance(ptr) == 2){
            if(calcBalance(ptr->getLeftPtr()) >= 0)
                ptr = rotateDoubleLeft(ptr);
            else
                ptr = rotateLeftRight(ptr);
        }
    }
    else if (rankRec < ptr->getRank()){
        ptr->setLeftPtr(deleteHelper(ptr->getLeftPtr(), rankRec));
        if (calcBalance(ptr) == -2){
            if(calcBalance(ptr->getRightPtr()) <= 0)
                ptr = rotateDoubleRight(ptr);
            else
                ptr = rotateRightLeft(ptr);
        }
    }
    else {
        if (ptr->getRightPtr() != nullptr){
            successorPtr = ptr->getRightPtr();
            while (successorPtr->getLeftPtr() != nullptr){
                successorPtr = successorPtr->getLeftPtr();
            }
            //copy record from successor to ptr
            ptr->setRank(successorPtr->getRank());
            ptr->setName(successorPtr->getName());
            ptr->setnationality(successorPtr->getNationality());
            ptr->setScore(successorPtr->getScore());
            ptr->setOpponent(successorPtr->getOpponent());
            ptr->setYear(successorPtr->getYear());
            ptr->setRightPtr(deleteHelper(ptr->getRightPtr(), ptr->getRank()));
            if (calcBalance(ptr) == 2){
                if(calcBalance(ptr->getLeftPtr()) >= 0)
                    ptr = rotateDoubleLeft(ptr);
                else
                    ptr = rotateLeftRight(ptr);
            }
        }
        else {
            return ptr->getLeftPtr();
        }
    }
    ptr->setHeight(calcHeight(ptr));
    return ptr;
}

string AVLTree::inorderHelper(AVLNode* ptr){
    string str = "";
    if (ptr != nullptr){
        str.append(inorderHelper(ptr->getLeftPtr()));
        str.append(ptr->getRecord());
        str.append("\n");
        str.append(inorderHelper(ptr->getRightPtr()));
    }
    return str;
}

string AVLTree::preorderHelper(AVLNode* ptr){
    string str = "";
    if (ptr != nullptr){
        str.append(ptr->getRecord());
        str.append("\n");
        str.append(inorderHelper(ptr->getLeftPtr()));
        str.append(inorderHelper(ptr->getRightPtr()));
    }
    return str;
}

string AVLTree::postorderHelper(AVLNode* ptr){
    string str = "";
    if (ptr != nullptr){
        str.append(inorderHelper(ptr->getLeftPtr()));
        str.append(inorderHelper(ptr->getRightPtr()));
        str.append(ptr->getRecord());
        str.append("\n");
    }
    return str;
}

AVLNode*  AVLTree::rotateRight(AVLNode* ptr){
    AVLNode* newParent;
    newParent = ptr->getLeftPtr();
    ptr->setLeftPtr(newParent->getRightPtr());
    newParent->setRightPtr(ptr);
    ptr->setHeight(calcHeight(ptr));
    newParent->setHeight(calcHeight(newParent));
    return (newParent);
}

AVLNode*  AVLTree::rotateLeft(AVLNode* ptr){
    AVLNode* newParent;
    newParent = ptr->getRightPtr();
    ptr->setRightPtr(newParent->getLeftPtr());
    newParent->setLeftPtr(ptr);
    ptr->setHeight(calcHeight(ptr));
    newParent->setHeight(calcHeight(newParent));
    return (newParent);
}

AVLNode*  AVLTree::rotateDoubleRight(AVLNode* ptr){
    ptr = rotateLeft(ptr);
    return(ptr);
}

AVLNode*  AVLTree::rotateDoubleLeft(AVLNode* ptr){
    ptr = rotateRight(ptr);
    return(ptr);
}

AVLNode*  AVLTree::rotateLeftRight(AVLNode* ptr){
    ptr->setLeftPtr(rotateLeft(ptr->getLeftPtr()));
    ptr = rotateRight(ptr);
    return(ptr);
}

AVLNode*  AVLTree::rotateRightLeft(AVLNode* ptr){
    ptr->setRightPtr(rotateRight(ptr->getRightPtr()));
    ptr = rotateLeft(ptr);
    return(ptr);
}

int AVLTree::calcHeight(AVLNode* ptr){
    int leftHeight, rightHeight;
    if( ptr == NULL)
        return(0);    
    if(ptr->getLeftPtr() == NULL)
        leftHeight = 0;
    else
        leftHeight = 1 + ptr->getLeftPtr()->getHeight();    
    if(ptr->getRightPtr() == NULL)
        rightHeight = 0;
    else
        rightHeight = 1 + ptr->getRightPtr()->getHeight();
    if(leftHeight > rightHeight)
        return(leftHeight);
    return(rightHeight);
}

int AVLTree::calcBalance(AVLNode* ptr){
    int leftHeight, rightHeight;
    if(ptr == NULL)
        return (0);
    if(ptr->getLeftPtr() == NULL)
        leftHeight = 0;
    else
        leftHeight = 1 + ptr->getLeftPtr()->getHeight();
    if(ptr->getRightPtr() == NULL)
        rightHeight = 0;
    else
        rightHeight = 1 + ptr->getRightPtr()->getHeight();
    return(leftHeight - rightHeight);
}

void AVLTree::purgeHelper(AVLNode* ptr){
    if (ptr == nullptr){
        return;
    }

    if (ptr->getRightPtr() != nullptr){
        purgeHelper(ptr->getRightPtr());
    }
    else if (ptr->getLeftPtr() != nullptr){
        purgeHelper(ptr->getLeftPtr());
    }
    else {
        return;
    }
    if (ptr->getRightPtr() != nullptr){
        AVLNode* tmpPtr = ptr->getRightPtr();
        ptr->setRightPtr(nullptr);
        delete tmpPtr;
        if (ptr->getLeftPtr() != nullptr){
            purgeHelper(ptr->getLeftPtr());
        }
    }
    if (ptr->getLeftPtr() != nullptr){
        AVLNode* tmpPtr = ptr->getLeftPtr();
        ptr->setLeftPtr(nullptr);
        delete tmpPtr;
    }
    if (ptr == root){
        resetRoot();
        delete ptr;
    }
    return;
}