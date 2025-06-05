#include "book_management.h"
#include <iostream>
using namespace std;

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
            if (book.genre == genre) {
                cout << " - " << book.title << endl;
                found = true;
            }
        }
        if (!found) {
            cout << " (No books in this category)\n";
        }
    }
}
