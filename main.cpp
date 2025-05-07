#include "Library.h"
#include <iostream>

int main() {
    Library lib;
    int choice;

    do {
        std::cout << "\n==== Library Management ====\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.issueBook(); break;
            case 5: lib.returnBook(); break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}