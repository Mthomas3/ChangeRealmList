#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Header.h"
#include <string>

using namespace std;

List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void	List::PrintList(int list)
{
	curr = head;
	while (curr != NULL)
	{
	  if (list == 0)
	    cout << curr->data << endl;
	  else if (list == 1)
	    {
	      cout << curr->server;
	      cout << "     end   :   ";
	      cout << curr->realmlist;
	    }
	  curr = curr->next;
	}
}

bool		List::IfNode(string match)
{
	nodePtr	n = NULL;

	temp = head;
	curr = head;
	while (curr != NULL && curr->data != match)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		delete n;
		return false;
	}
	else
	{
		delete n;
		return true;
	}
}

int		List::FindInNodeServer()
{
	nodePtr n = NULL;
	int number(0);

	curr = head;
	while (curr != NULL)
	{
		if (curr->data == "monster")
			number = 1;
		else if (curr->data == "chimera")
			number = 2;
		else if (curr->data == "molten")
			number = 3;
			temp = curr;
		curr = curr->next;
	}
	return number;
}

void	List::DeleteNode(string delData)
{
	nodePtr		delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		delete delPtr;
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
	}

}

string List::GetPath()
{
	nodePtr n = NULL;

	curr = head;
	if (curr != NULL)
		return curr->data;
	return NULL;
}

bool	List::IfSomethingInNode()
{
	nodePtr	n = NULL;

	curr = head;
	if (curr == NULL)
		return false;
	else
		return true;
}

void		List::AddNodeDouble(string NodeServer, string NodeReal)
{
  nodePtr	n = new node;

  n->next = NULL;
  n->server = server;
  n->realmlist = NodeReal;

  if (NULL != head)
    {
      curr = head;
      while (NULL != curr->next)
	curr = curr->next;
      curr->next = n;
    }
  else
    {
      head = n;
    }
}

void	List::AddNode(string addData, int number_list)
{
	nodePtr	n = new node;

	n->next = NULL;
	if (number_list == 0)
	  n->data = addData;
	else if (number_list == 1)
	  n->server = addData;
	else if (number_list == 2)
	  n->realmlist = addData;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}

}
