#include "Book.h"
#include <iostream>
#include <sstream>

Book::Book() : id(0), title(""), author(""), isIssued(false) {}

Book::Book(int id, std::string title, std::string author, bool status)
    : id(id), title(title), author(author), isIssued(status) {}

void Book::display() const {
    std::cout << "ID: " << id << ", Title: " << title
              << ", Author: " << author
              << ", Status: " << (isIssued ? "Issued" : "Available") << "\n";
}

int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

bool Book::getIssuedStatus() const {
    return isIssued;
}

void Book::issueBook() {
    isIssued = true;
}

void Book::returnBook() {
    isIssued = false;
}

std::string Book::toString() const {
    std::stringstream ss;
    ss << id << "|" << title << "|" << author << "|" << isIssued;
    return ss.str();
}