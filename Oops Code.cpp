#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
public:
    string name, timeSlot;
    int totalSeats, screen;
    double price;

    Movie(string name, string timeSlot, int seats, double price, int screen)
        : name(name), timeSlot(timeSlot), totalSeats(seats), price(price), screen(screen) {}

    void displayDetails() {
        cout << "Movie: " << name << ", Time: " << timeSlot 
             << ", Seats: " << totalSeats << ", Price: $" << price 
             << ", Screen: " << screen << endl;
    }

    bool bookSeats(int seats) {
        if (seats <= totalSeats) {
            totalSeats -= seats;
            cout << seats << " seats booked for " << name << " at " << timeSlot << ".\n";
            return true;
        }
        cout << "Not enough seats available!\n";
        return false;
    }

    void cancelSeats(int seats) {
        totalSeats += seats;
        cout << seats << " seats canceled for " << name << " at " << timeSlot << ".\n";
    }
};

class Theater {
public:
    string theaterName;
    vector<Movie> movies;

    Theater(string name) : theaterName(name) {}

    void addMovie(string name, string time, int seats, double price, int screen) {
        movies.push_back(Movie(name, time, seats, price, screen));
    }

    void removeMovie(int index) {
        if (index >= 0 && index < movies.size()) {
            cout << "Removing " << movies[index].name << " from schedule.\n";
            movies.erase(movies.begin() + index);
        } else {
            cout << "Invalid movie index.\n";
        }
    }

    void displayMovies() {
        cout << "--- Movies in " << theaterName << " ---\n";
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". ";
            movies[i].displayDetails();
        }
    }

    void editMovie(int index, string name, string time, int seats, double price, int screen) {
        if (index >= 0 && index < movies.size()) {
            movies[index] = Movie(name, time, seats, price, screen);
            cout << "Movie updated successfully.\n";
        } else {
            cout << "Invalid movie index.\n";
        }
    }

    void bookMovieTicket(int movieIndex, int seats) {
        if (movieIndex >= 0 && movieIndex < movies.size()) {
            if (!movies[movieIndex].bookSeats(seats)) {
                cout << "Booking failed.\n";
            }
        } else {
            cout << "Invalid movie selection.\n";
        }
    }

    void cancelMovieTicket(int movieIndex, int seats) {
        if (movieIndex >= 0 && movieIndex < movies.size()) {
            movies[movieIndex].cancelSeats(seats);
        } else {
            cout << "Invalid movie selection.\n";
        }
    }
};

void buyerView(Theater &theater) {
    int choice;
    do {
        cout << "\n--- Buyer Menu ---\n";
        cout << "1. Display Movies\n2. Book Tickets\n3. Cancel Booking\n4. Exit Buyer Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                theater.displayMovies();
                break;
            case 2: {
                int movieIndex, seats;
                theater.displayMovies();
                cout << "Select movie by index: ";
                cin >> movieIndex;
                cout << "Enter number of seats: ";
                cin >> seats;
                theater.bookMovieTicket(movieIndex - 1, seats);
                break;
            }
            case 3: {
                int movieIndex, seats;
                theater.displayMovies();
                cout << "Select movie by index: ";
                cin >> movieIndex;
                cout << "Enter number of seats to cancel: ";
                cin >> seats;
                theater.cancelMovieTicket(movieIndex - 1, seats);
                break;
            }
            case 4:
                cout << "Exiting Buyer Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

void theaterOwnerView(Theater &theater) {
    int choice;
    do {
        cout << "\n--- Theater Owner Menu ---\n";
        cout << "1. Add Movie\n2. Remove Movie\n3. Edit Movie\n4. Display Movies\n5. Exit Theater Owner Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, time;
                int seats, screen;
                double price;
                cout << "Enter movie name: ";
                cin >> ws;
                getline(cin, name);
                cout << "Enter time slot: ";
                getline(cin, time);
                cout << "Enter total seats: ";
                cin >> seats;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter screen number: ";
                cin >> screen;
                theater.addMovie(name, time, seats, price, screen);
                break;
            }
            case 2: {
                int movieIndex;
                theater.displayMovies();
                cout << "Select movie to remove by index: ";
                cin >> movieIndex;
                theater.removeMovie(movieIndex - 1);
                break;
            }
            case 3: {
                int movieIndex, seats, screen;
                string name, time;
                double price;
                theater.displayMovies();
                cout << "Select movie to edit by index: ";
                cin >> movieIndex;
                cout << "Enter new movie name: ";
                cin >> ws;
                getline(cin, name);
                cout << "Enter new time slot: ";
                getline(cin, time);
                cout << "Enter total seats: ";
                cin >> seats;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter screen number: ";
                cin >> screen;
                theater.editMovie(movieIndex - 1, name, time, seats, price, screen);
                break;
            }
            case 4:
                theater.displayMovies();
                break;
            case 5:
                cout << "Exiting Theater Owner Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    Theater theater("City Cinema");

    // Adding initial movies
    theater.addMovie("Movie A", "10:00 AM", 100, 10.0, 1);
    theater.addMovie("Movie B", "2:00 PM", 80, 12.0, 1);
    theater.addMovie("Movie C", "6:00 PM", 50, 15.0, 1);

    int mainChoice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Buyer View\n2. Theater Owner View\n3. Exit System\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                buyerView(theater);
                break;
            case 2:
                theaterOwnerView(theater);
                break;
            case 3:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}