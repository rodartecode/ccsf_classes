//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinarySearchTree.cpp */



#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
			getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
		+ getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}  // end getNumberOfNodesHelper

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr,
	BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}  // end if

		return subTreePtr;
	}  // end if
}  // end balancedAdd

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::randomAdd(BinaryNode<ItemType>* subTreePtr,
	BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		int random = rand();
		int child = random % 2;

		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

		if (child == 0)
		{
			rightPtr = randomAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = randomAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::sortedAdd(BinaryNode<ItemType>* subTreePtr,
	BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else if (subTreePtr->getItem() > newNodePtr->getItem())
	{
		BinaryNode<ItemType>* tempPtr = sortedAdd(subTreePtr->getLeftChildPtr(), newNodePtr);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		BinaryNode<ItemType>* tempPtr = sortedAdd(subTreePtr->getRightChildPtr(), newNodePtr);
		subTreePtr->setRightChildPtr(tempPtr);
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
{
	BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
	int leftHeight = getHeightHelper(leftPtr);
	int rightHeight = getHeightHelper(rightPtr);
	if (leftHeight > rightHeight)
	{
		subTreePtr->setItem(leftPtr->getItem());
		leftPtr = moveValuesUpTree(leftPtr);
		subTreePtr->setLeftChildPtr(leftPtr);
		return subTreePtr;
	}
	else
	{
		if (rightPtr != nullptr)
		{
			subTreePtr->setItem(rightPtr->getItem());
			rightPtr = moveValuesUpTree(rightPtr);
			subTreePtr->setRightChildPtr(rightPtr);
			return subTreePtr;
		}
		else
		{
			//this was a leaf!
			// value not important
			delete subTreePtr;
			return nullptr;
		}  // end if
	}  // end if
}  // end moveValuesUpTree

   /** Depth-first search of tree for item.
   @param subTreePtr  tree to search.
   @param target  target item to find.
   @param success  communicate to client we found it.
   @returns  A pointer to node containing the item. */
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
	const ItemType target,
	bool& success)
{
	if (subTreePtr == nullptr) // not found here
		return nullptr;

	if (subTreePtr->getItem() == target) // found it
	{
		subTreePtr = moveValuesUpTree(subTreePtr);
		success = true;
		return subTreePtr;
	}
	else
	{
		BinaryNode<ItemType>* targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr->setLeftChildPtr(targetNodePtr);
		if (!success) // no need to search right subTree
		{
			targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
			subTreePtr->setRightChildPtr(targetNodePtr);
		}  // end if

		return subTreePtr;
	}  // end if
}  // end removeValue

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr,
	const ItemType& target,
	bool& success) const
{
	if (treePtr == nullptr) // not found here
		return nullptr;

	if (treePtr->getItem() == target) // found it
	{
		success = true;
		return treePtr;
	}
	else
	{
		BinaryNode<ItemType>* targetNodePtr = findNode(treePtr->getLeftChildPtr(), target, success);
		if (!success) // no need to search right subTree
		{
			targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);
		}  // end if

		return targetNodePtr;
	}  // end if
}  // end findNode

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;

	// Copy tree nodes during a preorder traversal
	if (treePtr != nullptr)
	{
		// Copy node
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}  // end if

	return newTreePtr;
}  // end copyTree

template<class ItemType>
void BinarySearchTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}  // end if
}  // end destroyTree

   //////////////////////////////////////////////////////////////
   //      Protected Tree Traversal Sub-Section
   //////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}  // end if
}  // end preorder

template<class ItemType>
void BinarySearchTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}  // end if
}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	}  // end if
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem,
	const BinarySearchTree<ItemType>* leftTreePtr,
	const BinarySearchTree<ItemType>* rightTreePtr)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
		copyTree(rightTreePtr->rootPtr));
}  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	destroyTree(rootPtr);
}  // end destructor

   //////////////////////////////////////////////////////////////
   //      Public BinaryTreeInterface Methods Section
   //////////////////////////////////////////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}  // end isEmpty

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}  // end getHeight

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}  // end getNumberOfNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	destroyTree(rootPtr);
	rootPtr = nullptr;
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("getRootData() called with empty tree.");

	return rootPtr->getItem();
}  // end getRootData

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem)
{
	if (isEmpty())
		rootPtr = new BinaryNode<ItemType>(newItem, nullptr, nullptr);
	else
		rootPtr->setItem(newItem);
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = sortedAdd(rootPtr, newNodePtr);
	return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;
}  // end remove

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
	bool isSuccessful = false;
	BinaryNode<ItemType>* binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);

	if (isSuccessful)
		return binaryNodePtr->getItem();
	else
		throw NotFoundException("Entry not found in tree!");
}  // end getEntry

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
	bool isSuccessful = false;
	findNode(rootPtr, anEntry, isSuccessful);
	return isSuccessful;
}  // end contains

   //////////////////////////////////////////////////////////////
   //      Public Traversals Section
   //////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	preorder(visit, rootPtr);
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	inorder(visit, rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	postorder(visit, rootPtr);
}  // end postorderTraverse

   // End of implementation file.  To get this to compile on hills,
   // add definitions of template types we will use in this .cpp file.
   // (just strings and ints for now, add more types if desired)
template class BinaryNode<std::string>;
template class BinaryNode<int>;
template class BinarySearchTree<std::string>;
template class BinarySearchTree<int>;
template class BinarySearchTree<Person>;