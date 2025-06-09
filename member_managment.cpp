#include "MemberManagement.h"

void MemberManagement::listAllMembers() {
    std::cout << "List of Registered Members:" << std::endl;
    for (const auto& member : members) {
        std::cout << "ID: " << member.ID << ", Name: " << member.name 
                  << ", Contact: " << member.contact 
                  << ", Membership Type: " << member.membershipType << std::endl;
    }
}


