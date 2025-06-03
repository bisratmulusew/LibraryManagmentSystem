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
