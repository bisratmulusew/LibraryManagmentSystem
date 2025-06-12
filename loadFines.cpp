#include "Fine.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Fine> loadFines(const string& filename) {
    vector<Fine> fines;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error opening fine file.\n";
        return fines;
    }

    while (getline(file, line)) {
        fines.push_back(fineFromText(line));
    }

    return fines;
}


