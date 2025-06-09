#ifndef LOANMANAGEMENT_H
#define LOANMANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Loan {
    int loanID;
    std::string memberID;
    std::string ISBN;
    std::string dueDate;
    bool isReturned;
};

class LoanManagement {
public:
    void loadLoanRecordsFromFile(const std::string& filename);
private:
    std::vector<Loan> loans;
};

#endif // LOANMANAGEMENT_H
