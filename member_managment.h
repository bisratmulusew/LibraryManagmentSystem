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
