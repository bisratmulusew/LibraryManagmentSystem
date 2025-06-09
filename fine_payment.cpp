#include "FineManagement.h"

void FineManagement::processPartialPayment(int memberID, double paymentAmount) {
    for (auto& fine : fines) {
        if (fine.memberID == memberID && !fine.isPaid) {
            fine.amount -= paymentAmount;
            if (fine.amount <= 0) {
                fine.isPaid = true;
                fine.amount = 0;
                std::cout << "Fine for member " << memberID << " has been fully paid." << std::endl;
            } else {
                std::cout << "Partial payment processed. Remaining fine: $" << fine.amount << std::endl;
            }
            return;
        }
    }
    std::cout << "No unpaid fines found for member " << memberID << "." << std::endl;
}
