#include "Fine.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Load fines from file (same as in loadFines.cpp)
vector<Fine> loadFines(const string& filename) {
    vector<Fine> fines;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error reading fine file.\n";
        return fines;
    }

    while (getline(file, line)) {
        fines.push_back(fineFromText(line));
    }

    return fines;
}

// Save fines to file
void saveFines(const vector<Fine>& fines, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error writing fine file.\n";
        return;
    }

    for (const Fine& fine : fines) {
        file << fineToText(fine) << "\n";
    }
}

void processFinePayment(vector<Fine>& fines) {
    string fineId;
    double amount;

    cout << "Enter Fine ID to pay: ";
    getline(cin, fineId);

    bool found = false;
    for (Fine& fine : fines) {
        if (fine.fineId == fineId) {
            found = true;

            cout << "Fine Amount: $" << fine.totalAmount << "\n";
            cout << "Already Paid: $" << fine.amountPaid << "\n";
            cout << "Enter amount to pay: $";
            cin >> amount;
            cin.ignore();

            fine.amountPaid += amount;

            if (fine.amountPaid >= fine.totalAmount) {
                fine.amountPaid = fine.totalAmount; 
                fine.status = PAID;
            } else {
                fine.status = PARTIALLY_PAID;
            }

            cout << "Payment processed. New paid amount: $" << fine.amountPaid << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Fine ID not found.\n";
    }
}

int main() {
    string filename = "../data/fines.txt";

    vector<Fine> fines = loadFines(filename);
    if (fines.empty()) {
        cout << "No fines found.\n";
        return 0;
    }

    processFinePayment(fines);
    saveFines(fines, filename);

    return 0;
}
