#include "Library.h"
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

Library::Library() 
{
	count = 0;
}

void Library::addBooks(string title, string author, string isbn, int CopiesAvaiable) 
{
	if (count < 5) 
	{
		Books[count] = Book(title, author, isbn, CopiesAvaiable);
		count++;
	}
	else 
	{
		cout << "Library is full. Cannot add more books. \n";
	}
}

void Library::DisplayBooks() const 
{
	cout << "Library books:\n";
	if (count == 0) 
	{
		cout << "There are no books available in the library.\n";
	}
	else 
	{
		for (int i = 0; i < count; i++) 
		{
			Books[i].display(); // Call Book's display function
		}

	}
}