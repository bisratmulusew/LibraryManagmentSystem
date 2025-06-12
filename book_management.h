#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

string genreToString(Genre genre);

class Book {
private:
    string ISBN;
    string title;
    string author;
    Genre genre;
    int quantity;
    BookStatus status;

public:
    Book(const string& isbn, const string& title, const string& author, Genre genre, int quantity);

    void borrow();
    void returnBook();
    void markAsLost();

    BookStatus getStatus() const;
    string getISBN() const;
    string getTitle() const;
    string getAuthor() const;
    Genre getGenre() const;
    int getQuantity() const;

    void setQuantity(int q);
};

class BookManagement {
private:
    vector<Book> books;

public:
    void deleteBook(const string& ISBN);
    void loadBooksFromFile(const string& filename);
    void saveBooksToFile(const string& filename);
    void addBook(const Book& book);
    const std::vector<Book>& getBooks() const;
};

void BookCategoryManagement(const vector<Book>& books);

#endif 

