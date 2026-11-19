#include <iostream>
#include <string>
#include <stdexcept>

class Prescription {
    int n;
    std::string* medicines;

public:
    explicit Prescription(int count)
        : n(count),
          medicines(count >= 0 ? new std::string[count] : throw std::invalid_argument("Medicine count cannot be negative")) {}

    Prescription(const Prescription& other)
        : n(other.n), medicines(new std::string[other.n]) {
        for (int i = 0; i < n; ++i) {
            medicines[i] = other.medicines[i];
        }
    }

    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            std::string* newMedicines = new std::string[other.n];

            for (int i = 0; i < other.n; ++i) {
                newMedicines[i] = other.medicines[i];
            }

            delete[] medicines;
            medicines = newMedicines;
            n = other.n;
        }

        return *this;
    }

    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const std::string& m) {
        if (i >= 0 && i < n) {
            medicines[i] = m;
        }
    }

    std::string get(int i) const {
        if (i >= 0 && i < n) {
            return medicines[i];
        }

        throw std::out_of_range("Invalid medicine index");
    }
};

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;

    q.set(1, "Cetirizine");

    Prescription r(1);

    r = p;

    p.set(0, "Ibuprofen");

    std::cout << p.get(0) << ' ' << p.get(1)
              << " | " << q.get(0) << ' ' << q.get(1)
              << " | " << r.get(0) << ' ' << r.get(1) << '\n';

    p = p;
}