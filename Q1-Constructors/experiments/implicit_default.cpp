#include <iostream>

class Book {
public:
    void display() const {
        std::cout << "Compiler-generated default constructor works.\n";
    }
};

int main() {
    Book books[3];

    for (const Book& book : books) {
        book.display();
    }

    return 0;
}