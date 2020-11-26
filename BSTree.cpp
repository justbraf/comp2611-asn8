// BSTree.h
// Implementation of Binary Search Tree Class

#include "BSTree.h"

BSTNode* BSTree::insertHelper(BSTNode* ptr, int rankRec, string nameRec, string nationalityRec, int scoreRec, string opponentRec, int yearRec){
	if (ptr == nullptr){
		ptr = new BSTNode(rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec);
	}
	else {
		if (rankRec < ptr->getRank()){
			ptr->setLeftPtr(insertHelper(ptr->getLeftPtr(), rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec));
		}
		else {
			ptr->setRightPtr(insertHelper(ptr->getRightPtr(), rankRec, nameRec, nationalityRec, scoreRec, opponentRec, yearRec));
		}
	}
	return ptr;
}

BSTNode* BSTree::deleteHelper(BSTNode* ptr, int rankRec){
	BSTNode* successorPtr;

	// BST is empty
	if (ptr == nullptr){
		return nullptr;
	}

	if (rankRec > ptr->getRank()){
		ptr->setRightPtr(deleteHelper(ptr->getRightPtr(), rankRec));
	}
	else if (rankRec < ptr->getRank()){
		ptr->setLeftPtr(deleteHelper(ptr->getLeftPtr(), rankRec));
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
		}
		else {
			return ptr->getLeftPtr();
		}
	}
	return ptr;
}

void BSTree::purgeHelper(BSTNode* ptr){
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
		BSTNode* tmpPtr = ptr->getRightPtr();
		ptr->setRightPtr(nullptr);
		delete tmpPtr;
		if (ptr->getLeftPtr() != nullptr){
			purgeHelper(ptr->getLeftPtr());
		}
	}
	if (ptr->getLeftPtr() != nullptr){
		BSTNode* tmpPtr = ptr->getLeftPtr();
		ptr->setLeftPtr(nullptr);
		delete tmpPtr;
	}
	if (ptr == root){
		resetRoot();
		delete ptr;
	}
	return;
}

string BSTree::inorderHelper(BSTNode* ptr){
	string str = "";
	if (ptr != nullptr){
		str.append(inorderHelper(ptr->getLeftPtr()));
		str.append(ptr->getRecord());
		str.append("\n");
		str.append(inorderHelper(ptr->getRightPtr()));
	}
	return str;
}

string BSTree::preorderHelper(BSTNode* ptr){
	string str = "";
	if (ptr != nullptr){
		str.append(ptr->getRecord());
		str.append("\n");
		str.append(inorderHelper(ptr->getLeftPtr()));
		str.append(inorderHelper(ptr->getRightPtr()));
	}
	return str;
}

string BSTree::postorderHelper(BSTNode* ptr){
	string str = "";
	if (ptr != nullptr){
		str.append(inorderHelper(ptr->getLeftPtr()));
		str.append(inorderHelper(ptr->getRightPtr()));
		str.append(ptr->getRecord());
		str.append("\n");
	}
	return str;
}