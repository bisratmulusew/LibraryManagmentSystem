#include "AuditLog.h"
#include <sstream>
#include <iomanip>

string actionTypeToString(ActionType type) {
    switch (type) {
        case ADD: return "Add";
        case EDIT: return "Edit";
        case DELETE: return "Delete";
        default: return "Unknown";
    }
}

string auditLogToText(const AuditLog& log) {
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&log.timestamp));

    return log.username + "," + log.actionObject + "," + log.objectId + "," +
           actionTypeToString(log.action) + "," + buffer;
}

AuditLog auditLogFromText(const string& line) {
    AuditLog log;
    stringstream ss(line);
    string actionStr, timeStr;

    getline(ss, log.username, ',');
    getline(ss, log.actionObject, ',');
    getline(ss, log.objectId, ',');
    getline(ss, actionStr, ',');
    getline(ss, timeStr, ',');

    log.action = (actionStr == "Add") ? ADD :
                 (actionStr == "Edit") ? EDIT : DELETE;

    struct tm t = {};
    sscanf(timeStr.c_str(), "%d-%d-%d %d:%d:%d",
          &t.tm_year, &t.tm_mon, &t.tm_mday,
          &t.tm_hour, &t.tm_min, &t.tm_sec);
    t.tm_year -= 1900;
    t.tm_mon -= 1;
    log.timestamp = mktime(&t);

    return log;
}
