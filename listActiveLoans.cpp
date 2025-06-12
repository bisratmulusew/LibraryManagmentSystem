#include "Loan.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Loan> loadLoans(const string& filename) {
    vector<Loan> loans;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error opening loan file for reading.\n";
        return loans;
    }

    while (getline(file, line)) {
        loans.push_back(loanFromText(line));
    }
    return loans;
}

void listActiveLoans(const string& filename) {
    vector<Loan> loans = loadLoans(filename);

    bool foundActive = false;
    cout << "Active Loans:\n";
    cout << "LoanID | BookISBN | MemberID | Issue Date | Due Date\n";
    cout << "---------------------------------------------------\n";

    for (const Loan& loan : loans) {
        if (loan.status == ACTIVE) {
            foundActive = true;
            cout << loan.loanId << " | "
                 << loan.bookISBN << " | "
                 << loan.memberId << " | "
                 << loanToText(loan).substr(loan.loanId.length() + loan.bookISBN.length() + loan.memberId.length() + 6, 10) << " | "
                 << loanToText(loan).substr(loan.loanId.length() + loan.bookISBN.length() + loan.memberId.length() + 17, 10)
                 << "\n";
        }
    }

    if (!foundActive) {
        cout << "No active loans found.\n";
    }
}


