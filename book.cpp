#include "Book.h"
#include <sstream>

Book bookFromText(const string& line) {
    Book book;
    stringstream ss(line);
    string qtyStr, statusStr;

    getline(ss, book.isbn, ',');
    getline(ss, book.title, ',');
    getline(ss, book.author, ',');
    getline(ss, book.genre, ',');
    getline(ss, qtyStr, ',');
    getline(ss, statusStr, ',');

    book.quantity = stoi(qtyStr);
    book.status = stringToBookStatus(statusStr);
    return book;
}

string bookToText(const Book& book) {
    return book.isbn + "," + book.title + "," + book.author + "," +
           book.genre + "," + to_string(book.quantity) + "," +
           bookStatusToString(book.status);
}

string bookStatusToString(BookStatus status) {
    switch (status) {
        case AVAILABLE: return "Available";
        case BORROWED: return "Borrowed";
        case LOST: return "Lost";
        default: return "Unknown";
    }
}

BookStatus stringToBookStatus(const string& statusStr) {
    if (statusStr == "Available") return AVAILABLE;
    if (statusStr == "Borrowed") return BORROWED;
    if (statusStr == "Lost") return LOST;
    return AVAILABLE; // Default
}
