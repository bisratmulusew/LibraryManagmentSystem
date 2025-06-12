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

void searchMember(const string& filename) {
    vector<Member> members = loadMembers(filename);
    int choice;
    string input;

    cout << "Search by:\n1. ID\n2. Name\n3. Contact\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter search term: ";
    getline(cin, input);

    bool found = false;
    for (const Member& member : members) {
        if ((choice == 1 && member.getID() == input) ||
            (choice == 2 && member.getName() == input) ||
            (choice == 3 && member.getContact() == input)) {
            member.displayMember();
            found = true;
        }
    }

    if (!found) {
        cout << "No matching member found.\n";
    }
}

