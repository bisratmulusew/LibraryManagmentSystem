<<<<<<< HEAD
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
=======
#ifndef FINE_PAYMENT_H
#define FINE_PAYMENT_H

#include <string>
using namespace std;


enum FineStatus {
    PAID,
    UNPAID
};

struct Fine {
    int fineID;
    int memberID;
    double amount;
    string reason;
    FineStatus status;
};

void addFine(const Fine& fine);
void listUnpaidFines();
void loadFinesFromFile();
void saveFinesToFile();

#endif 
>>>>>>> main
