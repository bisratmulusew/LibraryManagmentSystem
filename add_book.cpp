#include "Book.h"
#include <fstream>
#include <iostream>

using namespace std;

void addBook(const string& filename) {
    Book newBook;
    newBook.inputBookDetails();

    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    file << newBook.toText() << "\n";
    cout << "Book added successfully.\n";
}

int main() {
    string filename = "../data/books.txt";
    addBook(filename);
    return 0;
}
