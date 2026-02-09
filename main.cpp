#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Person {
public:
    string name;
};


class Member : public Person {
public:
    string memberID;
};


class Book {
public:
    string id;
    string title;
    string author;
    int isIssued; 
};

int main() {
    int choice;
    Book b;
    Member m;

    while (true) {
        cout << "\n LIBRARY SYSTEM MENU ";
        cout << "\n1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Add Member\n6. Display Members\n7. Exit\nChoice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Use numbers.\n";
            cin.clear();
            char dummy; cin >> dummy;
            continue;
        }

        if (choice == 1) {
            cout << "Enter Book ID: "; cin >> b.id;
            
            // Dublicate checker
            bool exists = false;
            string checkID, checkT, checkA;
            int checkS;
            ifstream checkFile("library.txt");
            while (checkFile >> checkID >> checkT >> checkA >> checkS) {
                if (checkID == b.id) {
                    exists = true;
                    break;
                }
            }
            checkFile.close();

            if (exists) {
                cout << "Error: Book ID already exists! Please use a unique ID.\n";
            } else {
                cout << "Title (dont use spaces): "; cin >> b.title;
                cout << "Author (dont use spaces): "; cin >> b.author;
                b.isIssued = 0;

                ofstream file("library.txt", ios::app);
                file << b.id << " " << b.title << " " << b.author << " " << b.isIssued << endl;
                file.close();
                cout << "Book Saved!\n";
            }

        } else if (choice == 2) {
            ifstream file("library.txt");
            cout << "\nID | Title | Author | Status\n";
            while (file >> b.id >> b.title >> b.author >> b.isIssued) {
                cout << b.id << " | " << b.title << " | " << b.author << " | " << (b.isIssued == 1 ? "ISSUED" : "AVAILABLE") << endl;
            }
            file.close();

        } else if (choice == 3) {
            string sID;
            bool found = false;
            cout << "Enter Book ID to Issue: "; cin >> sID;

            ifstream file("library.txt");
            ofstream temp("temp.txt");
            while (file >> b.id >> b.title >> b.author >> b.isIssued) {
                if (b.id == sID) {
                    b.isIssued = 1; 
                    found = true;
                }
                temp << b.id << " " << b.title << " " << b.author << " " << b.isIssued << endl;
            }
            file.close(); temp.close();
            remove("library.txt"); rename("temp.txt", "library.txt");

            if (found) cout << "Book Issued successfully!\n";
            else cout << "Book not found.\n";
        }

        else if (choice == 4) {
            string sID;
            bool found = false;
            cout << "Enter Book ID to Return: "; cin >> sID;

            ifstream file("library.txt");
            ofstream temp("temp.txt");
            while (file >> b.id >> b.title >> b.author >> b.isIssued) {
                if (b.id == sID) {
                    b.isIssued = 0; 
                    found = true;
                }
                temp << b.id << " " << b.title << " " << b.author << " " << b.isIssued << endl;
            }
            file.close(); temp.close();
            remove("library.txt"); rename("temp.txt", "library.txt");

            if (found) cout << "Book Returned successfully!\n";
            else cout << "Book not found.\n";

        } else if (choice == 5) {
            cout << "Enter Member ID: "; cin >> m.memberID;
            // Dublicate checker

            bool exists = false;
            string mID, mName;
            ifstream checkM("members.txt");
            while (checkM >> mID >> mName) {
                if (mID == m.memberID) {
                    exists = true;
                    break;
                }
            }
            checkM.close();

            if (exists) {
                cout << "Error: Member ID already exists!\n";
            } else {
                cout << "Enter Member Name (No_Spaces): "; cin >> m.name;
                ofstream mFile("members.txt", ios::app);
                mFile << m.memberID << " " << m.name << endl;
                mFile.close();
                cout << "Member Added Successfully!\n";
            }

        } else if (choice == 6) {
            ifstream mFile("members.txt");
            cout << "\nMemberID | Name\n";
            while (mFile >> m.memberID >> m.name) {
                cout << m.memberID << " | " << m.name << endl;
            }
            mFile.close();

        } else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}