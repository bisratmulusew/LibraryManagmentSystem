#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include <string>
using namespace std;

enum class BookStatus {
    Available,
    Borrowed,
    Lost
};

class Book {
private:
    string title;
    string author;
    BookStatus status;

public:
    Book(const string& title, const string& author);
    
    void borrow();
    void returnBook();
    void markAsLost();
    
    BookStatus getStatus() const;
    string getTitle() const;
    string getAuthor() const;
};

#endif 