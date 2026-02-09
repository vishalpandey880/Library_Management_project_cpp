# Library Management System

A simple console-based Library Management System written in C++. This application allows you to manage books and members, as well as issue and return books.

## Features

- **Add Book**: Add new books with a unique ID, title, and author.
- **Display Books**: View a list of all books along with their current status (Available or Issued).
- **Issue Book**: valid member can borrow a book (functionality to link to member is not fully enforced, currently just marks book as issued).
- **Return Book**: Return a borrowed book to make it available again.
- **Add Member**: Register new library members with a unique ID and name.
- **Display Members**: View a list of all registered members.
- **Data Persistence**: All data is saved in text files (`library.txt` and `members.txt`), so your records are kept even after closing the program.

## Prerequisites

- A C++ compiler (like GCC or Clang).

## Compilation

To compile the program, open your terminal and run the following command:

```bash
g++ main.cpp -o library_system
```

## Usage

1. Run the compiled executable:
   ```bash
   ./library_system
   ```

2. The main menu will appear:
   ```
    LIBRARY SYSTEM MENU 
   1. Add Book
   2. Display Books
   3. Issue Book
   4. Return Book
   5. Add Member
   6. Display Members
   7. Exit
   ```

3. Enter the number corresponding to the action you want to perform.

### Important Note on Input
- When entering the **Title**, **Author**, or **Member Name**, strictly **do not use spaces**.
- Use underscores (`_`) or hyphens (`-`) instead (e.g., `Harry_Potter`, `JK-Rowling`).
- The program uses standard inputs that stop reading at whitespace.

## File Structure

- `main.cpp`: The main source code file.
- `library.txt`: Stores book records (ID, Title, Author, Status). Created automatically.
- `members.txt`: Stores member records (ID, Name). Created automatically.
