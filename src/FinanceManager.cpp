#include "FinanceManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

void FinanceManager::loadTransaction()
{
    transactions.clear();
    ifstream file(dataFilePath);

    if (!file.is_open())
    {
        cerr << "Warning: Could not open file " << dataFilePath << ". Starting with empty list.\n";
        return;
    }

    string line;
    while (getline(file, line))
    {
        try
        {
            transactions.push_back(Transaction::fromCSV(line));
        }
        catch (const exception &e)
        {
            cerr << "Skipping invalid line: " << line << "\n";
        }
    }
    file.close();
}