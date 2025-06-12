#ifndef FINE_MANAGEMENT_H
#define FINE_MANAGEMENT_H

#include <string>
#include <vector>

using namespace std;

enum FineStatus {
    PAID,
    UNPAID
};

struct Fine {
    int fineID;
    int memberID;
    string ISBN;       
    double amount;
    string reason;
    FineStatus status;
};

class FineManagement {
public:
    void addFine(const Fine& fine);
    void listUnpaidFines() const;
    void processPartialPayment(int memberID, double paymentAmount);
    void loadFinesFromFile();
    void saveFinesToFile();

private:
    vector<Fine> fines;
};

#endif 

