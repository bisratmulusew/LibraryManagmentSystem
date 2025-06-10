#include "Book.h"
#include <fstream>
#include <iostream>

using namespace std;

void addBook(const string& filename) {
    Book newBook;
    inputBookDetails(newBook);  // from Book.cpp

    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    file << toText(newBook) << "\n";  // from Book.cpp
    cout << "Book added successfully.\n";
}

int main() {
    string filename = "../data/books.txt";
    addBook(filename);
    return 0;
}
