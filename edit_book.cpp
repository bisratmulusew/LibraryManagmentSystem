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
        books.push_back(Book::fromText(line));
    }

    return books;
}

void saveBooks(const vector<Book>& books, const string& filename) {
    ofstream file(filename);
    for (const Book& book : books) {
        file << book.toText() << "\n";
    }
}

void editBook(const string& filename) {
    vector<Book> books = loadBooks(filename);
    string isbn;
    cout << "Enter ISBN of the book to edit: ";
    getline(cin, isbn);

    bool found = false;
    for (Book& book : books) {
        if (book.getISBN() == isbn) {
            book.editBookDetails();
            found = true;
            break;
        }
    }

    if (found) {
        saveBooks(books, filename);
        cout << "Book edited successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

int main() {
    string filename = "../data/books.txt";
    editBook(filename);
    return 0;
}
