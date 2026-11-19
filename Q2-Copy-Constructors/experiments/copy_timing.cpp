#include <iostream>
#include <chrono>

const int SIZE = 1024;
const int ITERATIONS = 10000;

class ShallowBuffer {
public:
    int* data;

    explicit ShallowBuffer(int* source) : data(source) {}

    ShallowBuffer(const ShallowBuffer& other) : data(other.data) {}
};

class DeepBuffer {
public:
    int* data;

    explicit DeepBuffer(int* source) {
        data = new int[SIZE];

        for (int i = 0; i < SIZE; ++i) {
            data[i] = source[i];
        }
    }

    DeepBuffer(const DeepBuffer& other) {
        data = new int[SIZE];

        for (int i = 0; i < SIZE; ++i) {
            data[i] = other.data[i];
        }
    }

    ~DeepBuffer() {
        delete[] data;
    }
};

int main() {
    int source[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        source[i] = i;
    }

    ShallowBuffer shallowSource(source);
    DeepBuffer deepSource(source);

    volatile long long checksum = 0;

    auto shallowStart = std::chrono::steady_clock::now();

    for (int i = 0; i < ITERATIONS; ++i) {
        ShallowBuffer copy(shallowSource);
        checksum = checksum + copy.data[i % SIZE];
    }

    auto shallowEnd = std::chrono::steady_clock::now();

    auto deepStart = std::chrono::steady_clock::now();

    for (int i = 0; i < ITERATIONS; ++i) {
        DeepBuffer copy(deepSource);
        checksum = checksum + copy.data[i % SIZE];
    }

    auto deepEnd = std::chrono::steady_clock::now();

    auto shallowTime =
        std::chrono::duration<double, std::milli>(
            shallowEnd - shallowStart).count();

    auto deepTime =
        std::chrono::duration<double, std::milli>(
            deepEnd - deepStart).count();

    std::cout << "Copy Performance Comparison\n\n";

    std::cout << "Iterations: " << ITERATIONS << '\n';
    std::cout << "Array size: " << SIZE << " integers\n\n";

    std::cout << "Shallow copy time: "
              << shallowTime << " ms\n";

    std::cout << "Deep copy time: "
              << deepTime << " ms\n";

    std::cout << "\nChecksum: " << checksum << '\n';

    return 0;
}
