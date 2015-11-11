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
		node	*next;
		string	realmlist;
	};

	typedef struct node		*nodePtr;

	nodePtr		head;
	nodePtr		curr;
	nodePtr		temp;
public:

	List();
	bool IfNode(string data);
	void AddNode(string addData, int size);
	void DeleteNode(string delData);
	bool IfSomethingInNode();
	int FindInNodeServer();
	string GetPath();
	void PrintList(int list);
};

#endif /* LIST_H  */
