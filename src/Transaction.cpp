#include "Transaction.h"
#include <sstream>
#include <vector>
using namespace std;

Transaction::Transaction(string date, string category, double amount, Type type, string note) : dateOfTransaction(date), categoryOfTransaction(category), amountOfTransaction(amount), typeOfTransaction(type), note(note) {}

string Transaction::toCSV() const
{
    stringstream ss;
    ss << dateOfTransaction << "," << categoryOfTransaction << "," << amountOfTransaction << "," << (typeOfTransaction == INCOME ? "INCOME" : "EXPENSE") << "," << note;
    return ss.str();
}

Transaction Transaction::fromCSV(const string &line)
{
    stringstream ss(line);
    string token;
    vector<string> parts;

    while (getline(ss, token, ','))
    {
        parts.push_back(token);
    }

    if (parts.size() != 5)
    {
        throw runtime_error("Invalid CSV Format!");
    }

    Type type = (parts[3] == "INCOME") ? INCOME : EXPENSE;
    return Transaction(parts[0], parts[1], stod(parts[2]), type, parts[4]);
}

string Transaction::getDate() const { return dateOfTransaction; }
string Transaction::getCategory() const { return categoryOfTransaction; }
double Transaction::getAmount() const { return amountOfTransaction; }
Transaction::Type Transaction::getType() const { return typeOfTransaction; }
string Transaction::getNote() const { return note; }