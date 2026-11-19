#include <iostream>
#include <stdexcept>

class Number {
private:
    double value;

public:
    Number(double v = 0.0) : value(v) {}

    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }

    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }

    Number operator/(const Number& other) const {
        if (other.value == 0.0) {
            throw std::runtime_error("Division by zero is not allowed");
        }
        return Number(value / other.value);
    }

    friend std::ostream& operator<<(std::ostream& out, const Number& n) {
        out << n.value;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Number& n) {
        in >> n.value;
        return in;
    }
};

int main() {
    Number a, b;

    std::cout << "Enter two numbers: ";

    if (!(std::cin >> a >> b)) {
        std::cout << "Invalid input\n";
        return 1;
    }

    try {
        std::cout << "First number: " << a << '\n';
        std::cout << "Second number: " << b << '\n';
        std::cout << "Addition: " << a + b << '\n';
        std::cout << "Subtraction: " << a - b << '\n';
        std::cout << "Multiplication: " << a * b << '\n';
        std::cout << "Division: " << a / b << '\n';
    }
    catch (const std::runtime_error& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    return 0;
}