#include "loan_reservation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std; 

vector<Loan> LoanReservationModule::loadLoans() {
    vector<Loan> loans;
    ifstream file("loans.txt");
    Loan loan;
    int statusInt;
    while (file >> loan.loanID >> loan.memberID >> loan.bookID >> loan.dueDate >> statusInt) {
        loan.status = static_cast<LoanStatus>(statusInt);
        loans.push_back(loan);
    }
    return loans;
}

vector<Reservation> LoanReservationModule::loadReservations() {
    vector<Reservation> reservations;
    ifstream file("reservations.txt");
    Reservation res;
    while (file >> res.bookID >> res.reservedBy) {
        reservations.push_back(res);
    }
    return reservations;
}

void LoanReservationModule::saveLoans(const vector<Loan>& loans) {
    ofstream file("loans.txt");
    for (const Loan& loan : loans) {
        file << loan.loanID << " " << loan.memberID << " " << loan.bookID << " "
             << loan.dueDate << " " << static_cast<int>(loan.status) << endl;
    }
}

bool LoanReservationModule::isDateOverdue(const string& date) {
    return date < getCurrentDate(); 
}

string LoanReservationModule::getCurrentDate() {
    time_t t = time(0);
    tm* now = localtime(&t);
    ostringstream oss;
    oss << (now->tm_year + 1900) << '-'
        << setw(2) << setfill('0') << (now->tm_mon + 1) << '-'
        << setw(2) << setfill('0') << now->tm_mday;
    return oss.str();
}

string LoanReservationModule::addDaysToDate(const string& date, int days) {
    tm t = {};
    istringstream ss(date);
    ss >> get_time(&t, "%Y-%m-%d");
    t.tm_mday += days;
    mktime(&t);
    ostringstream newDate;
    newDate << (t.tm_year + 1900) << '-'
            << setw(2) << setfill('0') << (t.tm_mon + 1) << '-'
            << setw(2) << setfill('0') << t.tm_mday;
    return newDate.str();
}

void LoanReservationModule::renewLoan(const string& loanID) {
    renewLoan(loanID, 7);
}

void LoanReservationModule::renewLoan(const string& loanID, int extraDays) {
    vector<Loan> loans = loadLoans();
    vector<Reservation> reservations = loadReservations();
    bool found = false;

    for (Loan& loan : loans) {
        if (loan.loanID == loanID) {
            found = true;

            // Check if reserved
            bool reserved = false;
            for (const Reservation& res : reservations) {
                if (res.bookID == loan.bookID) {
                    reserved = true;
                    break;
                }
            }

            if (reserved) {
                cout << "Cannot renew. Book is reserved.\n";
                return;
            } else {
                loan.dueDate = addDaysToDate(loan.dueDate, extraDays);
                loan.status = ACTIVE;
                cout << "Loan renewed. New due date: " << loan.dueDate << "\n";
                saveLoans(loans);
                return;
            }
        }
    }

    if (!found) {
        cout << "Loan ID not found.\n";
    }
}

void LoanReservationModule::checkOverdueLoans() {
    vector<Loan> loans = loadLoans();
    string today = getCurrentDate();
    bool found = false;

    for (Loan& loan : loans) {
        if (isDateOverdue(loan.dueDate)) {
            loan.status = OVERDUE;
            cout << "Overdue: LoanID " << loan.loanID
                 << ", MemberID: " << loan.memberID
                 << ", BookID: " << loan.bookID
                 << ", Due: " << loan.dueDate << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No overdue loans.\n";
    }

    saveLoans(loans);
}
