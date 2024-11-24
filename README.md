
# Theater Management System

The **Theater Management System** is a C++ console-based application designed to simplify theater operations. It offers functionalities for movie management, ticket booking, and cancellation, catering to both theater owners and customers.

---

## Features

### For Theater Owners:
- Add new movies to the schedule.
- Edit movie details (name, time slot, seats, price, screen number).
- Remove movies from the schedule.
- View all movies with their details.

### For Customers:
- View the list of available movies.
- Book tickets for any movie.
- Cancel previously booked tickets.

---

## How It Works

1. **Main Menu**:
   - Choose between **Buyer View** or **Theater Owner View**.
   - Exit the system if no further operations are needed.

2. **Buyer View**:
   - Display all available movies.
   - Select a movie and book tickets by specifying the number of seats.
   - Cancel tickets for a previously booked movie.

3. **Theater Owner View**:
   - Add, edit, or remove movies from the theater's schedule.
   - Display all movies with detailed information.

---

## Prerequisites

To compile and run this project, you need:
- A C++ compiler (e.g., GCC, Clang, or MSVC).
- A C++ development environment (e.g., Code::Blocks, Visual Studio, or an online compiler like Replit).

---

## Compilation and Execution

1. Clone or download the project files.
2. Open a terminal or your IDE.
3. Compile the code using a command like:
   ```bash
   g++ -o TheaterManagement TheaterManagement.cpp
