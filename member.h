#ifndef MEMBER_H
#define MEMBER_H

#include <string>

using namespace std;

class Member {
private:
    string id, name, contact, membershipType;

public:
    Member();
    Member(string, string, string, string);

    string getID() const;
    string getName() const;
    string getContact() const;
    void displayMember() const;

    string toText() const;
    static Member fromText(const string&);
};

#endif
