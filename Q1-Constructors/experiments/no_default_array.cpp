#include <string>

class Book {
private:
    std::string title;

public:
    explicit Book(const std::string& bookTitle) : title(bookTitle) {}
};

int main() {
    Book books[3];
    return 0;
}