#include "AuditLog.h"
#include <fstream>
#include <iostream>

using namespace std;

void logAction(const string& username, const string& object, const string& id, ActionType action, const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error writing to audit log.\n";
        return;
    }

    AuditLog log;
    log.username = username;
    log.actionObject = object;
    log.objectId = id;
    log.action = action;
    log.timestamp = time(nullptr);

    file << auditLogToText(log) << "\n";
    cout << "Audit log recorded.\n";
}

int main() {
    string filename = "../data/auditlog.txt";
    logAction("admin1", "Book", "978-XYZ-123", ADD, filename);
    return 0;
}
