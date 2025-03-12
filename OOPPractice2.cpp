#include <iostream>
#include <string>

using namespace std;

class Chovek {
private:
    string firstName;
    string lastName;
    char gender; // 'M' за мъж, 'F' за жена

public:
    // Конструктор
    Chovek(const string& fName, const string& lName, char gen) // & is a refrence so that the program does not make a copy.
        : firstName(fName), lastName(lName), gender(gen) { // direct intialazation
    }

    // Методи за достъп (Getters)
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    char getGender() const { return gender; }

    // Методи за промяна (Setters)
    void setFirstName(const string& newFirstName) { firstName = newFirstName; }
    void setLastName(const string& newLastName) { lastName = newLastName; }
    void setGender(char newGender) { gender = newGender; }

    // Метод за извеждане на информация
    void printInfo() const {
        cout << "Name: " << firstName << ", LastName: " << lastName << ", Gender: " << gender << endl;
    }
};

int main() {
    Chovek person("Ivan", "Petrov", 'M');
    person.printInfo();

    // Използване на сетъри
    person.setFirstName("Petar");
    person.setLastName("Ivanov");
    person.setGender('M');

    person.printInfo();

    return 0;
}
