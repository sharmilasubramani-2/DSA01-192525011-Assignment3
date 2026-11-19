#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>

class Text {
private:
    char* data;
    std::size_t length;
    static int copyCount;

public:
    Text(const char* message = "") {
        if (message == nullptr) {
            message = "";
        }

        length = std::strlen(message);
        data = new char[length + 1];
        std::memcpy(data, message, length + 1);
    }

    Text(const Text& other) : length(other.length) {
        data = new char[length + 1];
        std::memcpy(data, other.data, length + 1);
        ++copyCount;
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            char* newData = new char[other.length + 1];
            std::memcpy(newData, other.data, other.length + 1);

            delete[] data;
            data = newData;
            length = other.length;
        }

        return *this;
    }

    Text operator+(const Text& other) const {
        std::size_t newLength = length + other.length;
        char* combined = new char[newLength + 1];

        std::memcpy(combined, data, length);
        std::memcpy(combined + length, other.data, other.length + 1);

        Text result(combined);
        delete[] combined;

        return result;
    }

    bool operator==(const Text& other) const {
        return std::strcmp(data, other.data) == 0;
    }

    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& out, const Text& text) {
        out << text.data;
        return out;
    }

    static void resetCopyCount() {
        copyCount = 0;
    }

    static int getCopyCount() {
        return copyCount;
    }

    ~Text() {
        delete[] data;
    }
};

int Text::copyCount = 0;

int main() {
    Text first("Hello ");
    Text second("Student");
    Text empty("");

    std::cout << "SMS Gateway - Text Operations\n";

    Text combined = first + second;
    std::cout << "Combined message: " << combined << '\n';

    std::cout << "\nComparison Operations\n";
    std::cout << "first == second: "
              << (first == second ? "True" : "False") << '\n';

    std::cout << "first != second: "
              << (first != second ? "True" : "False") << '\n';

    std::cout << "\nCopy Constructor Test\n";
    Text copied(combined);
    std::cout << "Copied message: " << copied << '\n';

    std::cout << "\nCopy Assignment Test\n";
    Text assigned("Temporary");
    assigned = combined;
    std::cout << "Assigned message: " << assigned << '\n';

    std::cout << "\nSelf Assignment Test\n";
    assigned = assigned;
    std::cout << "After self assignment: " << assigned << '\n';

    std::cout << "\nEmpty Message Test\n";
    Text emptyCombined = empty + first;
    std::cout << "Empty + first: " << emptyCombined << '\n';

    std::cout << "\nLong Message Test\n";
    Text longMessage("This is a long SMS message used to test dynamic memory allocation and safe string operations.");
    std::cout << "Long message: " << longMessage << '\n';

    std::cout << "\nChained Addition Test\n";
    Text third(" Gateway");
    Text::resetCopyCount();

    Text finalMessage = first + second + third;

    std::cout << "Final message: " << finalMessage << '\n';
    std::cout << "Copy constructor calls: "
              << Text::getCopyCount() << '\n';

    std::cout << "\nAll tests completed successfully.\n";

    return 0;
}