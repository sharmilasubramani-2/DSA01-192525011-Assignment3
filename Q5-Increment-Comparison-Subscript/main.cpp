#include <iostream>
#include <vector>
#include <stdexcept>

class NumberList {
private:
    int value;
    std::vector<int> elements;

public:
    NumberList(int v, const std::vector<int>& data)
        : value(v), elements(data) {}

    NumberList& operator++() {
        ++value;
        return *this;
    }

    NumberList operator++(int) {
        NumberList temp = *this;
        ++value;
        return temp;
    }

    bool operator==(const NumberList& other) const {
        return value == other.value;
    }

    bool operator>(const NumberList& other) const {
        return value > other.value;
    }

    int& operator[](std::size_t index) {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const int& operator[](std::size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    int getValue() const {
        return value;
    }

    void display() const {
        std::cout << "Value: " << value << '\n';
        std::cout << "Elements: ";

        for (int element : elements) {
            std::cout << element << ' ';
        }

        std::cout << '\n';
    }
};

int main() {
    NumberList first(10, {10, 20, 30, 40});
    NumberList second(15, {5, 15, 25, 35});

    std::cout << "Initial Objects\n";
    first.display();
    second.display();

    std::cout << "\nPrefix Increment\n";
    ++first;
    std::cout << "First value: " << first.getValue() << '\n';

    std::cout << "\nPostfix Increment\n";
    NumberList previous = second++;
    std::cout << "Previous value: " << previous.getValue() << '\n';
    std::cout << "Current value: " << second.getValue() << '\n';

    std::cout << "\nComparison Operators\n";
    std::cout << "First == Second: "
              << (first == second ? "True" : "False") << '\n';
    std::cout << "First > Second: "
              << (first > second ? "True" : "False") << '\n';

    std::cout << "\nSubscript Operator\n";
    std::cout << "First element: " << first[0] << '\n';
    std::cout << "Third element: " << first[2] << '\n';

    first[1] = 99;
    std::cout << "Modified second element: " << first[1] << '\n';

    std::cout << "\nBounds Checking\n";

    try {
        std::cout << first[10] << '\n';
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    return 0;
}