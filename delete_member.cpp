#include "Member.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Member> loadMembers(const string& filename) {
    ifstream file(filename);
    vector<Member> members;
    string line;

    while (getline(file, line)) {
        members.push_back(Member::fromText(line));
    }

    return members;
}

void saveMembers(const vector<Member>& members, const string& filename) {
    ofstream file(filename);
    for (const Member& member : members) {
        file << member.toText() << "\n";
    }
}

void deleteMember(const string& filename) {
    vector<Member> members = loadMembers(filename);
    string id;
    cout << "Enter Member ID to delete: ";
    getline(cin, id);

    bool found = false;
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getID() == id) {
            members.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        saveMembers(members, filename);
        cout << "Member deleted successfully.\n";
    } else {
        cout << "Member not found.\n";
    }
}

int main() {
    string filename = "../data/members.txt";
    deleteMember(filename);
    return 0;
}
