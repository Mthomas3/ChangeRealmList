#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class List {

public:
	struct node {
		string	data;
		node	*next;
	};

	typedef struct node		*nodePtr;

	nodePtr		head;
	nodePtr		curr;
	nodePtr		temp;
public:

	List();
	bool IfNode(string data);
	void AddNode(string addData);
	void DeleteNode(string delData);
	bool IfSomethingInNode();
	int FindInNodeServer();
	string GetPath();
	void PrintList();
};

#endif /* LIST_H  */
