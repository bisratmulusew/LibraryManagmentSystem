#ifndef AUDIT_LOG_H
#define AUDIT_LOG_H

#include <string>
#include <ctime>

using namespace std;

enum ActionType {
    ADD,
    EDIT,
    DELETE
};

struct AuditLog {
    string username;
    string actionObject; 
    string objectId;
    ActionType action;
    time_t timestamp;
};

string actionTypeToString(ActionType type);

string auditLogToText(const AuditLog& log);

AuditLog auditLogFromText(const string& line);


#endif
