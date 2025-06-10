#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <vector>
#include <ctime> 

using namespace std;

enum LoanStatus {
    ACTIVE,
    RETURNED,
    OVERDUE
};

struct Loan {
    string loanId;       
    string bookISBN;
    string memberId;
    time_t issueDate;     
    time_t dueDate;        
    LoanStatus status;
};

string loanStatusToString(LoanStatus status);

LoanStatus stringToLoanStatus(const string& statusStr);

string loanToText(const Loan& loan);

Loan loanFromText(const string& line);


#endif
