#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

enum BookStatus {
    AVAILABLE,
    BORROWED,
    LOST
};

struct Book {
    string isbn;
    string title;
    string author;
    string genre;
    int quantity;
    BookStatus status;
};

// Conversion functions
Book bookFromText(const string& line);
string bookToText(const Book& book);
string bookStatusToString(BookStatus status);
BookStatus stringToBookStatus(const string& statusStr);

#endif
