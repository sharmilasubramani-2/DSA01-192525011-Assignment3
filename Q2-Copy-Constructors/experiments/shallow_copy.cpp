#include <iostream>

class ShallowCopy {
public:
    int* data;

    explicit ShallowCopy(int value) {
        data = new int(value);
    }

    ShallowCopy(const ShallowCopy& other) {
        data = other.data;
    }
};

int main() {
    ShallowCopy original(100);
    ShallowCopy copied = original;

    std::cout << "Shallow Copy Demonstration\n\n";

    std::cout << "Original value: " << *original.data << '\n';
    std::cout << "Copied value: " << *copied.data << '\n';

    std::cout << "\nOriginal address: " << original.data << '\n';
    std::cout << "Copied address: " << copied.data << '\n';

    copied.data[0] = 250;

    std::cout << "\nAfter modifying copied object:\n";
    std::cout << "Original value: " << *original.data << '\n';
    std::cout << "Copied value: " << *copied.data << '\n';

    delete original.data;
    original.data = nullptr;
    copied.data = nullptr;

    return 0;
}
