#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include <string>
#include "Transaction.h"

class FinanceManager
{
private:
    std::vector<Transaction> transactions;
    std::string dataFile = "data/transactions.csv";

public:
    void loadTransactions();
    void saveTransactions() const;

    void addTransaction(const Transaction &txn);
    void showAllTransactions() const;
    void showMonthlyReport(const std::string &month) const;
};

#endif
