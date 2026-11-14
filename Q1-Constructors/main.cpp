#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class Book {
private:
    std::string title;
    std::string author;
    int copies;

    static int validateCopies(int count) {
        if (count < 0) {
            throw std::invalid_argument("Number of copies cannot be negative.");
        }
        return count;
    }

public:
    Book() : Book("", "", 0) {}

    explicit Book(std::string bookTitle)
        : Book(std::move(bookTitle), "Unknown", 1) {}

    Book(std::string bookTitle, std::string bookAuthor, int bookCopies)
        : title(std::move(bookTitle)),
          author(std::move(bookAuthor)),
          copies(validateCopies(bookCopies)) {}

    Book(const Book& other)
        : Book(other.title, other.author, other.copies) {}

    void display() const {
        std::cout << "Title: "
                  << (title.empty() ? "Empty" : title)
                  << "\nAuthor: "
                  << (author.empty() ? "Unknown" : author)
                  << "\nCopies: " << copies << "\n\n";
    }
};

int main() {
    try {
        Book emptyBook;
        Book donatedBook("Wings of Fire");
        Book fullBook("Atomic Habits", "James Clear", 5);
        Book copiedBook(fullBook);

        std::cout << "DEFAULT CONSTRUCTOR\n";
        emptyBook.display();

        std::cout << "TITLE-ONLY CONSTRUCTOR\n";
        donatedBook.display();

        std::cout << "PARAMETERIZED CONSTRUCTOR\n";
        fullBook.display();

        std::cout << "COPY CONSTRUCTOR\n";
        copiedBook.display();

        std::cout << "INVALID COPY COUNT TEST\n";
        Book invalidBook("Test Book", "Test Author", -3);
        invalidBook.display();
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Validation Error: " << error.what() << '\n';
    }

    return 0;
}