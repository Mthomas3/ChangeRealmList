#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Header.h"
#include <stdlib.h>

using namespace std;

string	get_realName(string server)
{
  int	a(-1);
  int	size_server(0);

  size_server = server.size();

  while (++a < size_server)
    if (server[a] >= 'A' && server[a] <= 'Z')
      server[a] = server[a] + 32;
  return server;
}

int	my_server(string server)
{
  int	server_number(0);

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

void		write_in_file()
{
  string const	name_file("test.txt");
  ofstream	MyFlux(name_file.c_str());
  string	path;

  print_message("Hello, It's your first time here you have to type your path here :");
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

bool	end_program()
{
  print_message("end of program too many errors, im sorry!");
  system("pause");
  return false;
}

void		write_file(string server, string realmlist)
{
  std::ofstream ofs;

  ofs.open ("test.txt", ofstream::out | ofstream::app);
  ofs << "\n";
  ofs << server;
  ofs << "\n";
  ofs << realmlist;
  ofs << "\n";
  ofs.close();
}

bool		add_real( List *ptr )
{
  string	reply;
  string	name_server;
  string	name_realmlist;

  print_message("Do you want to add a realmlist?");
  print_message("type yes or no");
  cin >> reply;
  if (reply == "no")
    return false;
  else if (reply == "yes") //fix ici
    {
      print_message("type your name server here : ");
      cin >> name_server;
      print_message("type your realmlist here :");
      cin >> name_realmlist;
    }
  print_message("Modification succeded!");
  (*ptr).AddNodeDouble(name_server, name_realmlist);
  write_file(name_server, name_realmlist);
  return true;
}

bool		write_ok(List *ptr, int error)
{
  string	path;
  string	server;
  int		number_server(0);

  path = (*ptr).GetPath();
  string const	name_file(path);
  ofstream	MyFlux(name_file.c_str());

  print_message("Hello buddy, type your name server here : ");
  print_message("Or you can type option if you want to change ur config :)");
  cin >> server;
  server = get_realName(server);
  if (server == "option")
    {
      add_real(ptr);
      print_message("So now, which server do you want to play?");
      cin >> server;
      server = get_realName(server);
    }
  (*ptr).AddNode(server, 0);
  (*ptr).FindInNodeServer(ptr);
  (*ptr).PrintList(0);
  if (((*ptr).FindError(ptr)) == false)
    {
      error++;
      print_error();
      if ((error > 20))
	return end_program(); //exit program if error ..
      else
	write_ok(ptr, error);
    }
  if (MyFlux)
    {
      MyFlux << (*ptr).write_list();
    }
  else
    {
      print_message("can't write in this file, sorry");
    }
  return true;
}

//parsing server!

void		GetFullFile( List *list )
{
  ifstream	fichier("test.txt", ios::in);
  string	line;
  int		break_line(0);
  int		break_tab(0);
  string	tab[2];

  while (getline(fichier, line))
    {
      if (0 != break_line)
	{
	  if ("\0" != line && break_tab == 0)
	    {
	      tab[0] = line;
	      ++break_tab;
	    }
	  else
	    {
	      tab[1] = line;
	    }
	  if (tab[0] != "\0" && tab[1] != "\0")
	    {
	      (*list).AddNodeDouble(tab[0], tab[1]);
	      break_tab = 0;
	    }
	}
      ++break_line;
    }
  fichier.close();
}

int		main( void )
{
  List		ptr;
  int		error(0);
  ifstream	fichier("test.txt", ios::in);
  string	contenu;
  string	ligne;
  string	server;
  int		break_line(0);

  ptr.GetFullList(&ptr);
  GetFullFile(&ptr);
  while (getline(fichier, ligne))
    {
      if (break_line == 0)
	ptr.AddNode(ligne, 0);
      ++break_line;
    }
  fichier.close();
  if ((ptr.IfSomethingInNode()))
    {
      if ((write_ok(&ptr, error)) == true)
	print_message("Your realmlist has been changed!:)\n");
      else
	return false;
    }
  else
    write_in_file();
  system("pause");
  return 0;
}
