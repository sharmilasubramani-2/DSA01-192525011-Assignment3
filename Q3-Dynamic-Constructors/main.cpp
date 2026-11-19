#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

class Event {
private:
    std::string name;
    int rows;
    int seatsPerRow;
    char** seats;
    int bookedCount;

public:
    Event(const std::string& eventName, int r, int s)
        : name(eventName), rows(r), seatsPerRow(s),
          seats(nullptr), bookedCount(0) {

        if (rows < 0 || seatsPerRow < 0) {
            throw std::invalid_argument("Invalid seat dimensions");
        }

        try {
            if (rows > 0) {
                seats = new char*[rows]{};

                for (int i = 0; i < rows; ++i) {
                    if (seatsPerRow > 0) {
                        seats[i] = new char[seatsPerRow];
                        std::fill_n(seats[i], seatsPerRow, 'O');
                    }
                }
            }
        } catch (...) {
            for (int i = 0; i < rows; ++i) {
                delete[] seats[i];
            }
            delete[] seats;
            throw;
        }

        std::cout << "Created event: " << name << '\n';
    }

    bool bookSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seatsPerRow)
            return false;

        if (seats[r][s] == 'X')
            return false;

        seats[r][s] = 'X';
        ++bookedCount;
        return true;
    }

    bool cancelSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seatsPerRow)
            return false;

        if (seats[r][s] == 'O')
            return false;

        seats[r][s] = 'O';
        --bookedCount;
        return true;
    }

    void display() const {
        std::cout << "Seat map of " << name << ":\n";

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < seatsPerRow; ++j) {
                std::cout << seats[i][j] << ' ';
            }
            std::cout << '\n';
        }

        std::cout << "Booked seats: " << bookedCount << '\n';
    }

    ~Event() {
        for (int i = 0; i < rows; ++i) {
            delete[] seats[i];
        }

        delete[] seats;

        std::cout << "Closed event: " << name
                  << " | Final bookings: " << bookedCount << '\n';
    }
};

int main() {
    std::cout << "Stack Object\n";

    Event first("College Fest", 2, 3);
    first.bookSeat(0, 0);
    first.bookSeat(1, 1);
    first.cancelSeat(0, 0);
    first.display();

    std::cout << "\nBlock Scope Object\n";

    {
        Event second("Workshop", 2, 2);
        second.bookSeat(0, 1);
    }

    std::cout << "\nHeap Object\n";

    Event* third = new Event("Conference", 3, 2);
    third->bookSeat(1, 1);
    third->display();
    delete third;

    std::cout << "\nZero Row Test\n";

    Event fourth("Empty Event", 0, 5);
    fourth.display();

    std::cout << "\nProgram End\n";

    return 0;
}