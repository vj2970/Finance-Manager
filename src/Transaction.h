#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction
{
public:
    enum Type
    {
        INCOME,
        EXPENSE
    };

private:
    string dateOfTransaction;
    string categoryOfTransaction;
    double amountOfTransaction;
    Type typeOfTransaction;
    string note;

public:
    Transaction(string dateOfTransaction, string categoryOfTransaction, double amountOfTransaction, Type typeOfTransaction, string note);
    string toCSV() const;
    static Transaction fromCSV(const string &line);

    string getDate() const;
    string getCategory() const;
    double getAmount() const;
    Type getType() const;
    string getNote() const;
};

#endif