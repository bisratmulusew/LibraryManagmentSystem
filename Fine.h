#ifndef FINE_H
#define FINE_H

#include <string>
#include <vector>

using namespace std;

enum FineStatus {
    UNPAID,
    PARTIALLY_PAID,
    PAID
};

struct Fine {
    string fineId;     
    string memberId;
    string bookISBN;
    double totalAmount;
    double amountPaid;
    FineStatus status;
};

string fineStatusToString(FineStatus status);

FineStatus stringToFineStatus(const string& str);

string fineToText(const Fine& fine);

Fine fineFromText(const string& line);

#endif
