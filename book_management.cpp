#include "book_management.h"
#include <iostream>
#include <algorithm> 
using namespace std;

book::book(string t, string g) {
    title = t;
    genre = g;
}

void BookCategoryManagment(vector<book>& books) {
    sort(books.begin(), books.end(), [](const book& a, const  book& b) {
        return a.genre < b.genre;
    });
}