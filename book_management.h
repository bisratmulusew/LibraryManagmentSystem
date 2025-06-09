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
