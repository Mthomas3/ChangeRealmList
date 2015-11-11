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
	curr_real = NULL;
	head_real = NULL;
	head_name = NULL;
}

void	List::PrintList(int list)
{
	curr = head;
	while (curr != NULL)
	{
	  if (list == 0)
	    cout << curr->data_real << endl;
	  else if (list == 1)
	    {
	      cout << curr->server;
	      cout << curr->realmlist;
	      cout << endl;
	    }
	  curr = curr->next;
	}
}

void		List::PrintDoubleList( void )
{
	curr_real = head_real;
	while (NULL != curr_real)
	  {
	    cout << curr_real->data_real;
	    cout << curr_real->real;
	    cout << endl;
	    curr_real = curr_real->next;
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

int		List::FindInNodeServer(List *ptr)
{
	nodePtr n = NULL;
	int number(0);

	curr = head;
	curr_real = head_real;
	cout << "print" << endl;
	(*ptr).PrintList(0);
	cout << curr->next->next->next->data << endl;
	while (curr != NULL && NULL != curr_real)
	{
		if (curr->data == curr_real->real)
			number = 3;
		else if (curr->data == curr_real->real)
			number = 2;
		else if (curr->data == curr_real->real)
			number = 1;
			temp = curr;
		curr = curr->next;
		curr_real = curr_real->next;
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

void		List::GetFullList( List *ptr )
{
  (*ptr).AddNodeDouble("molten", " !real molten! ");
  (*ptr).AddNodeDouble("chimera", " !real chimera! ");
  (*ptr).AddNodeDouble("monster", " !real monster! ");
  (*ptr).AddNodeDouble("caca", " !real caca! ");
}

//need to fix this function ...

void		List::AddNodeDouble(string NodeServer, string NodeReal)
{
  nodePtr	n = new node;
  nodePtr	j = new node;

  cout << NodeServer << endl;
  n->next = NULL;
  j->next = NULL;
  n->data_real = NodeServer;
  j->real = NodeReal;

  if (NULL != head_real && NULL != head_name)
    {
      curr_real = head_real;
      curr_name = head_name;
      while (NULL != curr_name->next && NULL != curr_real->next)
	{
	  curr_name = curr_name->next;
	  curr_real = curr_real->next;
	}
      curr_name->next = n;
      curr_real->next = j;
    }
  else
    {
      head_name = n;
      head_real = j;
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
