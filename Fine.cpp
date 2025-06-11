#include "Fine.h"
#include <sstream>
#include <iomanip>

string fineStatusToString(FineStatus status) {
    switch (status) {
        case UNPAID: return "Unpaid";
        case PARTIALLY_PAID: return "PartiallyPaid";
        case PAID: return "Paid";
        default: return "Unknown";
    }
}

FineStatus stringToFineStatus(const string& str) {
    if (str == "Unpaid") return UNPAID;
    if (str == "PartiallyPaid") return PARTIALLY_PAID;
    if (str == "Paid") return PAID;
    return UNPAID; 
}

string fineToText(const Fine& fine) {
    stringstream ss;
    ss << fine.fineId << ","
       << fine.memberId << ","
       << fine.bookISBN << ","
       << fixed << setprecision(2) << fine.totalAmount << ","
       << fixed << setprecision(2) << fine.amountPaid << ","
       << fineStatusToString(fine.status);
    return ss.str();
}

Fine fineFromText(const string& line) {
    Fine fine;
    stringstream ss(line);
    string totalStr, paidStr, statusStr;

    getline(ss, fine.fineId, ',');
    getline(ss, fine.memberId, ',');
    getline(ss, fine.bookISBN, ',');
    getline(ss, totalStr, ',');
    getline(ss, paidStr, ',');
    getline(ss, statusStr, ',');

    fine.totalAmount = stod(totalStr);
    fine.amountPaid = stod(paidStr);
    fine.status = stringToFineStatus(statusStr);

    return fine;
}
