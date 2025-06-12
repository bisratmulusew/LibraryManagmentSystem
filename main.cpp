#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

//  Include All Modules 
#include "Admin.h"
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "Fine.h"
#include "AuditLog.h"

#include "book_management.h"
#include "fine_payment.h"
#include "admin_security.h"
#include "reporting_analytics.h"
#include "loan_reservation.h"
#include "member_managment.h"

using namespace std;

//  FILE PATHS 
const string BOOK_FILE = "../data/books.txt";
const string MEMBER_FILE = "../data/members.txt";
const string LOAN_FILE = "../data/loans.txt";
const string FINE_FILE = "../data/fines.txt";
const string ADMIN_FILE = "../data/admins.txt";
const string AUDIT_FILE = "../data/auditlog.txt";

BookManager bookManager;
MemberManager memberManager;
LoanManager loanManager;
FineManager fineManager;
AdminManager adminManager;
LoanReservationModule loanModule;

//  Authentication 
bool login(string& loggedInUser) {
    vector<Admin> admins = loadAdmins(ADMIN_FILE);
    if (admins.empty()) {
        cerr << "No admins available.\n";
        return false;
    }

    string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    if (verifyLogin(admins, username, password)) {
        loggedInUser = username;
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

//  Book Management Menu 
void bookMenu(const string& user) {
    while (true) {
        cout << "\n-- Book Management --\n";
        cout << "1. Add Book\n2. Edit Book\n3. List All Books\n4. Check Availability\n5. Back\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Book book;
            book.inputBookDetails();
            bookManager.addBook(book);
            logAction(user, "Book", book.getISBN(), ADD, AUDIT_FILE);
        } else if (choice == 2) {
            string isbn;
            cout << "Enter ISBN to edit: ";
            getline(cin, isbn);
            bookManager.editBook(isbn);
            logAction(user, "Book", isbn, EDIT, AUDIT_FILE);
        } else if (choice == 3) {
            bookManager.listBooks();
        } else if (choice == 4) {
            string isbn;
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            bookManager.checkAvailability(isbn);
        } else {
            break;
        }
    }
}

//  Member Management Menu 
void memberMenu(const string& user) {
    while (true) {
        cout << "\n-- Member Management --\n";
        cout << "1. Search Member\n2. Delete Member\n3. Back\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            searchMember(MEMBER_FILE);
        } else if (choice == 2) {
            deleteMember(MEMBER_FILE);
            logAction(user, "Member", "Deleted", DELETE, AUDIT_FILE);
        } else {
            break;
        }
    }
}

//  Loan Management Menu 
void loanMenu() {
    cout << "\n-- Active Loans --\n";
    listActiveLoans(LOAN_FILE);
}

//  Fine Management Menu 
void fineMenu(const string& user) {
    while (true) {
        cout << "\n-- Fine Management --\n";
        cout << "1. View All Fines\n2. Search Fine\n3. Pay Fine\n4. Delete Fine\n5. Back\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        vector<Fine> fines = loadFines(FINE_FILE);
        if (choice == 1) {
            for (const Fine& fine : fines)
                cout << fineToText(fine) << "\n";
        } else if (choice == 2) {
            searchFine(FINE_FILE);
        } else if (choice == 3) {
            processFinePayment(fines);
            saveFines(fines, FINE_FILE);
            logAction(user, "Fine", "Paid", EDIT, AUDIT_FILE);
        } else if (choice == 4) {
            deleteFine(FINE_FILE);
            logAction(user, "Fine", "Deleted", DELETE, AUDIT_FILE);
        } else {
            break;
        }
    }
}

//  Dashboard 
void dashboard() {
    showDashboard(BOOK_FILE, LOAN_FILE, FINE_FILE);
}

//  Admin Menu 
void extendedAdminMenu(const string& currentUser) {
    int choice;
    do {
        cout << "\n========== Extended Admin Menu ==========";
        cout << "\n6. Admin: View Logs\n7. Admin: Backup Database\n8. Admin: Restore Database\n9. Generate Monthly Report\n10. Exit to Main Menu\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 6: {
                vector<AdminActionLog> logs = loadAdminLogs();
                for (const auto& log : logs) {
                    cout << log.timestamp << " | " << log.adminName << " | "
                         << actionTypeToString(log.actionType) << " | " << log.details << "\n";
                }
                break;
            }
            case 7:
                if (backupDatabase("../data/backup.dat"))
                    cout << "Backup successful.\n";
                break;
            case 8:
                if (restoreDatabase("../data/backup.dat"))
                    cout << "Restore successful.\n";
                break;
            case 9: {
                string month = "2024-05";
                string summary;
                generateMonthlySummary(loanManager.getLoans(), fineManager.getFines(), memberManager.getMembers(), month, summary);
                exportReportToFile("../data/monthly_report.txt", summary, "Library Report Header");
                cout << summary;
                break;
            }
            case 10:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 10);
}

//  Main Menu 
int main() {
    string currentUser;

    cout << "====== Library Management System ======\n";
    if (!login(currentUser)) return 0;

    // Load data
    bookManager.loadBooksFromFile(BOOK_FILE);
    memberManager.loadMembersFromFile(MEMBER_FILE);
    loanManager.loadLoansFromFile(LOAN_FILE);
    fineManager.loadFinesFromFile(FINE_FILE);
    adminManager.loadAdminsFromFile(ADMIN_FILE);

    while (true) {
        cout << "\n====== Main Menu ======\n";
        cout << "1. Book Management\n2. Member Management\n3. Loan Management\n";
        cout << "4. Fine Management\n5. Dashboard\n6. Admin Panel\n7. Exit\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: bookMenu(currentUser); break;
            case 2: memberMenu(currentUser); break;
            case 3: loanMenu(); break;
            case 4: fineMenu(currentUser); break;
            case 5: dashboard(); break;
            case 6: extendedAdminMenu(currentUser); break;
            case 7: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
