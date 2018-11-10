#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"
using namespace std;

class BSTree
{
private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};
	Node *root;
public:
	BSTree();
	~BSTree();
	bool Insert(Account *accountHolder);
	void InsertRecur(Account *accountHolder, Node * &curr);
	// retrieve object, first parameter is the ID of the account 
	// second parameter holds pointer to found object, NULL if not found 
	bool Retrieve(const int &id, Account * &targetAccount) const;
	// displays the contents of a tree to cout 
	void Display() const;
	void PrintTree(Node *node, std::ostream & out) const;
	
	void makeEmpty(Node * &node);
	void Empty();
	bool isEmpty() const;

};

