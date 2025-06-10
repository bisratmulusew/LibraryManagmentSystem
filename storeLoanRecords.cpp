#include "Loan.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Save all loans to file
void saveLoans(const vector<Loan>& loans, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening loan file for writing.\n";
        return;
    }

    for (const Loan& loan : loans) {
        file << loanToText(loan) << "\n";
    }
}

int main() {
    string filename = "../data/loans.txt";

    // For demonstration, let's load loans first, then save them back (you can modify this as needed)
    vector<Loan> loans;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        loans.push_back(loanFromText(line));
    }

    saveLoans(loans, filename);

    cout << "Loan records saved successfully.\n";
    return 0;
}
