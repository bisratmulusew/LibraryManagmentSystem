#ifndef LOAN_RESERVATION_H
#define LOAN_RESERVATION_H

#include <string>
#include <vector>
using namespace std;

enum LoanStatus {
    ACTIVE,
    OVERDUE
};

struct Loan {
    string loanID;
    string memberID;
    string bookID;
    string dueDate;
    LoanStatus status;
};

struct Reservation {
    string bookID;
    string reservedBy;
};

class LoanReservationModule {
public:
    void renewLoan(const string& loanID); 
    void renewLoan(const string& loanID, int extraDays); 
    void checkOverdueLoans();

private:
    vector<Loan> loadLoans();
    vector<Reservation> loadReservations();
    void saveLoans(const vector<Loan>& loans);
    bool isDateOverdue(const string& date);
    string getCurrentDate();
    string addDaysToDate(const string& date, int days);
};

#endif
