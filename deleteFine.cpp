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

void saveFines(const vector<Fine>& fines, const string& filename) {
    ofstream file(filename);
    for (const Fine& fine : fines) {
        file << fineToText(fine) << "\n";
    }
}

void deleteFine(const string& filename) {
    vector<Fine> fines = loadFines(filename);
    string fineId;

    cout << "Enter Fine ID to delete: ";
    getline(cin, fineId);

    bool deleted = false;
    vector<Fine> updatedFines;

    for (const Fine& fine : fines) {
        if (fine.fineId != fineId) {
            updatedFines.push_back(fine);
        } else {
            deleted = true;
        }
    }

    if (deleted) {
        saveFines(updatedFines, filename);
        cout << "Fine deleted successfully.\n";
    } else {
        cout << "Fine ID not found.\n";
    }
}

