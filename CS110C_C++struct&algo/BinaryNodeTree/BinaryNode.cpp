//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinaryNode.cpp */

#include "BinaryNode.h"
#include <cstddef>
#include <string>

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}  // end constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr,
                             BinaryNode<ItemType>* rightPtr) : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}  // end constructor

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
}  // end setItem

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const 
{
   return item;
}  // end getItem

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) 
{
   leftChildPtr = leftPtr;
}  // end setLeftChildPtr

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) 
{
   rightChildPtr = rightPtr;
}  // end setRightChildPtr

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
   return leftChildPtr;
}  // end getLeftChildPtr		

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
   return rightChildPtr;
}  // end getRightChildPtr		

// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use in this .cpp file.
// (just strings and ints for now, add more types if desired)
template class BinaryNode<std::string>;
template class BinaryNode<int>;


