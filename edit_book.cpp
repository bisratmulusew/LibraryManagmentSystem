#include "Book.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Load all books from file
vector<Book> loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error opening file for reading.\n";
        return books;
    }

    while (getline(file, line)) {
        books.push_back(fromText(line));
    }

    return books;
}

// Save all books back to file
void saveBooks(const vector<Book>& books, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (const Book& book : books) {
        file << toText(book) << "\n";
    }
}

// Edit a book identified by ISBN
void editBook(const string& filename) {
    vector<Book> books = loadBooks(filename);

    if (books.empty()) {
        cout << "No books found.\n";
        return;
    }

    string isbnToEdit;
    cout << "Enter ISBN of the book to edit: ";
    getline(cin, isbnToEdit);

    bool found = false;

    for (Book& book : books) {
        if (book.isbn == isbnToEdit) {
            editBookDetails(book);  // Uses Book.cpp logic
            found = true;
            break;
        }
    }

    if (found) {
        saveBooks(books, filename);
        cout << "Book edited successfully.\n";
    } else {
        cout << "Book with ISBN '" << isbnToEdit << "' not found.\n";
    }
}

int main() {
    string filename = "../data/books.txt";
    editBook(filename);
    return 0;
}
