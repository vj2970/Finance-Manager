#include "FinanceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void FinanceManager::loadTransactions() {
    transactions.clear();
    std::ifstream file(dataFile);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, category, amountStr, typeStr, note;

        std::getline(ss, date, ',');
        std::getline(ss, category, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, typeStr, ',');
        std::getline(ss, note, ',');

        double amount = std::stod(amountStr);
        TransactionType type = stringToTransactionType(typeStr);

        transactions.emplace_back(date, category, amount, type, note);
    }
}

void FinanceManager::saveTransactions() const {
    std::ofstream file(dataFile);
    for (const auto& txn : transactions) {
        file << txn.toCSV() << "\n";
    }
}

void FinanceManager::addTransaction(const Transaction& txn) {
    transactions.push_back(txn);
}

void FinanceManager::showAllTransactions() const {
    std::cout << "\n--- All Transactions ---\n";
    for (const auto& txn : transactions) {
        std::cout << txn.getDate() << " | "
                  << transactionTypeToString(txn.getType()) << " | "
                  << txn.getAmount() << " | "
                  << txn.getCategory() << " | "
                  << txn.getNote() << "\n";
    }
}

void FinanceManager::showMonthlyReport(const std::string& month) const {
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    std::cout << "\n--- Monthly Report for " << month << " ---\n";
    for (const auto& txn : transactions) {
        if (txn.getDate().substr(0, 7) == month) {
            std::cout << txn.getDate() << " | "
                      << transactionTypeToString(txn.getType()) << " | "
                      << txn.getAmount() << " | "
                      << txn.getCategory() << " | "
                      << txn.getNote() << "\n";

            if (txn.getType() == TransactionType::INCOME)
                totalIncome += txn.getAmount();
            else
                totalExpense += txn.getAmount();
        }
    }

    double balance = totalIncome - totalExpense;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nTotal Income:  ₹" << totalIncome << "\n";
    std::cout << "Total Expense: ₹" << totalExpense << "\n";
    std::cout << "Net Balance:   ₹" << balance << "\n";
}
