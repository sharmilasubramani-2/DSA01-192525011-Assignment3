#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;

public:
     Book(const char* bookTitle) : title(bookTitle) {}

    void display() const {
        cout << "Book: " << title << '\n';
    }
};

int main() {
    Book book("Wings of Fire");
    book.display();

    Book anotherBook = "Atomic Habits";
    anotherBook.display();

    return 0;
}