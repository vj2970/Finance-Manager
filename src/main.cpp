#include <iostream>
#include "FinanceManager.h"

TransactionType getTransactionTypeFromUser() {
    int choice;
    std::cout << "Type (1 for Income, 2 for Expense): ";
    std::cin >> choice;
    std::cin.ignore();
    return (choice == 1) ? TransactionType::INCOME : TransactionType::EXPENSE;
}

int main() {
    FinanceManager manager;
    manager.loadTransactions();

    int option;
    do {
        std::cout << "\n1. Add Transaction\n2. View All Transactions\n3. Monthly Report\n4. Exit\nChoose: ";
        std::cin >> option;
        std::cin.ignore();

        if (option == 1) {
            std::string date, category, note;
            double amount;
            TransactionType type = getTransactionTypeFromUser();

            std::cout << "Date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            std::cout << "Category: ";
            std::getline(std::cin, category);
            std::cout << "Amount: ";
            std::cin >> amount;
            std::cin.ignore();
            std::cout << "Note: ";
            std::getline(std::cin, note);

            Transaction txn(date, category, amount, type, note);
            manager.addTransaction(txn);
            manager.saveTransactions();

        } else if (option == 2) {
            manager.showAllTransactions();

        } else if (option == 3) {
            std::string month;
            std::cout << "Enter month (YYYY-MM): ";
            std::getline(std::cin, month);
            manager.showMonthlyReport(month);
        }

    } while (option != 4);

    return 0;
}
