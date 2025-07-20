#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

enum class TransactionType {
    INCOME,
    EXPENSE
};

class Transaction {
private:
    std::string date;
    std::string category;
    double amount;
    TransactionType type;
    std::string note;

public:
    Transaction(const std::string& date, const std::string& category, double amount, TransactionType type, const std::string& note);

    std::string getDate() const { return date; }
    std::string getCategory() const { return category; }
    double getAmount() const { return amount; }
    TransactionType getType() const { return type; }
    std::string getNote() const { return note; }

    std::string toCSV() const;
};

std::string transactionTypeToString(TransactionType type);
TransactionType stringToTransactionType(const std::string& str);

#endif
