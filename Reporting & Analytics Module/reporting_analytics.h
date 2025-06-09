#ifndef REPORTING_ANALYTICS_H
#define REPORTING_ANALYTICS_H

#include <string>
#include <vector>
using namespace std;

enum class BookStatus {
    Available,
    Lost,
    Damaged
};

struct Book {
    int bookID;
    string title;
    int quantity;
    int threshold; 
    BookStatus status;
};

struct Loan {
    int loanID;
    string date; 
};

struct Fine {
    int fineID;
    double amount;
    string date; 
};

struct Member {
    int memberID;
    string registrationDate; 
};


vector<Book> getBooksNeedingRestock(const vector<Book>& books);
vector<Book> getLostOrDamagedBooks(const vector<Book>& books);
void generateMonthlySummary(const vector<Loan>& loans, const vector<Fine>& fines, const vector<Member>& members, const string& month, string& summaryOut);

bool exportReportToFile(const string& filename, const string& reportContent);
bool exportReportToFile(const string& filename, const string& reportContent, const string& header);

#endif 
