#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Header.h"
#include <string>

using namespace std;

List::List( )
{
  head = NULL;
  curr = NULL;
  temp = NULL;
  curr_name = NULL;
  curr_real = NULL;
  head_real = NULL;
  head_name = NULL;
  head_one = NULL;
  head_two = NULL;
  curr_one = NULL;
  curr_two = NULL;
}

bool		List::FindError( List *ptr )
{
  int		error(0);

  curr_two = head_two;
  while (NULL != curr_two)
    {
      if (curr_two->server_exit == 1)
	++error;
      curr_two = curr_two->next;
    }
  if (error == 0)
    return false;
  return true;
}

string		List::write_list( void )
{
  curr_two = head_two;
  while (NULL != curr_two)
    {
      if (curr_two->server_exit == 1)
	return curr_two->data_two;
      curr_two = curr_two->next;
    }
  return NULL;
}

void		List::PrintList(int list)
{
  curr = head;
  while (curr != NULL)
    {
      if (list == 0)
	cout << curr->data << endl;
      else if (list == 1)
	{
	  cout << curr->server;
	  cout << curr->realmlist;
	  cout << endl;
	}
      curr = curr->next;
    }
}

void		List::FindInNodeServer(List *ptr)
{
  string	server;

  curr = head;
  curr_one = head_one;
  server = curr->next->data;
  while (NULL != curr_one)
    {
      if (server == curr_one->data_one)
	curr_one->server_exit = 1;
      curr_one = curr_one->next;
    }
}

void		List::PrintDoubleList( void )
{
  curr_one = head_one;
  curr_two = head_two;
  while (NULL != curr_one && NULL != curr_two)
    {
      cout << curr_one->data_one;
      cout << curr_two->data_two;
      cout << curr_one->server_exit;
      cout << endl;
      curr_one = curr_one->next;
      curr_two = curr_two->next;
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

void		List::DeleteNode(string delData)
{
  nodePtr	delPtr = NULL;
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

string		List::GetPath()
{
  nodePtr	n = NULL;

  curr = head;
  if (curr != NULL)
    return curr->data;
  return NULL;
}

bool		List::IfSomethingInNode()
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
  (*ptr).AddNodeDouble("cacaLOL", " !real cacaLOL! ");
}

// fixed!

void		List::AddNodeDouble(string NodeServer, string NodeReal)
{
  nodePtr	n = new node;

  n->next = NULL;
  n->data_one = NodeServer;
  n->data_two = NodeReal;
  if (head_one != NULL && head_two != NULL)
    {
      curr_one = head_one;
      curr_two = head_two;
      while (curr_one->next != NULL && curr_two->next != NULL)
	{
	  curr_one = curr_one->next;
	  curr_two = curr_two->next;
	}
      curr_one->next = n;
      curr_two->next = n;
    }
  else
    {
      head_one = n;
      head_two = n;
    }
}

void		List::AddNode(string addData, int number_list)
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
