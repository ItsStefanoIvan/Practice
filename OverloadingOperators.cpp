#include <iostream>

class MyNumber {
private:
    int value;

public:
    MyNumber(int val = 0) : value(val) {}

    // Arithmetic Operators
    MyNumber operator+(const MyNumber& other) const { return MyNumber(value + other.value); } // Addition
    MyNumber operator-(const MyNumber& other) const { return MyNumber(value - other.value); } // Subtraction
    MyNumber operator*(const MyNumber& other) const { return MyNumber(value * other.value); } // Multiplication
    MyNumber operator/(const MyNumber& other) const { return MyNumber(value / other.value); } // Division
    MyNumber operator%(const MyNumber& other) const { return MyNumber(value % other.value); } // Modulus

    // Comparison Operators
    bool operator==(const MyNumber& other) const { return value == other.value; } // Equal to
    bool operator!=(const MyNumber& other) const { return value != other.value; } // Not equal to
    bool operator<(const MyNumber& other) const { return value < other.value; } // Less than
    bool operator>(const MyNumber& other) const { return value > other.value; } // Greater than
    bool operator<=(const MyNumber& other) const { return value <= other.value; } // Less than or equal to
    bool operator>=(const MyNumber& other) const { return value >= other.value; } // Greater than or equal to

    // Logical Operators
    bool operator!() const { return !value; } // Logical NOT
    bool operator&&(const MyNumber& other) const { return value && other.value; } // Logical AND
    bool operator||(const MyNumber& other) const { return value || other.value; } // Logical OR

    // Bitwise Operators
    MyNumber operator&(const MyNumber& other) const { return MyNumber(value & other.value); } // Bitwise AND
    MyNumber operator|(const MyNumber& other) const { return MyNumber(value | other.value); } // Bitwise OR
    MyNumber operator^(const MyNumber& other) const { return MyNumber(value ^ other.value); } // Bitwise XOR
    MyNumber operator~() const { return MyNumber(~value); } // Bitwise NOT
    MyNumber operator<<(int shift) const { return MyNumber(value << shift); } // Left shift
    MyNumber operator>>(int shift) const { return MyNumber(value >> shift); } // Right shift

    // Increment and Decrement Operators
    MyNumber& operator++() { ++value; return *this; }   // Prefix Increment
    MyNumber operator++(int) { MyNumber temp = *this; ++value; return temp; } // Postfix Increment
    MyNumber& operator--() { --value; return *this; }   // Prefix Decrement
    MyNumber operator--(int) { MyNumber temp = *this; --value; return temp; } // Postfix Decrement

    // Assignment Operators
    MyNumber& operator+=(const MyNumber& other) { value += other.value; return *this; } // Addition Assignment
    MyNumber& operator-=(const MyNumber& other) { value -= other.value; return *this; } // Subtraction Assignment
    MyNumber& operator*=(const MyNumber& other) { value *= other.value; return *this; } // Multiplication Assignment
    MyNumber& operator/=(const MyNumber& other) { value /= other.value; return *this; } // Division Assignment
    MyNumber& operator%=(const MyNumber& other) { value %= other.value; return *this; } // Modulus Assignment
    MyNumber& operator&=(const MyNumber& other) { value &= other.value; return *this; } // Bitwise AND Assignment
    MyNumber& operator|=(const MyNumber& other) { value |= other.value; return *this; } // Bitwise OR Assignment
    MyNumber& operator^=(const MyNumber& other) { value ^= other.value; return *this; } // Bitwise XOR Assignment
    MyNumber& operator<<=(int shift) { value <<= shift; return *this; } // Left Shift Assignment
    MyNumber& operator>>=(int shift) { value >>= shift; return *this; } // Right Shift Assignment

    // Function Call Operator
    void operator()() const { std::cout << "Value: " << value << std::endl; } // Function Call

    // Subscript Operator
    int operator[](int index) const { return value + index; } // Array Indexing

    // Stream Operators
    friend std::ostream& operator<<(std::ostream& os, const MyNumber& num) { // Output Stream
        os << num.value;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, MyNumber& num) { // Input Stream
        is >> num.value;
        return is;
    }
};

int main() {
    MyNumber a(10), b(5);
    std::cout << "Addition: " << (a + b) << std::endl;
    std::cout << "Multiplication: " << (a * b) << std::endl;
    std::cout << "Bitwise AND: " << (a & b) << std::endl;
    std::cout << "Equality: " << (a == b) << std::endl;
    std::cout << "Increment: " << ++a << std::endl;
    a(); // Function call operator
    return 0;
}
