<<<<<<< HEAD
#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
struct Book {
    std::string ISBN;
    std::string title;
    std::string author;
    std::string genre;
    int quantity;
};

class BookManagement {
public:
    void deleteBook(const std::string& ISBN);
    void loadBooksFromFile(const std::string& filename);
    void saveBooksToFile(const std::string& filename);
private:
    std::vector<Book> books;
};

#endif // BOOKMANAGEMENT_H
=======
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

>>>>>>> main
