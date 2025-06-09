#ifndef FINEMANAGEMENT_H
#define FINEMANAGEMENT_H

#include <iostream>
#include <vector>
#include <string>

struct Fine {
    int memberID;
    std::string ISBN;
    double amount;
    bool isPaid;
};

class FineManagement {
public:
    void processPartialPayment(int memberID, double paymentAmount);
private:
    std::vector<Fine> fines;
};

#endif // FINEMANAGEMENT_H
