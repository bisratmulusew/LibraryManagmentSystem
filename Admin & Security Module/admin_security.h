#ifndef ADMIN_SECURITY_H
#define ADMIN_SECURITY_H

#include <string>
#include <vector>
using namespace std;

enum class AdminActionType {
    BookEdit,
    MemberDelete,
    SystemBackup,
    SystemRestore,
    Custom
};

struct AdminActionLog {
    string timestamp;
    string adminName;
    AdminActionType actionType;
    string details;
};

string hashPassword(const string& password);
bool verifyPassword(const string& password, const string& hashed);

void logAdminAction(const string& details, AdminActionType type, const string& adminName = "admin");
vector<AdminActionLog> loadAdminLogs(); 

bool backupDatabase(const string& backupFile = "backup.txt");
bool restoreDatabase(const string& backupFile = "backup.txt");

#endif