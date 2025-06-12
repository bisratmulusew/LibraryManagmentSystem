#include "Admin.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Load admin credentials from file
vector<Admin> loadAdmins(const string& filename) {
    vector<Admin> admins;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error opening admin file.\n";
        return admins;
    }

    while (getline(file, line)) {
        admins.push_back(adminFromText(line));
    }

    return admins;
}

// Verify login
bool verifyLogin(const vector<Admin>& admins, const string& username, const string& password) {
    for (const Admin& admin : admins) {
        if (admin.username == username && admin.password == password) {
            cout << "Login successful. Role: " << roleToString(admin.role) << "\n";
            return true;
        }
    }
    return false;
}

