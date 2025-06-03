#ifndef MEMBER_MANAGEMENT_H
#define MEMBER_MANAGEMENT_H

#include <string>
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


void addMember(); 
void addMember(const Member& member); 
void editMember(); 
void editMember(int id, const string& newName, const string& newContact, MembershipType newType); 
void displayAllMembers();
string membershipTypeToString(MembershipType type);
MembershipType stringToMembershipType(const string& str);

#endif 
