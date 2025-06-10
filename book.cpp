#include "Book.h"
#include <iostream>
using namespace std;

void Book::inputBookDetails() {
    int genreChoice;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter year of publication: ";
    cin >> year;
    cout << "Select genre:\n";
    cout << "0 - Fiction\n";
    cout << "1 - Non-Fiction\n";
    cout << "2 - Mystery\n";
    cout << "3 - Sci-Fi\n";
    cout << "4 - Biography\n";
    cout << "5 - Other\n";
    cout << "Choice: ";
    cin >> genreChoice;
    cin.ignore(); // Clear newline from input buffer
    genre = static_cast<Genre>(genreChoice);
}

string Book::toText() const {
    string genreStr[] = { "Fiction", "Non-Fiction", "Mystery", "Sci-Fi", "Biography", "Other" };
    return title + "," + author + "," + to_string(year) + "," + genreStr[genre];
}
