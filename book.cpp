#include "Book.h"
#include <iostream>
#include <sstream>

using namespace std;

Book::Book() {}

Book::Book(string isbn, string title, string author, string genre, int quantity)
    : isbn(isbn), title(title), author(author), genre(genre), quantity(quantity) {}

void Book::inputBookDetails() {
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Genre: ";
    getline(cin, genre);
    cout << "Enter Quantity: ";
    cin >> quantity;
    cin.ignore();  // clear newline
}

void Book::displayBook() const {
    cout << "ISBN: " << isbn << "\nTitle: " << title << "\nAuthor: " << author
         << "\nGenre: " << genre << "\nQuantity: " << quantity << "\n";
}

string Book::getISBN() const {
    return isbn;
}

void Book::editBookDetails() {
    cout << "Editing Book...\n";
    inputBookDetails();
}

string Book::toText() const {
    return isbn + "," + title + "," + author + "," + genre + "," + to_string(quantity);
}

Book Book::fromText(const string& line) {
    stringstream ss(line);
    string token;
    string fields[5];
    int i = 0;

    while (getline(ss, token, ',') && i < 5) {
        fields[i++] = token;
    }

    return Book(fields[0], fields[1], fields[2], fields[3], stoi(fields[4]));
}
