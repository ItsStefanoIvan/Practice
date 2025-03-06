#include <iostream>
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;



int main()
{

    Student s1("Alexa", 20, 60.5, 90.0, 76.2);
    Student s2("George", 21, 98.1, 78.9, 96.8);
    
    s1.display();
    s2.display();
}


