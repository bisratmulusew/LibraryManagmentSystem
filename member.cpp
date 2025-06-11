#include "Member.h"
#include <iostream>
#include <sstream>

using namespace std;

Member::Member() {}

Member::Member(string id, string name, string contact, string membershipType)
    : id(id), name(name), contact(contact), membershipType(membershipType) {}

string Member::getID() const {
    return id;
}

string Member::getName() const {
    return name;
}

string Member::getContact() const {
    return contact;
}

void Member::displayMember() const {
    cout << "ID: " << id << "\nName: " << name << "\nContact: " << contact
         << "\nMembership Type: " << membershipType << "\n";
}

string Member::toText() const {
    return id + "," + name + "," + contact + "," + membershipType;
}

Member Member::fromText(const string& line) {
    stringstream ss(line);
    string fields[4];
    string token;
    int i = 0;

    while (getline(ss, token, ',') && i < 4) {
        fields[i++] = token;
    }

    return Member(fields[0], fields[1], fields[2], fields[3]);
}
