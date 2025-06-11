#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include <string>
#include <vector>
using namespace std;

enum class BookStatus {
    Available,
    Borrowed,
    Lost
};

enum Genre {
    FICTION,
    NONFICTION,
    SCIENCE,
    HISTORY,
    OTHER,
    GENRE_COUNT  
};

class Book {
private:
    string title;
    string author;
    BookStatus status;
    Genre genre;

public:
    Book(const string& title, const string& author, Genre genre);

    void borrow();
    void returnBook();
    void markAsLost();

    BookStatus getStatus() const;
    string getTitle() const;
    string getAuthor() const;
    Genre getGenre() const;
};

void BookCategoryManagement(const vector<Book>& books);
string genreToString(Genre genre);

#endif

