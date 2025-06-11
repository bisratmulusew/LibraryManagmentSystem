<<<<<<< HEAD
#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H

#include <iostream>
#include <vector>
#include <string>

struct Member {
    int ID;
    std::string name;
    std::string contact;
    std::string membershipType;
};

class MemberManagement {
public:
    void listAllMembers();
    void loadMembersFromFile(const std::string& filename);
    void saveMembersToFile(const std::string& filename);
private:
    std::vector<Member> members;
};

#endif // MEMBERMANAGEMENT_H
=======
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
>>>>>>> main
