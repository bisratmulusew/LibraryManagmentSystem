#include <iostream>
#include <string>
#include "book_management.h"
using namespace std;

   Book::Book(const string& title, const string& author)
        : title(title), author(author), status(BookStatus::Available) {}

    void Book::borrow() {
        if (status == BookStatus::Available) {
            status = BookStatus::Borrowed;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is not available for borrowing." << endl;
        }
    }

    void Book::returnBook() {
        if (status == BookStatus::Borrowed) {
            status = BookStatus::Available;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not borrowed." << endl;
        }
    }

    void Book::markAsLost() {
        if (status == BookStatus::Borrowed) {
            status = BookStatus::Lost;
            cout << title << " has been reported lost." << endl;
        } else {
            cout << title << " is not currently borrowed." << endl;
        }
    }

    BookStatus Book::getStatus() const {
       return status;
    }
    string Book::getTitle() const {
    return title;
    }

    string Book::getAuthor() const {
    return author;
    }