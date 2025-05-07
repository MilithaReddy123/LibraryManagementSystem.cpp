#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;
    void loadFromFile();
    void saveToFile() const;

public:
    Library();
    void addBook();
    void displayBooks() const;
    void searchBook() const;
    void issueBook();
    void returnBook();
};

#endif