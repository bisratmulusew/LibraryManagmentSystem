#include "reporting_analytics.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<Book> getBooksNeedingRestock(const vector<Book>& books) {
    vector<Book> restockBooks;
    for (const auto& book : books) {
        if (book.quantity < book.threshold) {
            restockBooks.push_back(book);
        }
    }
    return restockBooks;
}

vector<Book> getLostOrDamagedBooks(const vector<Book>& books) {
    vector<Book> lostOrDamagedBooks;
    for (const auto& book : books) {
        if (book.status == BookStatus::Lost || book.status == BookStatus::Damaged) {
            lostOrDamagedBooks.push_back(book);
        }
    }
    return lostOrDamagedBooks;
}

void generateMonthlySummary(const vector<Loan>& loans, const vector<Fine>& fines, const vector<Member>& members, const string& month, string& summaryOut) {
    stringstream summary;
    summary << "Monthly Summary for " << month << "\n";
    summary << "Total Loans: " << loans.size() << "\n";
    summary << "Total Fines: " << fines.size() << "\n";
    summary << "Total Members: " << members.size() << "\n";
    
    double totalFineAmount = 0.0;
    for (const auto& fine : fines) {
        totalFineAmount += fine.amount;
    }
    summary << "Total Fine Amount: $" << totalFineAmount << "\n";
    
    summaryOut = summary.str();
}

bool exportReportToFile(const string& filename, const string& reportContent) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return false;
    }
    outFile << reportContent;
    outFile.close();
    return true;
}

bool exportReportToFile(const string& filename, const string& reportContent, const string& header) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return false;
    }
    outFile << header << "\n" << reportContent;
    outFile.close();
    return true;
}