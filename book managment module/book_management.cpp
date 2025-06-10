#include "book_management.h"
#include <iostream>
using namespace std;

// Constructor updated to include genre
Book::Book(const string& title, const string& author, Genre genre)
    : title(title), author(author), status(BookStatus::Available), genre(genre) {}

    
void Book::borrow() {
    if (status == BookStatus::Available) {
        status = BookStatus::Borrowed;
        cout << title << " has been borrowed." << endl;
    } else {
        cout << title << " is not available for borrowing." << endl;
    }
}

void Book::returnBook() {
    if (status == BookStatus::Borrowed) {
        status = BookStatus::Available;
        cout << title << " has been returned." << endl;
    } else {
        cout << title << " was not borrowed." << endl;
    }
}

void Book::markAsLost() {
    if (status == BookStatus::Borrowed) {
        status = BookStatus::Lost;
        cout << title << " has been reported lost." << endl;
    } else {
        cout << title << " is not currently borrowed." << endl;
    }
}

BookStatus Book::getStatus() const {
    return status;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

Genre Book::getGenre() const {
    return genre;
}

string genreToString(Genre genre) {
    switch (genre) {
        case FICTION: return "Fiction";
        case NONFICTION: return "Non-Fiction";
        case SCIENCE: return "Science";
        case HISTORY: return "History";
        case OTHER: return "Other";
        default: return "Unknown";
    }
}

void BookCategoryManagement(const vector<Book>& books) {
    cout << "Books Organized by Genre:\n";
    for (int g = 0; g < GENRE_COUNT; g++) {
        Genre genre = static_cast<Genre>(g);
        cout << "\n[" << genreToString(genre) << "]\n";
        bool found = false;
        for (const auto& book : books) {
            if (book.getGenre() == genre) {
                cout << " - " << book.getTitle() << endl;
                found = true;
            }
        }
        if (!found) {
            cout << " (No books in this category)\n";
        }
    }
}

