#include "FineManagement.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void FineManagement::addFine(const Fine& fine) {
    fines.push_back(fine);
}

void FineManagement::listUnpaidFines() const {
    cout << "Unpaid Fines:\n";
    for (const auto& fine : fines) {
        if (fine.status == UNPAID) {
            cout << "Fine ID: " << fine.fineID
                 << ", Member ID: " << fine.memberID
                 << ", Amount: $" << fine.amount
                 << ", Reason: " << fine.reason << endl;
        }
    }
}

void FineManagement::processPartialPayment(int memberID, double paymentAmount) {
    for (auto& fine : fines) {
        if (fine.memberID == memberID && fine.status == UNPAID) {
            fine.amount -= paymentAmount;
            if (fine.amount <= 0) {
                fine.status = PAID;
                fine.amount = 0;
                cout << "Fine for member " << memberID << " has been fully paid.\n";
            } else {
                cout << "Partial payment processed. Remaining fine: $" << fine.amount << endl;
            }
            return;
        }
    }
    cout << "No unpaid fines found for member " << memberID << ".\n";
}

void FineManagement::loadFinesFromFile() {
    ifstream infile("fines.txt");
    if (!infile) {
        cout << "Cannot open fines.txt for reading.\n";
        return;
    }

    fines.clear();
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        Fine fine;
        int statusInt;
        if (!(iss >> fine.fineID >> fine.memberID >> fine.amount))
            continue;

        string word;
        vector<string> words;
        while (iss >> word)
            words.push_back(word);

        if (words.empty()) continue;

        statusInt = stoi(words.back());
        words.pop_back();

        fine.reason.clear();
        for (size_t i = 0; i < words.size(); ++i) {
            fine.reason += words[i];
            if (i < words.size() - 1)
                fine.reason += " ";
        }

        fine.status = static_cast<FineStatus>(statusInt);
        fines.push_back(fine);
    }
    infile.close();
}

void FineManagement::saveFinesToFile() {
    ofstream outfile("fines.txt");
    if (!outfile) {
        cout << "Cannot open fines.txt for writing.\n";
        return;
    }

    for (const auto& fine : fines) {
        outfile << fine.fineID << " "
                << fine.memberID << " "
                << fine.amount << " "
                << fine.reason << " "
                << static_cast<int>(fine.status) << "\n";
    }

    outfile.close();
}

