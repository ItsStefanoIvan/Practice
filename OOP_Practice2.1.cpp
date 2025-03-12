#include <iostream>
#include <string>

using namespace std;

class Chovek {
private:
    string firstName;
    string lastName;
    char gender;
    bool hasBrother;

public:
    // Конструктор
    Chovek(const string& fName, const string& lName, char gen, bool hasBro = false) // & refrence
        : firstName(fName), lastName(lName), gender(gen), hasBrother(hasBro) { // direct initialisation
    }

    // Гетъри
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    char getGender() const { return gender; }

    // Оператор за сключване на брак
    void operator+=(const Chovek& husband) {
        if (gender == 'F' && husband.gender == 'M') { // Проверка дали жената се омъжва за мъж
            if (hasBrother) {
                lastName = husband.lastName + "a"; // Изцяло взима фамилията на мъжа и добавя "а"
            }
            else {
                lastName += "-" + husband.lastName + "a"; // Добавя фамилията на мъжа с тире и "а"
            }
        }
    }

    // Оператор за извеждане на информация
    friend ostream& operator<<(ostream& os, const Chovek& person) {
        os << "Name: " << person.firstName << ", LastName: " << person.lastName << ", Gender: " << person.gender;
        return os;
    }
};

int main() {
    // Мъж и жена без брат
    Chovek husband("Ivan", "Petrov", 'M');
    Chovek wife1("Maria", "Dimitrova", 'F', false);

    // Мъж и жена с брат
    Chovek wife2("Elena", "Koleva", 'F', true);

    cout << "Before marriage:" << endl;
    cout << wife1 << endl;
    cout << wife2 << endl;

    // Жените се омъжват за мъжа
    wife1 += husband;
    wife2 += husband;

    cout << "\nAfter marriage:" << endl;
    cout << wife1 << endl;
    cout << wife2 << endl;

    return 0;
}
