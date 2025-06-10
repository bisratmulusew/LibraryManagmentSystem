#include "Book.h"
#include <iostream>
#include <sstream>

using namespace std;

// Function to get book details from user
void inputBookDetails(Book& book) {
    int genreChoice;

    cout << "Enter title: ";
    getline(cin, book.title);

    cout << "Enter author: ";
    getline(cin, book.author);

    cout << "Enter ISBN: ";
    getline(cin, book.isbn);

    cout << "Enter year: ";
    cin >> book.year;

    cout << "Select genre:\n";
    cout << "0 - Fiction\n1 - Non-Fiction\n2 - Mystery\n3 - Sci-Fi\n4 - Biography\n5 - Other\n";
    cout << "Choice: ";
    cin >> genreChoice;
    cin.ignore(); // clear newline from input buffer

    book.genre = static_cast<Genre>(genreChoice);
}

// Function to edit book details (same input as adding)
void editBookDetails(Book& book) {
    cout << "Editing book with ISBN: " << book.isbn << endl;
    inputBookDetails(book);
}

// Convert a book to CSV line
string toText(const Book& book) {
    string genreNames[] = { "Fiction", "Non-Fiction", "Mystery", "Sci-Fi", "Biography", "Other" };
    return book.title + "," + book.author + "," + book.isbn + "," + to_string(book.year) + "," + genreNames[book.genre];
}

// Convert CSV line to Book struct
Book fromText(const string& line) {
    Book book;
    stringstream ss(line);
    string yearStr, genreStr;

    getline(ss, book.title, ',');
    getline(ss, book.author, ',');
    getline(ss, book.isbn, ',');
    getline(ss, yearStr, ',');
    getline(ss, genreStr, ',');

    book.year = stoi(yearStr);

    if (genreStr == "Fiction") book.genre = FICTION;
    else if (genreStr == "Non-Fiction") book.genre = NON_FICTION;
    else if (genreStr == "Mystery") book.genre = MYSTERY;
    else if (genreStr == "Sci-Fi") book.genre = SCI_FI;
    else if (genreStr == "Biography") book.genre = BIOGRAPHY;
    else book.genre = OTHER;

    return book;
}
