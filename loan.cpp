#include "Loan.h"
#include <sstream>
#include <iomanip>

using namespace std;

string loanStatusToString(LoanStatus status) {
    switch(status) {
        case ACTIVE: return "Active";
        case RETURNED: return "Returned";
        case OVERDUE: return "Overdue";
        default: return "Unknown";
    }
}

LoanStatus stringToLoanStatus(const string& statusStr) {
    if (statusStr == "Active") return ACTIVE;
    if (statusStr == "Returned") return RETURNED;
    if (statusStr == "Overdue") return OVERDUE;
    return ACTIVE; 
}

string loanToText(const Loan& loan) {
  
    char issueBuffer[11], dueBuffer[11];
    strftime(issueBuffer, sizeof(issueBuffer), "%Y-%m-%d", localtime(&loan.issueDate));
    strftime(dueBuffer, sizeof(dueBuffer), "%Y-%m-%d", localtime(&loan.dueDate));

    return loan.loanId + "," + loan.bookISBN + "," + loan.memberId + "," + issueBuffer + "," + dueBuffer + "," + loanStatusToString(loan.status);
}

Loan loanFromText(const string& line) {
    Loan loan;
    stringstream ss(line);
    string issueDateStr, dueDateStr, statusStr;

    getline(ss, loan.loanId, ',');
    getline(ss, loan.bookISBN, ',');
    getline(ss, loan.memberId, ',');
    getline(ss, issueDateStr, ',');
    getline(ss, dueDateStr, ',');
    getline(ss, statusStr, ',');

    int y, m, d;

    sscanf(issueDateStr.c_str(), "%d-%d-%d", &y, &m, &d);
    struct tm tmIssue = {0};
    tmIssue.tm_year = y - 1900;
    tmIssue.tm_mon = m - 1;
    tmIssue.tm_mday = d;
    loan.issueDate = mktime(&tmIssue);

    sscanf(dueDateStr.c_str(), "%d-%d-%d", &y, &m, &d);
    struct tm tmDue = {0};
    tmDue.tm_year = y - 1900;
    tmDue.tm_mon = m - 1;
    tmDue.tm_mday = d;
    loan.dueDate = mktime(&tmDue);

    loan.status = stringToLoanStatus(statusStr);

    return loan;
}