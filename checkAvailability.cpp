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

void checkBookAvailability(const vector<Book>& books, const string& isbn) {
    for (const Book& book : books) {
        if (book.isbn == isbn) {
            if (book.quantity > 0 && book.status == AVAILABLE) {
                cout << "✅ Book is available: " << book.title << "\n";
            } else {
                cout << "❌ Book is not available (status: " << bookStatusToString(book.status)
                     << ", quantity: " << book.quantity << ")\n";
            }
            return;
        }
    }
    cout << "❌ Book with ISBN " << isbn << " not found.\n";
}

int main() {
    string filename = "../data/books.txt";
    vector<Book> books = loadBooks(filename);

    string isbn;
    cout << "Enter ISBN to check availability: ";
    getline(cin, isbn);

    checkBookAvailability(books, isbn);
    return 0;
}
