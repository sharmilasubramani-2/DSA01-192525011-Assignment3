#include <iostream>

class Book {
private:
    int copies;
    int price;

public:
    Book() : copies(50), price(500) {
        std::cout << "Copies: " << copies << '\n';
        std::cout << "Price: " << price << '\n';
    }
};

int main() {
    Book book;
    return 0;
}