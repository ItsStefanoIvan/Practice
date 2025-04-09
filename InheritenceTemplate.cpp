#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;

// Utility function to safely copy a C-string
char* copy_str(const char* src) {
    char* dest = new char[strlen(src) + 1];
    assert(dest != NULL);
    strcpy_s(dest, strlen(src) + 1, src);
    return dest;
}

class People {
    friend std::ostream& operator<<(std::ostream&, const People&);

public:
    People(const char* n = "No Name", const char* e = "No EGN");
    People(const People&);
    People& operator=(const People&);
    virtual ~People();

    void set_name(const char*);
    void set_egn(const char*);

    const char* get_name() const;
    const char* get_egn() const;

    virtual void print() const;

private:
    char* name;
    char* egn;
};

class Student : public People {
    friend std::ostream& operator<<(std::ostream&, const Student&);

public:
    Student(const char* n = "No Name", const char* e = "No EGN", const char* f = "No Faculty Number", double g = 2.0);
    Student(const Student&);
    Student& operator=(const Student&);
    ~Student();

    void set_fnum(const char*);
    void set_grade(double);

    const char* get_fnum() const;
    double get_grade() const;

    void print() const override;

private:
    char* fnum;
    double grade;
};

// ------------------- People -------------------

People::People(const char* n, const char* e) {
    name = copy_str(n);
    egn = copy_str(e);
}

People::People(const People& p) {
    name = copy_str(p.name);
    egn = copy_str(p.egn);
}

People& People::operator=(const People& p) {
    if (this != &p) {
        delete[] name;
        delete[] egn;
        name = copy_str(p.name);
        egn = copy_str(p.egn);
    }
    return *this;
}

People::~People() {
    delete[] name;
    delete[] egn;
}

void People::set_name(const char* n) {
    delete[] name;
    name = copy_str(n);
}

void People::set_egn(const char* e) {
    delete[] egn;
    egn = copy_str(e);
}

const char* People::get_name() const {
    return name;
}

const char* People::get_egn() const {
    return egn;
}

void People::print() const {
    cout << "Name: " << name << endl;
    cout << "EGN: " << egn << endl;
}

ostream& operator<<(ostream& out, const People& p) {
    out << "Name: " << p.name << " EGN: " << p.egn << endl;
    return out;
}

// ------------------- Student -------------------

Student::Student(const char* n, const char* e, const char* f, double g) : People(n, e) {
    fnum = copy_str(f);
    set_grade(g);
}

Student::Student(const Student& s) : People(s) {
    fnum = copy_str(s.fnum);
    grade = s.grade;
}

Student& Student::operator=(const Student& s) {
    if (this != &s) {
        People::operator=(s);
        delete[] fnum;
        fnum = copy_str(s.fnum);
        grade = s.grade;
    }
    return *this;
}

Student::~Student() {
    delete[] fnum;
}

void Student::set_fnum(const char* f) {
    delete[] fnum;
    fnum = copy_str(f);
}

void Student::set_grade(double g) {
    grade = (g < 2) ? 2 : (g > 6) ? 6 : g;
}

const char* Student::get_fnum() const {
    return fnum;
}

double Student::get_grade() const {
    return grade;
}

void Student::print() const {
    People::print();
    cout << "Faculty number: " << fnum << endl;
    cout << "Grade: " << grade << endl;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << "Name: " << s.get_name() << " EGN: " << s.get_egn() << endl
        << "Faculty number: " << s.fnum << " Grade: " << s.grade << endl;
    return out;
}

// ------------------- Main -------------------

int main() {
    People p("Ivanov", "1234567898");
    cout << p << endl;
    p.print();

    People q = p;  // copy constructor
    cout << "Copy of People object: " << q << endl;

    Student s("Petrov", "912345678", "67890", 4.56);
    cout << s << endl;
    s.print();

    Student x(s);  // copy constructor
    cout << "Copy of Student object: " << x << endl;

    People y = x;  // slicing: only base part is copied
    cout << "Copy of Student to People (sliced): " << y << endl;

    return 0;
}
