#pragma once
#ifndef Book_h
#define Book_h

#include <iostream>
#include <string>

using namespace std;

class Book 
{
private:
	string title;
	string author;
	string isbn;
	int CopiesAvailable;

public:

	Book();

	Book(string t, string a, string i, int c);

	void setTitle(string t);
	void setAuthor(string a);
	void setIsbn(string i);
	void setCopies(int c);

	string getTitle();
	string getAuthor();
	string getIsbn();
	int getCopies();

	void display() const;

};



#endif

