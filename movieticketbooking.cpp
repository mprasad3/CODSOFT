#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;

class MovieTicketBookingSystem {
private:
    vector<vector <bool> > seats;
    double ticketPrice;

public:
    MovieTicketBookingSystem(double price) : ticketPrice(price) {
        seats.assign(NUM_ROWS, vector<bool>(NUM_COLS, true));
    }

    void displaySeats() {
        cout << "Available Seats:\n";
        cout << "----------------\n";

        for (int row = 0; row < NUM_ROWS; ++row) {
            for (int col = 0; col < NUM_COLS; ++col) {
                cout << (seats[row][col] ? "O" : "X") << " ";
            }
            cout << endl;
        }

        cout << "----------------\n";
    }

    bool bookSeat(int row, int col) {
        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            cout << "Invalid seat selection. Please try again.\n";
            return false;
        }

        if (seats[row][col]) {
            seats[row][col] = false;
            cout << "Seat booked successfully.\n";
            return true;
        } else {
            cout << "This seat is already booked. Please choose another seat.\n";
            return false;
        }
    }

    double calculateTotalCost(int numSeats) {
        return numSeats * ticketPrice;
    }
};

int main() {
    MovieTicketBookingSystem bookingSystem(10.0); // Ticket price

    int choice;
    do {
        cout << "Movie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Book Seats\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.displaySeats();
                break;
            case 2: {
                int row, col, numSeats;
                cout << "Enter row and column for the first seat (0-based): ";
                cin >> row >> col;
                cout << "Enter the number of seats to book: ";
                cin >> numSeats;

                double totalCost = 0.0;
                for (int i = 0; i < numSeats; ++i) {
                    bookingSystem.displaySeats();
                    if (bookingSystem.bookSeat(row, col)) {
                        totalCost += bookingSystem.calculateTotalCost(1);
                    }
                    cout << "Total cost so far: $" << fixed << setprecision(2) << totalCost << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
