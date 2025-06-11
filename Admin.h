#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

using namespace std;

enum Role {
    LIBRARIAN,
    MEMBER
};

struct Admin {
    string username;
    string password; 
    Role role;
};

string roleToString(Role role);
Role stringToRole(const string& roleStr);

Admin adminFromText(const string& line);
string adminToText(const Admin& admin);

#endif
