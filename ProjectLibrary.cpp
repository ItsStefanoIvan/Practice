#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
	Library myLibrary;

	myLibrary.addBooks("Boneshaker", "Cherie Priest", "9780743273565", 2);
	myLibrary.addBooks("1984", "George Orwell", "9780451524935", 5);
	myLibrary.DisplayBooks();
}


