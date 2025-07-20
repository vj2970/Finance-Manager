#include "Transaction.h"

Transaction::Transaction(const std::string& date, const std::string& category, double amount, TransactionType type, const std::string& note)
    : date(date), category(category), amount(amount), type(type), note(note) {}

std::string Transaction::toCSV() const {
    return date + "," + category + "," + std::to_string(amount) + "," + transactionTypeToString(type) + "," + note;
}

std::string transactionTypeToString(TransactionType type) {
    return (type == TransactionType::INCOME) ? "INCOME" : "EXPENSE";
}

TransactionType stringToTransactionType(const std::string& str) {
    return (str == "INCOME") ? TransactionType::INCOME : TransactionType::EXPENSE;
}
