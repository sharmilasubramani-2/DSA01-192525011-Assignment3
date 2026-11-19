#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r) : real(r), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) const {
        double denominator =
            other.real * other.real + other.imag * other.imag;

        if (denominator == 0.0) {
            throw std::runtime_error("Division by zero impedance");
        }

        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    bool operator==(const Complex& other) const {
        const double epsilon = 1e-9;

        return std::abs(real - other.real) < epsilon &&
               std::abs(imag - other.imag) < epsilon;
    }

    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    friend std::ostream& operator<<(std::ostream& out,
                                    const Complex& value) {
        out << value.real;

        if (value.imag >= 0)
            out << " + " << value.imag << "i";
        else
            out << " - " << std::abs(value.imag) << "i";

        return out;
    }
};

Complex parallelImpedance(const Complex& z1, const Complex& z2) {
    return (z1 * z2) / (z1 + z2);
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Complex a(4, 3);
    Complex b(2, -1);

    std::cout << "AC Impedance Calculator\n";

    std::cout << "\nComplex Numbers\n";
    std::cout << "Z1: " << a << '\n';
    std::cout << "Z2: " << b << '\n';

    std::cout << "\nArithmetic Operations\n";
    std::cout << "Addition: " << a + b << '\n';
    std::cout << "Subtraction: " << a - b << '\n';
    std::cout << "Multiplication: " << a * b << '\n';
    std::cout << "Division: " << a / b << '\n';

    std::cout << "\nMagnitude\n";
    std::cout << "|Z1|: " << a.magnitude() << '\n';

    std::cout << "\nEquality Comparison\n";
    std::cout << "Z1 == Z2: "
              << (a == b ? "True" : "False") << '\n';

    std::cout << "\nSeries RLC Impedance\n";

    Complex resistance(4, 0);
    Complex inductive(0, 3);
    Complex capacitive(0, -1);

    Complex series = resistance + inductive + capacitive;

    std::cout << "Resistance: " << resistance << '\n';
    std::cout << "Inductive impedance: " << inductive << '\n';
    std::cout << "Capacitive impedance: " << capacitive << '\n';
    std::cout << "Total series impedance: " << series << '\n';
    std::cout << "Magnitude: " << series.magnitude() << '\n';

    std::cout << "\nParallel Impedance\n";

    Complex branch1(4, 2);
    Complex branch2(2, -1);

    Complex parallel = parallelImpedance(branch1, branch2);

    std::cout << "Branch 1: " << branch1 << '\n';
    std::cout << "Branch 2: " << branch2 << '\n';
    std::cout << "Equivalent impedance: " << parallel << '\n';
    std::cout << "Magnitude: " << parallel.magnitude() << '\n';

    std::cout << "\nZero Impedance Division Test\n";

    try {
        Complex zero;
        Complex result = a / zero;
        std::cout << result << '\n';
    }
    catch (const std::runtime_error& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    std::cout << "\nAll tests completed successfully.\n";

    return 0;
}