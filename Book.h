#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

public:
    Book();
    Book(int, std::string, std::string, bool);
    void display() const;
    int getId() const;
    std::string getTitle() const;
    bool getIssuedStatus() const;
    void issueBook();
    void returnBook();
    std::string toString() const;
};

#endif