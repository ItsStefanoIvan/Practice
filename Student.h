#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	int age;
	float grades[3];

public:
	Student(string n, int a, float g1 = 0, float g2 = 0, float g3 = 0);

	void setName(string n);
	void setAge(int a);
	void setGrade(float g1, float g2, float g3);

	string getName() const;
	int getAge() const;
	float getGrade(int index) const;

	void display() const;

};

#endif
