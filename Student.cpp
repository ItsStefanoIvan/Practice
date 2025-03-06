#include "Student.h"
#include <iostream>
#include <string>

Student::Student(string n, int a, float g1, float g2, float g3) 
{
	name = n;
	age = a;
	grades[0] = g1;
	grades[1] = g2;
	grades[2] = g3;

}
void Student::setName(string n) 
{
	name = n;
}
void Student::setAge(int a) 
{
	age = a;
}
void Student::setGrade(float g1, float g2, float g3) 
{
	grades[0] = g1;
	grades[1] = g2;
	grades[2] = g3;
}

string Student::getName() const 
{
	return name;
}
int Student::getAge() const
{
	return age;
}
float Student::getGrade(int index) const 
{
	return(index >= 0 && index < 3) ? grades[index] : -1;
}

void Student::display() const 
{
	cout << "Student: " << name << ", Age: " << age << ", Grades: [" << grades[0] << ", " << grades[1] << ", " << grades[2] << "]\n";
}