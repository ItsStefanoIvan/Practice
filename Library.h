#pragma once
#ifndef Library_h
#define Library_h

#include <iostream>
#include "Book.h"

using namespace std;

class Library 
{
private:
	Book Books[5];
	int count;


public:
	Library(); //Constructor

	void addBooks(string title, string author, string isbn, int CopiesAvailable);

	void DisplayBooks() const;

};




#endif