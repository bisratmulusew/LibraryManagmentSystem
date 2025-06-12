#include "book.h"
#include "Loan.h"
#include "Fine.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Book> loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        books.push_back(Book::fromText(line));

    }
    return books;
}

vector<Loan> loadLoans(const string& filename) {
    vector<Loan> loans;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        loans.push_back(loanFromText(line));
    }
    return loans;
}

vector<Fine> loadFines(const string& filename) {
    vector<Fine> fines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        fines.push_back(fineFromText(line));
    }
    return fines;
}

void showDashboard(const string& bookFile, const string& loanFile, const string& fineFile) {
    vector<Book> books = loadBooks(bookFile);
    vector<Loan> loans = loadLoans(loanFile);
    vector<Fine> fines = loadFines(fineFile);

    int totalBooks = books.size();
    int activeLoans = 0;
    double unpaidFines = 0;

    for (const Loan& loan : loans) {
        if (loan.status == ACTIVE) activeLoans++;
    }

    for (const Fine& fine : fines) {
        if (fine.status != PAID) {
            unpaidFines += (fine.totalAmount - fine.amountPaid);
        }
    }

    cout << "\n--- Library Statistics Dashboard ---\n";
    cout << "Total Books: " << totalBooks << "\n";
    cout << "Active Loans: " << activeLoans << "\n";
    cout << "Total Unpaid Fines: $" << unpaidFines << "\n";
    cout << "-------------------------------------\n";
}

