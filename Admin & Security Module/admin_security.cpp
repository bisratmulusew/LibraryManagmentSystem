
#include "admin_security.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <functional>

using namespace std;

string getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buf[100];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

bool verifyPassword(const string& password, const string& hashed) {
    return hashPassword(password) == hashed;
}

string actionTypeToString(AdminActionType type) {
    switch (type) {
        case AdminActionType::BookEdit: return "BookEdit";
        case AdminActionType::MemberDelete: return "MemberDelete";
        case AdminActionType::SystemBackup: return "SystemBackup";
        case AdminActionType::SystemRestore: return "SystemRestore";
        case AdminActionType::Custom: return "Custom";
        default: return "Unknown";
    }
}

void logAdminAction(const string& details, AdminActionType type, const string& adminName) {
    ofstream outFile("admin_logs.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Cannot open log file.\n";
        return;
    }

    outFile << getCurrentTimestamp() << '|'
            << adminName << '|'
            << actionTypeToString(type) << '|'
            << details << '\n';
    outFile.close();
}

vector<AdminActionLog> loadAdminLogs() {
    vector<AdminActionLog> logs;
    ifstream inFile("admin_logs.txt");

    if (!inFile) {
        cerr << "Warning: No log file found.\n";
        return logs;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string timestamp, adminName, typeStr, details;

        getline(ss, timestamp, '|');
        getline(ss, adminName, '|');
        getline(ss, typeStr, '|');
        getline(ss, details);

        AdminActionType type = AdminActionType::Custom;
        if (typeStr == "BookEdit") type = AdminActionType::BookEdit;
        else if (typeStr == "MemberDelete") type = AdminActionType::MemberDelete;
        else if (typeStr == "SystemBackup") type = AdminActionType::SystemBackup;
        else if (typeStr == "SystemRestore") type = AdminActionType::SystemRestore;

        logs.push_back({timestamp, adminName, type, details});
    }

    return logs;
}

bool backupDatabase(const string& backupFile) {
    ofstream out(backupFile, ios::binary);
    if (!out) {
        cerr << "Error: Cannot create backup file.\n";
        return false;
    }

    ifstream books("books.dat", ios::binary);
    ifstream members("members.dat", ios::binary);

    if (!books || !members) {
        cerr << "Error: Cannot open source data files.\n";
        return false;
    }

    out << books.rdbuf();
    out << members.rdbuf();

    books.close();
    members.close();
    out.close();

    logAdminAction("Backup created in file: " + backupFile, AdminActionType::SystemBackup);
    return true;
}

bool restoreDatabase(const string& backupFile) {
    ifstream in(backupFile, ios::binary);
    if (!in) {
        cerr << "Error: Cannot open backup file.\n";
        return false;
    }

    ofstream books("books.dat", ios::binary);
    ofstream members("members.dat", ios::binary);

    if (!books || !members) {
        cerr << "Error: Cannot write to data files.\n";
        return false;
    }

    stringstream buffer;
    buffer << in.rdbuf();
    string data = buffer.str();
    size_t split = data.size() / 2;

    books.write(data.c_str(), split);
    members.write(data.c_str() + split, data.size() - split);

    books.close();
    members.close();
    in.close();

    logAdminAction("Database restored from file: " + backupFile, AdminActionType::SystemRestore);
    return true;
}
