# 💰 Personal Finance Manager (C++ CLI)

A simple command-line application to manage personal income and expenses.  
Built in **pure C++** with a focus on clean architecture, file I/O, and OOP principles.

---

## 📦 Features

- ✅ Add income and expense transactions
- 📂 Save and load data to/from CSV file
- 🔎 View all transactions in a tabular format
- 📊 Generate monthly financial reports (income, expense, balance)
- 🧠 Uses C++ OOP, STL, and enum-based transaction types

---

## 📸 Demo (CLI Example)

Personal Finance Manager

Add a transaction
View all transactions
View monthly report
Exit
Enter choice: 1

Enter date (YYYY-MM-DD): 2025-07-19
Enter amount: 200
Enter type (0 = INCOME, 1 = EXPENSE): 1
Enter category: Food
Enter note (optional): Lunch

✅ Transaction added successfully!

---

## 🧱 Project Structure

finance-manager/<br>
├── src/<br>
│ ├── main.cpp<br>
│ ├── Transaction.h / Transaction.cpp<br>
│ ├── FinanceManager.h / FinanceManager.cpp<br>
├── data/<br>
│ └── transactions.csv<br>
├── README.md<br>

---

## 🛠️ How to Build and Run

### 📌 Prerequisites:

- C++11 or newer
- A C++ compiler like `g++`

### 🔧 Build:

```bash
g++ src/*.cpp -o finance-manager
▶️ Run:
./finance-manager
Your data will be saved to data/transactions.csv automatically.
🧠 Concepts Used

Object-Oriented Programming (OOP)
File I/O with CSV
Enums and conditional logic
STL (vector, string, fstream, etc.)
CLI menu and user input
📈 Possible Future Improvements

🔐 Password-protected user accounts
📊 Graphical summary (if ported to GUI using Qt)
📁 Export reports to PDF or HTML
🧪 Unit tests using Google Test
🌐 Cloud sync using REST APIs
👨‍💻 Author

Vaibhav Jha
Built with ❤️ to showcase practical C++ skills.
```
