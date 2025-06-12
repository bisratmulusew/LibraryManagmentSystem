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


