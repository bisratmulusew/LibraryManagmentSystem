#include "book_management.h"

void book_management::deleteBook(const std::string& ISBN) {
    auto it = std::remove_if(books.begin(), books.end(), [&](const Book& book) {
        return book.ISBN == ISBN;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Book with ISBN " << ISBN << " has been deleted." << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }
}

// Implement the loadbooks From File and saveBooksToFile as needed
