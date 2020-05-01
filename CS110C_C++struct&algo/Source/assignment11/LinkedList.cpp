//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
@file LinkedList.cpp */



#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
	headPtr = nullptr;
	itemCount = 0;
	tailPtr = nullptr;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
	Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original list is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
		origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item 
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Link new node to end of new chain
			newNodePtr->setPrev(newChainPtr);

			// Advance pointer to new last node      
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while

		newChainPtr->setNext(nullptr);              // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		// Create a new node containing the new entry 
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		// Insert to first position. Set new node 'next' pointer to headPtr.
		// Set headPtr 'prev' to point back to the new first node. headPtr 
		// is set to point to the new first node.	  
		if (newPosition == 1)
		{
			if (isEmpty())
			{
				// headPtr points to new head
				headPtr = newNodePtr;
				// tailPtr points to new tail
				tailPtr = newNodePtr;

			}
			else
			{
				// old head and new head point to each other
				newNodePtr->setNext(headPtr);
				headPtr->setPrev(newNodePtr);
				// headPtr points to new head
				headPtr = newNodePtr;
			}


		}

		// Insert to last position. Set new node 'prev' pointer to tailPtr.
		// Set tailPtr to point ahead to new last node. Set tailPtr to 
		// point to new last node.
		else if (newPosition == itemCount + 1)
		{
			// old tail and new tail point to each other
			newNodePtr->setPrev(tailPtr);
			tailPtr->setNext(newNodePtr);
			// tail points to new tail
			tailPtr = newNodePtr;
		}
		else
		{
			// Create pointers to next and previous entries
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			Node<ItemType>* currPtr = getNodeAt(newPosition);

			// Current newPosition entry's prev ptr now points to new node
			currPtr->setPrev(newNodePtr);
			// New Node points backwards and forwards to old entries
			newNodePtr->setNext(currPtr);
			newNodePtr->setPrev(prevPtr);
			// Previous entry's 'next' pointer now points to new node
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;  // Increase count of entries
	}  // end if

	return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::insert(const ItemType& newEntry)
{
	bool ableToInsert = true;
	if (ableToInsert)
	{
		// Create a new node containing the new entry 
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		// Insert to first position. Set new node 'next' pointer to headPtr.
		// Set headPtr 'prev' to point back to the new first node. headPtr 
		// is set to point to the new first node.	  
		if (isEmpty())
		{
			// headPtr points to new head				
			headPtr = newNodePtr;
			// tailPtr points to new tail				
			tailPtr = newNodePtr;
		}
		else
		{
			// old head and new head point to each other				
			newNodePtr->setNext(headPtr);
			headPtr->setPrev(newNodePtr);
			// headPtr points to new head				
			headPtr = newNodePtr;
		}
	}
	itemCount++;
	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
			headPtr->setPrev(nullptr);
		}
		else if (position == this->getLength())
		{
			//Remove the last node in the chain
			curPtr = tailPtr;
			tailPtr = tailPtr->getPrev();
			tailPtr->setNext(nullptr);
		}
		else
		{
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Find node that is after the one to delete
			Node<ItemType>* nextPtr = getNodeAt(position + 1);

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(nextPtr);
			nextPtr->setPrev(prevPtr);

		}  // end if

		   // Return node to system
		curPtr->setNext(nullptr);
		curPtr->setPrev(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;  // Decrease count of entries
	}  // end if

	return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	}  // end if
}  // end getEntry

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& newEntry)
{
	bool result = false;

	for (int i = 1; i <= this->getLength(); i++)
	{
		if (getEntry(i) == newEntry)
			return true;
	}

	return false;
}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	// Enforce precondition
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		string message = "setEntry() called with an invalid position.";
		throw(PrecondViolatedExcep(message));
	}  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}  // end getNodeAt


template<class ItemType>
void LinkedList<ItemType>::reverse()
{

	Node<ItemType>* curPtr = headPtr;
	headPtr = tailPtr;
	tailPtr = curPtr;

	for (int i = 1; i <= this->getLength(); i++)
	{
		if (i == 1)
		{
			curPtr->setPrev(curPtr->getNext());
			curPtr->setNext(nullptr);
			curPtr = curPtr->getPrev();
		}
		else if (i == this->getLength())
		{
			curPtr->setNext(curPtr->getPrev());
			curPtr->setPrev(nullptr);
		}
		else
		{
			Node<ItemType>* nxtPtr = curPtr->getNext();
			curPtr->setNext(curPtr->getPrev());
			curPtr->setPrev(nxtPtr);
			curPtr = curPtr->getPrev();
		}
	}
}

// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;
