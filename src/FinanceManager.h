#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include "Transaction.h"
#include <vector>
#include <string>

class FinanceManager
{
private:
    vector<Transaction> transactions;
    string dataFilePath = "data/transactions.csv";

public:
    void loadTransaction();
    void saveTransaction() const;
    void addTransaction(const Transaction txn);
    void showAllTransaction() const;
    void showMonthlyReport(const string &yearMonth) const;
};

#endif