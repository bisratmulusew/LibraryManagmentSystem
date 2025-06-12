#include "Book.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Book> loadBooks(const string& filename) {
    ifstream file(filename);
    vector<Book> books;
    string line;

    while (getline(file, line)) {
        books.push_back(bookFromText(line));
    }

    return books;
}

void listAllBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books found.\n";
        return;
    }

    cout << "All Available Books:\n";
    for (const Book& book : books) {
        cout << "ISBN: " << book.isbn << "\n"
             << "Title: " << book.title << "\n"
             << "Author: " << book.author << "\n"
             << "Genre: " << book.genre << "\n"
             << "Quantity: " << book.quantity << "\n"
             << "Status: " << bookStatusToString(book.status) << "\n\n";
    }
}


