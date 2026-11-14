#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

public:
    Book(const string& bookTitle = "Empty",
         const string& bookAuthor = "Unknown",
         int bookCopies = 0)
        : title(bookTitle), author(bookAuthor), copies(bookCopies) {}

    void display() const {
        cout << "Title: " << title << '\n';
        cout << "Author: " << author << '\n';
        cout << "Copies: " << copies << "\n\n";
    }
};

int main() {
    Book emptyBook;
    Book donatedBook("Wings of Fire");
    Book fullBook("Atomic Habits", "James Clear", 5);

    cout << "DEFAULT ARGUMENT CONSTRUCTOR\n";
    emptyBook.display();

    cout << "TITLE-ONLY BOOK\n";
    donatedBook.display();

    cout << "FULL BOOK DETAILS\n";
    fullBook.display();

    return 0;
}