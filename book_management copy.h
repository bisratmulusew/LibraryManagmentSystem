#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include <string>
#include <vector>

struct Book {
    std::string ISBN;
    std::string title;
    std::string author;
    std::string genre;
    int quantity;
};

class BookManager {
private:
    std::vector<Book> books;

public:
    void searchBook();
    void deleteBook();
    
};

#endif
