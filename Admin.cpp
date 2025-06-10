#include "Admin.h"
#include <sstream>

string roleToString(Role role) {
    return role == LIBRARIAN ? "Librarian" : "Member";
}

Role stringToRole(const string& roleStr) {
    return roleStr == "Librarian" ? LIBRARIAN : MEMBER;
}

Admin adminFromText(const string& line) {
    Admin admin;
    stringstream ss(line);
    string roleStr;

    getline(ss, admin.username, ',');
    getline(ss, admin.password, ',');
    getline(ss, roleStr, ',');

    admin.role = stringToRole(roleStr);
    return admin;
}

string adminToText(const Admin& admin) {
    return admin.username + "," + admin.password + "," + roleToString(admin.role);
}
