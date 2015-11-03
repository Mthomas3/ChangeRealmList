#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Header.h"
#include <stdlib.h>

using namespace std;

string get_realName(string server)
{
	int a(-1);
	int size_server(0);

	size_server = server.size();

	while (++a < size_server)
		if (server[a] >= 'A' && server[a] <= 'Z')
			server[a] = server[a] + 32;
	return server;
}

int my_server(string server)
{
	int server_number(0);

	if (server == "chimera") server_number = 2;
	else if (server == "molten") server_number = 1;
	else if (server == "monster") server_number = 3;
	else server_number = -1;
	return server_number;
}

void	print_message(string write_this)
{
	cout << write_this << endl;
}

void	write_in_file()
{
	string const name_file("test.txt");
	ofstream MyFlux(name_file.c_str());
	string path;

	cout << "Hello! its your first time here so you have to type your path here : \n";
	cin >> path;
	if (MyFlux)
	{
		MyFlux << path;
	}
	print_message("Your path is saved, start again the program to change your realmlist! :)");
}

void	print_error()
{
	print_message("Name server is wrong, try another please!");
}

void	end_program()
{
	print_message("end of program too many errors, im sorry!");
	system("pause");
	exit(1);
}

void	write_ok(List *ptr, int error)
{
	string path;
	string server;
	int number_server(0);

	path = (*ptr).GetPath();
	string const name_file(path);
	ofstream MyFlux(name_file.c_str());

	print_message("Hello buddy, write your name server here : ");
	cin >> server;
	server = get_realName(server);
	(*ptr).AddNode(server);
	number_server = (*ptr).FindInNodeServer();
	if (number_server == 0)
	{
		error++;
		print_error();
		error > 20 ? end_program() : write_ok(ptr, error);
	}
	if (MyFlux)
	{
		if (number_server == 1)
			MyFlux << "set realmlist logon.warmane.com" << endl;
		else if (number_server == 2)
			MyFlux << "set realmlist wow-phoenixia.com" << endl;
		else if (number_server == 3)
		{
			MyFlux << "set realmlist logon.monster-wow.com" << endl;
			MyFlux << "set patchlist logon.monster-wow.com" << endl;
		}
	}
	else
	{
		print_message("can't write in this file, sorry");
	}
	print_message("your realmlist has been changed!");
}

int main( )
{
	List ptr;
	int	error(0);
	ifstream fichier("test.txt", ios::in);
	string contenu;
	string ligne;

	while (getline(fichier, ligne))
			ptr.AddNode(ligne);
	fichier.close();
	ptr.IfSomethingInNode() ? write_ok(&ptr, error) : write_in_file();
	system("pause");
	return 0;
}
