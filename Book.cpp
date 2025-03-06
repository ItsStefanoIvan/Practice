#include "Book.h"
#include "Library.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book() 
{
	title = "Unknown";
	author = "Unknown";
	isbn = "0000000000";
	CopiesAvailable = 0;
}

Book::Book(string t, string a, string i, int c) 
{
	title = t;
	author = a;
	isbn = i;
	CopiesAvailable = c;
}

void Book::setTitle(string t) 
{
	title = t;
}
void Book::setAuthor(string a)
{
	author = a;
}
void Book::setIsbn(string i) 
{
	isbn = i;
}
void Book::setCopies(int c) 
{
	CopiesAvailable = c;
}

string Book::getTitle()
{
	return title;
}
string Book::getAuthor()
{
	return author;
}
string Book::getIsbn() 
{
	return isbn;
}
int Book::getCopies() 
{
	return CopiesAvailable;
}

void Book::display() const
{
	cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << ", Available copies: " << CopiesAvailable << endl;
}