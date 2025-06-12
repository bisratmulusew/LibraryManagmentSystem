#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum MembershipType {
    STANDARD,
    PREMIUM,
    VIP
};

struct Member {
    int id;
    string name;
    string contact;
    MembershipType type;
};

string membershipTypeToString(MembershipType type);
MembershipType stringToMembershipType(const string& str);

class MemberManagement {
private:
    vector<Member> members;

public:
    void addMember();
    void addMember(const Member& member);
    void editMember();
    void editMember(int id, const string& newName, const string& newContact, MembershipType newType);
    void listAllMembers() const;
    void loadMembersFromFile(const string& filename);
    void saveMembersToFile(const string& filename);
};

#endif 

