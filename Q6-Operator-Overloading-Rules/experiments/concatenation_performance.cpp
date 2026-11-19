#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

const int ITERATIONS = 100000;

class Text {
private:
    char* data;
    std::size_t length;

public:
    Text(const char* message = "") {
        length = std::strlen(message);
        data = new char[length + 1];
        std::memcpy(data, message, length + 1);
    }

    Text(const Text& other) : length(other.length) {
        data = new char[length + 1];
        std::memcpy(data, other.data, length + 1);
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

    std::size_t size() const {
        return length;
    }

    ~Text() {
        delete[] data;
    }
};

int main() {
    Text first("Mobile ");
    Text second("Computing");

    std::string standardFirst = "Mobile ";
    std::string standardSecond = "Computing";

    volatile std::size_t checksum = 0;

    auto customStart = std::chrono::steady_clock::now();

    for (int i = 0; i < ITERATIONS; ++i) {
        Text result = first + second;
        checksum = checksum + result.size();
    }

    auto customEnd = std::chrono::steady_clock::now();

    auto standardStart = std::chrono::steady_clock::now();

    for (int i = 0; i < ITERATIONS; ++i) {
        std::string result = standardFirst + standardSecond;
        checksum = checksum + result.size();
    }

    auto standardEnd = std::chrono::steady_clock::now();

    double customTime =
        std::chrono::duration<double, std::milli>(
            customEnd - customStart).count();

    double standardTime =
        std::chrono::duration<double, std::milli>(
            standardEnd - standardStart).count();

    std::cout << "String Concatenation Performance\n\n";
    std::cout << "Iterations: " << ITERATIONS << '\n';

    std::cout << "\nCustom Text class: "
              << customTime << " ms\n";

    std::cout << "Standard string: "
              << standardTime << " ms\n";

    std::cout << "\nChecksum: " << checksum << '\n';

    return 0;
}