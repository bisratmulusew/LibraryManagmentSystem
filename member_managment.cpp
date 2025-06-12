#include "MemberManagement.h"
#include <iostream>
#include <vector>

using namespace std;

// Utility functions
string membershipTypeToString(MembershipType type) {
    switch (type) {
        case STANDARD: return "STANDARD";
        case PREMIUM: return "PREMIUM";
        case VIP: return "VIP";
        default: return "UNKNOWN";
    }
}

MembershipType stringToMembershipType(const string& str) {
    if (str == "STANDARD") return STANDARD;
    if (str == "PREMIUM") return PREMIUM;
    if (str == "VIP") return VIP;

    cout << "Invalid membership type entered. Defaulting to STANDARD.\n";
    return STANDARD;
}

// MemberManagement class methods
void MemberManagement::addMember() {
    Member newMember;
    cout << "Enter Member ID: ";
    cin >> newMember.id;
    cin.ignore();
    cout << "Enter Member Name: ";
    getline(cin, newMember.name);
    cout << "Enter Member Contact: ";
    getline(cin, newMember.contact);
    string type;
    cout << "Enter Membership Type (STANDARD, PREMIUM, VIP): ";
    getline(cin, type);
    newMember.type = stringToMembershipType(type);
    members.push_back(newMember);
    cout << "Member added successfully!\n";
}

void MemberManagement::addMember(const Member& member) {
    members.push_back(member);
    cout << "Member added successfully!\n";
}

void MemberManagement::editMember() {
    int id;
    cout << "Enter Member ID to edit: ";
    cin >> id;
    cin.ignore();
    for (auto& member : members) {
        if (member.id == id) {
            cout << "Enter new Name: ";
            getline(cin, member.name);
            cout << "Enter new Contact: ";
            getline(cin, member.contact);
            string type;
            cout << "Enter new Membership Type (STANDARD, PREMIUM, VIP): ";
            getline(cin, type);
            member.type = stringToMembershipType(type);
            cout << "Member updated successfully!\n";
            return;
        }
    }
    cout << "Member not found!\n";
}

void MemberManagement::editMember(int id, const string& newName, const string& newContact, MembershipType newType) {
    for (auto& member : members) {
        if (member.id == id) {
            if (!newName.empty()) member.name = newName;
            if (!newContact.empty()) member.contact = newContact;
            member.type = newType;
            cout << "Member updated successfully!\n";
            return;
        }
    }
    cout << "Member ID not found.\n";
}

void MemberManagement::listAllMembers() const {
    cout << "\n--- Member List ---\n";
    for (const auto& member : members) {
        cout << "ID: " << member.id
             << ", Name: " << member.name
             << ", Contact: " << member.contact
             << ", Membership Type: " << membershipTypeToString(member.type) << "\n";
    }
}

