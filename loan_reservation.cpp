#include "LoanManagement.h"

void LoanManagement::loadLoanRecordsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    Loan loan;
    while (file >> loan.loanID >> loan.memberID >> loan.ISBN >> loan.dueDate >> loan.isReturned) {
        loans.push_back(loan);
    }
    file.close();
    std::cout << "Loan records loaded successfully." << std::endl;
}
