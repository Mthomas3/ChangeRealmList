#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class List {

private:
	struct node {
		string	server;
		string	data;
	  string data_one;
	  string data_two;
		node	*next;
		string	realmlist;
		string real;
	  int	server_exit;
	  string data_real;
	};

	typedef struct node		*nodePtr;

	nodePtr		head;
	nodePtr		head_real;
	nodePtr		curr;
	nodePtr		curr_real;
	nodePtr		curr_name;
	nodePtr		temp;
	nodePtr		head_name;
	nodePtr		head_one;
	nodePtr		head_two;
	nodePtr		curr_one;
	nodePtr		curr_two;

public:

	List();
	bool IfNode(string data);
	void AddNode(string addData, int size);
	void DeleteNode(string delData);
	bool IfSomethingInNode();
	void FindInNodeServer(List *ptr);
	string GetPath();
	void PrintList(int list);
	void AddNodeDouble(string NodeServer, string NodeReal);
	void PrintDoubleList( void );
	void GetFullList( List *ptr );
	string write_list( void );
};

#endif /* LIST_H  */
