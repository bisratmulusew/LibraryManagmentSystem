#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include <string>
#include <vector>
using namespace std;

enum Genre {
    FICTION,
    NONFICTION,
    SCIENCE,
    HISTORY,
    OTHER,
    GENRE_COUNT  
};

struct Book {
    string title;
    Genre genre;
};

void BookCategoryManagement(const vector<Book>& books);
string genreToString(Genre genre);

#endif

