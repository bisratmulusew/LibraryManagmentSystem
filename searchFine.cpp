#include "Fine.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Fine> loadFines(const string& filename) {
    vector<Fine> fines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        fines.push_back(fineFromText(line));
    }
    return fines;
}

void displayFine(const Fine& fine) {
    cout << "Fine ID: " << fine.fineId << "\n";
    cout << "Member ID: " << fine.memberId << "\n";
    cout << "Book ISBN: " << fine.bookISBN << "\n";
    cout << "Total Amount: $" << fine.totalAmount << "\n";
    cout << "Amount Paid: $" << fine.amountPaid << "\n";
    cout << "Status: " << fineStatusToString(fine.status) << "\n\n";
}

void searchFine(const string& filename) {
    vector<Fine> fines = loadFines(filename);
    string keyword;

    cout << "Enter Member ID or Book ISBN to search: ";
    getline(cin, keyword);

    bool found = false;

    for (const Fine& fine : fines) {
        if (fine.memberId == keyword || fine.bookISBN == keyword) {
            displayFine(fine);
            found = true;
        }
    }

    if (!found) {
        cout << "No fines found matching the keyword.\n";
    }
}

int main() {
    string filename = "../data/fines.txt";
    searchFine(filename);
    return 0;
}
