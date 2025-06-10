#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
private:
    string isbn, title, author, genre;
    int quantity;

public:
    Book();
    Book(string, string, string, string, int);

    void inputBookDetails();
    void displayBook() const;
    string getISBN() const;
    void editBookDetails();

    string toText() const;
    static Book fromText(const string&);
};

#endif
