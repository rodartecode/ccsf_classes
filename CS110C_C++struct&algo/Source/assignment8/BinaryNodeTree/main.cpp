//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

void display(string& anItem)
{
	cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
	if (success)
		cout << "Done." << endl;
	else
		cout << " Entry not in tree." << endl;
}  // end check

int main()
{
	srand(time(0));
	BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();

	BinaryTreeInterface<string>* tree2 = new BinaryNodeTree<string>();

	tree1->add("10");
	tree1->add("20");
	tree1->add("30");
	tree1->add("40");
	tree1->add("50");
	tree1->add("60");
	tree1->add("70");
	tree1->add("80");

	tree2->add("10");
	tree2->add("20");
	tree2->add("30");
	tree2->add("40");
	tree2->add("50");
	tree2->add("60");
	tree2->add("70");
	tree2->add("80");

	cout << "Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80\n";
	tree1->preorderTraverse(display);

	cout << "Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80\n";
	tree1->inorderTraverse(display);

	cout << "Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10\n";
	tree1->postorderTraverse(display);

	cout << "Tree 1 height: " << tree1->getHeight() << endl;
	cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;

	cout << "Remove the leaf 80: ";
	bool success = tree1->remove("80");
	check(success);

	cout << "Try to remove the leaf 80 again: ";
	success = tree1->remove("80");
	check(success);

	cout << "Tree 2 Preorder: \n";
	tree2->preorderTraverse(display);

	cout << "Tree 2 Inorder: \n";
	tree2->inorderTraverse(display);

	cout << "Tree 2 Postorder: \n";
	tree2->postorderTraverse(display);

	cout << "Tree 2 height: " << tree2->getHeight() << endl;
	cout << "Tree 2 number of nodes: " << tree2->getNumberOfNodes() << endl;

	cout << "Remove the node 40 in Tree 1: ";
	success = tree1->remove("40");
	check(success);

	cout << "Tree 1 Preorder: Should be 10 20 70 60 30\n";
	tree1->preorderTraverse(display);

	cout << "Tree 1 Inorder: Should be 70 20 60 10 30\n";
	tree1->inorderTraverse(display);

	cout << "Tree 1 Postorder: Should be 70 60 20 30 10\n";
	tree1->postorderTraverse(display);

	cout << "Tree 1 height: " << tree1->getHeight() << endl;
	cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;
}  // end main

   /* SAMPLE OUTPUT

   Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80
   Displaying item - 10
   Displaying item - 20
   Displaying item - 50
   Displaying item - 30
   Displaying item - 80
   Displaying item - 40
   Displaying item - 60
   Displaying item - 70
   Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80
   Displaying item - 20
   Displaying item - 50
   Displaying item - 10
   Displaying item - 80
   Displaying item - 30
   Displaying item - 70
   Displaying item - 60
   Displaying item - 40
   Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10
   Displaying item - 20
   Displaying item - 50
   Displaying item - 30
   Displaying item - 80
   Displaying item - 40
   Displaying item - 60
   Displaying item - 70
   Displaying item - 10
   Tree 1 height: 5
   Tree 1 number of nodes: 8
   Remove the leaf 80: Done.
   Try to remove the leaf 80 again:  Entry not in tree.
   Tree 2 Preorder:
   Displaying item - 10
   Displaying item - 20
   Displaying item - 30
   Displaying item - 40
   Displaying item - 60
   Displaying item - 50
   Displaying item - 70
   Displaying item - 80
   Tree 2 Inorder:
   Displaying item - 30
   Displaying item - 20
   Displaying item - 60
   Displaying item - 40
   Displaying item - 10
   Displaying item - 70
   Displaying item - 50
   Displaying item - 80
   Tree 2 Postorder:
   Displaying item - 20
   Displaying item - 30
   Displaying item - 40
   Displaying item - 60
   Displaying item - 50
   Displaying item - 70
   Displaying item - 80
   Displaying item - 10
   Tree 2 height: 4
   Tree 2 number of nodes: 8
   Remove the node 40 in Tree 1: Done.
   Tree 1 Preorder: Should be 10 20 70 60 30
   Displaying item - 10
   Displaying item - 20
   Displaying item - 50
   Displaying item - 30
   Displaying item - 60
   Displaying item - 70
   Tree 1 Inorder: Should be 70 20 60 10 30
   Displaying item - 20
   Displaying item - 50
   Displaying item - 10
   Displaying item - 30
   Displaying item - 70
   Displaying item - 60
   Tree 1 Postorder: Should be 70 60 20 30 10
   Displaying item - 20
   Displaying item - 50
   Displaying item - 30
   Displaying item - 60
   Displaying item - 70
   Displaying item - 10
   Tree 1 height: 4
   Tree 1 number of nodes: 6
   */
