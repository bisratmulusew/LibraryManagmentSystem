#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

enum Genre {
    FICTION,
    NON_FICTION,
    MYSTERY,
    SCI_FI,
    BIOGRAPHY,
    OTHER
};

struct Book {
    string title;
    string author;
    int year;
    Genre genre;

void inputBookDetails();
void editBookDetails(Book& book);          
string toText(const Book& book);         
Book fromText(const string& line);              

#endif
