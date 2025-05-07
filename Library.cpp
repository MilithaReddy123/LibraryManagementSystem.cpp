#include "Library.h"
#include <iostream>
#include <fstream>
#include <sstream>

Library::Library() {
    loadFromFile();
}

void Library::loadFromFile() {
    std::ifstream file("books.txt");
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        int id;
        std::string title, author;
        bool status;

        std::string temp;
        getline(ss, temp, '|'); id = stoi(temp);
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, temp, '|'); status = stoi(temp);

        books.push_back(Book(id, title, author, status));
    }
    file.close();
}

void Library::saveToFile() const {
    std::ofstream file("books.txt");
    for (const auto& book : books) {
        file << book.toString() << "\n";
    }
    file.close();
}

void Library::addBook() {
    int id;
    std::string title, author;
    std::cout << "Enter Book ID: "; std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Title: "; getline(std::cin, title);
    std::cout << "Enter Author: "; getline(std::cin, author);
    books.push_back(Book(id, title, author, false));
    saveToFile();
    std::cout << "Book added successfully.\n";
}

void Library::displayBooks() const {
    for (const auto& book : books) {
        book.display();
    }
}

void Library::searchBook() const {
    int searchId;
    std::cout << "Enter Book ID to search: ";
    std::cin >> searchId;

    for (const auto& book : books) {
        if (book.getId() == searchId) {
            book.display();
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::issueBook() {
    int id;
    std::cout << "Enter Book ID to issue: ";
    std::cin >> id;
    for (auto& book : books) {
        if (book.getId() == id) {
            if (!book.getIssuedStatus()) {
                book.issueBook();
                saveToFile();
                std::cout << "Book issued successfully.\n";
            } else {
                std::cout << "Book is already issued.\n";
            }
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::returnBook() {
    int id;
    std::cout << "Enter Book ID to return: ";
    std::cin >> id;
    for (auto& book : books) {
        if (book.getId() == id) {
            if (book.getIssuedStatus()) {
                book.returnBook();
                saveToFile();
                std::cout << "Book returned successfully.\n";
            } else {
                std::cout << "Book was not issued.\n";
            }
            return;
        }
    }
    std::cout << "Book not found.\n";
}