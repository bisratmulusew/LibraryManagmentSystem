#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include <string>
#include <vector>
using namespace std;

class book {
public:
    string title;
    string genre;

    book(string t, string g);
};
void BookCategoryManagment(vector<book>& books);


#endif
