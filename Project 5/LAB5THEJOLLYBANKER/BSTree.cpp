#include "stdafx.h"
#include "BSTree.h"


BSTree::BSTree()
{
	root = new Node;
	root = NULL;
}


BSTree::~BSTree()
{
	Empty();
}

bool BSTree::Insert(Account *accountHolder)
{
	InsertRecur(accountHolder, root);
	return true;
}

void BSTree::InsertRecur(Account *accountHolder, Node * &curr)
{
	if (curr == NULL)
	{
		curr = new Node;
		curr->left = curr->right = NULL;
		curr->pAcct = accountHolder;
		return;
	}
	else if (curr->pAcct->getId() == accountHolder->getId())
	{
		return;
	}
	else if (accountHolder->getId() < curr->pAcct->getId())
	{
		InsertRecur(accountHolder, curr->left);
	}
	else
	{
		InsertRecur(accountHolder, curr->right);
	}
}
// retrieve object, first parameter is the ID of the account 
// second parameter holds pointer to found object, NULL if not found 
bool BSTree::Retrieve(const int &id, Account * &targetAccount) const
{
	
	
	bool found = false;
	Node *fNode = new Node;
	fNode = root;
	while (found != true)
	{
		if (fNode == NULL)
		{
			return false;
		}
		else if (fNode->pAcct->getId() == id)
		{
			found = true;
			targetAccount = fNode->pAcct;
			return true;
		}
		else if (fNode->pAcct->getId() < id)
		{
			fNode = fNode->right;
		}
		else
		{
			fNode = fNode->left;
		}
	}
	return true;
}

// displays the contents of a tree to cout 
void BSTree::Display() const
{
	PrintTree(root, cerr);
}

void BSTree::PrintTree(Node *node, std::ostream & out) const
{
	if (node == NULL)
	{
		return;
	}
	//inorder traversal
	PrintTree(node->left, out);
	node->pAcct->Print();
	PrintTree(node->right, out);

}

void BSTree::Empty()
{
	makeEmpty(root);
}

void BSTree::makeEmpty(Node * &node)
{
	if (node != NULL)
	{
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node->pAcct;
		delete node;

	}
}

bool BSTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}