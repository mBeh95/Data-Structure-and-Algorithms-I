#pragma once
#ifndef LIST342_H 
#define LIST342_H 

#include <iostream>
#include <fstream>
#include <string>
#include "Child.h"
using namespace std;



template <typename ItemType>
class List342
{
private:
	struct Node
	{
		ItemType *data;
		Node *next;
	};
	string fileName;
	Node *head;
	int size;

public:
	List342()
	{
		head = NULL;
		size = 0;
	}
	List342(string fileName)
	{
		curr = head = new Node<ItemType>;
		size = 0;
		BuildList(fileName);
	}
	~List342()
	{
		DeleteList();
	}
	
	
	
	bool BuildList(string fileName)
	{
		ifstream input;
		ItemType temp;
		input.open(fileName.c_str());
		if (!input)
		{
			cout << "File error" << endl;
			return false;
		}
		else
		{
			while (!fileName.eof())
			{
				input >> temp;
				Insert(&temp);
			}
			return true;
		}
	}

	
	bool Insert(ItemType *obj)
	{
		Node *pNode = head;
		Node *insNode = new Node;
		ItemType *newObject = new ItemType;
		*newObject = *obj;
		insNode->data = newObject;
		insNode->next = NULL;
		if (obj == NULL)
		{
			delete insNode;
			delete newObject;
			return false;
		}
		if (head == NULL)
		{
			
			head = insNode;
			head->next = NULL;
			size++;
			return true;
		}
		else if (*(insNode->data) < *(head->data))
		{
			insNode->next = head;
			head = insNode;
			size++;
			return true;
		}
		else
		{
			while ((pNode->next != NULL) && (*((pNode->next)->data) < *(insNode->data)))
			{
				pNode = pNode->next;
			}
			if (*(insNode->data) == *(pNode->data))
			{
				delete insNode;
				return false;
			}
			if ((pNode->next != NULL) && (*(insNode->data) == *(pNode->next->data)))
			{
				delete insNode;
				return false;
			}
			else
			{
				insNode->next = pNode->next;
				pNode->next = insNode;
				size++;
			}
			return true;
		}
	}

	
	bool Remove(ItemType target, ItemType &result)
	{
		Node *temp;
		if (size == 0)
		{
			return false;
		}
		if (*(head->data) == target)
		{
			temp = head;
			head = head->next;
			result = *(temp->data);
			delete temp->data;
			delete temp;
			temp = NULL;
			size--;
			return true;
		}
		Node *pNode = head;
		while ((pNode->next != NULL) && (*((pNode->next)->data) != target))
		{
			pNode = pNode->next;
		}
		if (pNode->next == NULL)
		{
			return false;
		}
		else
		{
			temp = pNode->next;
			pNode->next = pNode->next->next;
			result = *(temp->data);
			delete temp->data;
			delete temp;
			temp = NULL;
			size--;
			return true;
		}
	}

	
	bool Peek(ItemType target, ItemType &result) const
	{
		if (head == NULL)
		{
			return false;
		}

		if (*head->data == target)
		{
			result = target;
			return true;
		}

		Node *current = head;

		while ((*current->data != target) && (current->next != NULL))
		{
			current = current->next;
		}

		if (*current->data == target)
		{
			result = target;
			return true;
		}

		return false;
	}
	
	bool isEmpty() const
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void DeleteList()
	{
		Node *temp;
		while (head != NULL) 
		{
			temp = head;
			head = head->next;
			delete temp->data;
			delete temp;
			
		}
		head = NULL;
		size = 0;
	}

	
	bool Merge(List342 &list1)
	{
	
		if ((this == &list1) || (list1.head == NULL))
		{
			return false;
		}

		if (!(list1.head == NULL) && (head == NULL))
		{
			head = list1.head;
			list1.head = NULL;
			return true;
		}

		Node*dNode = head;
		Node*sNode = list1.head;
		Node temp;
		Node *current = &temp;
		head = NULL;
		list1.head = NULL;

		while (dNode != NULL && sNode != NULL)
		{
			if ((*dNode->data) == (*sNode->data))
			{
				current->next = dNode;
				dNode = dNode->next;

				Node *dummy = sNode;
				sNode = sNode->next;
				delete dummy->data;
				delete dummy;
			}
			else if ((*dNode->data) < (*sNode->data))
			{
				current->next = dNode;
				dNode = dNode->next;
			}
			else
			{
				current->next = sNode;
				sNode = sNode->next;
			}

			current = current->next;
		}

		if (sNode != NULL)
		{
			current->next = sNode;
		}

		if (dNode != NULL)
		{
			current->next = dNode;
		}

		head = temp.next;
		return true;
	}
	
	List342<ItemType> operator+=(const List342 &rhs)
	{
		if (rhs.head == NULL)
		{
			return *this;
		}
		else
		{
			Node *ptr = rhs.head;

			while (ptr != NULL)
			{
				Insert(ptr->data);
				ptr = ptr->next;
			}
		}

		return *this;
	}

	
	List342<ItemType> operator+(const List342 &rhs) const
	{
		List342<ItemType> temp;
		Node *ptr;

		while (ptr != NULL)
		{
			temp.Insert(current->data);
			ptr = ptr->next;
		}

		current = rhs.head;

		while (ptr != NULL)
		{
			temp.Insert(ptr->data);
			ptr = ptr->next;
		}

		return temp;
	}

	
	bool operator==(const List342 &rhs) const
	{
		Node *ptr = rhs.head;
		Node *ptr2 = head;

		if (ptr2 == NULL)
		{
			return false;
		}
		if (ptr == NULL)
		{
			return false;
		}
		if (this->size != rhs.size)
		{
			return false;
		}
		else
		{
			while (ptr != NULL && ptr2 != NULL)
			{
				if (*(ptr->data) != *(ptr2->data))
				{
					return false;
				}
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
		}
		return true;
	}

	
	bool operator=(const List342<ItemType> &rhs) const
	{
		Node *ptr = rhs.head;
		Node *temp = new Node;
		ItemType data = new ItemType;
		*data = *(ptr->data);
		Node *copy = ptr;
		if (this == &rhs)
		{
			return;
		}
		DeleteList();
		while (ptr != NULL)
		{
			copy->next = temp;
			copy = copy->next;
			ptr = ptr->next;
		}
		return true;
	}

	
	bool operator!=(const List342 &rhs) const
	{
		Node *ptr = rhs.head;
		Node *ptr2 = head;

		if (ptr2 == NULL)
		{
			return false;
		}
		if (ptr == NULL)
		{
			return false;
		}
		if (this->size != rhs.size)
		{
			return false;
		}
		else
		{
			while (ptr != NULL && ptr2 != NULL)
			{
				if (*(ptr->data) == *(ptr2->data))
				{
					return false;
				}
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
		}
		return true;
	}

	friend ostream& operator<<(ostream &outStream, const List342<ItemType> &rhs)
	{
		Node *ptr = rhs.head;
		while (ptr != NULL)
		{
			outStream << *(ptr->data);
			ptr = ptr->next;
		}
		return outStream;
	}

};

#endif