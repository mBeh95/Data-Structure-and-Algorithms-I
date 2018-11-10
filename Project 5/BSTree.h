#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"
using namespace std;

class BSTree
{
public:
	BSTree();
	~BSTree();
	bool Insert(Account *); 
	// retrieve object, first parameter is the ID of the account 
	// second parameter holds pointer to found object, NULL if not found 
	bool Retrieve(const int &, Account * &) const; 
	// displays the contents of a tree to cout 
	void Display() const; 
	void Empty(); 
	bool isEmpty() const; 
private: 
	struct Node 
	{ 
		Account *pAcct; 
		Node *right; 
		Node *left; 
	}; 
	Node *root; 
};

