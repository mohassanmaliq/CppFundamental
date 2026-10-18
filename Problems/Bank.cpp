// Bank Account System (C++17)
// Create accounts, deposit, withdraw, transfer. Data is saved to accounts.txt.
// Compile: g++ -std=c++17 -Wall -o bank_system bank_system.cpp

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

const string DATA_FILE = "accounts.txt";
const long long MAX_CENTS = 100000000000LL;  // $1,000,000,000 cap per account

struct Account {
    int id;
    string name;
    long long cents;  // money stored in cents to avoid floating-point errors
};

string money(long long c) {
    ostringstream o;
    o << "$" << c / 100 << "." << setw(2) << setfill('0') << c % 100;
    return o.str();
}

// ---------- Input validation ----------

string readLine(const string& prompt) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) { cout << "\nInput closed. Exiting.\n"; exit(0); }
        if (s.find_first_not_of(" \t") != string::npos) return s;
        cout << "  Input cannot be empty.\n";
    }
}

int readInt(const string& prompt, int lo, int hi) {
    while (true) {
        string s = readLine(prompt);
        try {
            size_t used = 0;
            int v = stoi(s, &used);
            if (used != s.size()) throw invalid_argument("trailing");
            if (v >= lo && v <= hi) return v;
            cout << "  Enter a number from " << lo << " to " << hi << ".\n";
        } catch (...) { cout << "  Invalid input. Please enter a whole number.\n"; }
    }
}

// Accepts "12", "12.5", "12.50", ".75" -> cents. Rejects negatives, letters,
// more than 2 decimals, zero, and amounts above the cap.
bool parseAmount(const string& s, long long& cents) {
    size_t dot = s.find('.');
    string whole = s.substr(0, dot);
    string frac = (dot == string::npos) ? "" : s.substr(dot + 1);
    auto digit = [](char c) { return isdigit(static_cast<unsigned char>(c)) != 0; };
    if (whole.empty() && frac.empty()) return false;
    if (frac.size() > 2 || whole.size() > 10) return false;
    if (!all_of(whole.begin(), whole.end(), digit)) return false;
    if (!all_of(frac.begin(), frac.end(), digit)) return false;
    while (frac.size() < 2) frac += '0';
    long long total = (whole.empty() ? 0 : stoll(whole)) * 100 + stoll(frac);
    if (total <= 0 || total > MAX_CENTS) return false;
    cents = total;
    return true;
}

long long readAmount(const string& prompt) {
    long long cents;
    while (true) {
        if (parseAmount(readLine(prompt), cents)) return cents;
        cout << "  Invalid amount. Use a positive number like 25 or 25.50.\n";
    }
}

// ---------- Bank ----------

class Bank {
    vector<Account> accts;
    int nextId = 1001;

    Account* find(int id) {
        for (auto& a : accts) if (a.id == id) return &a;
        return nullptr;
    }

    Account* ask(const string& label) {
        int id = readInt(label, 1, 999999);
        Account* a = find(id);
        if (!a) cout << "  No account with number " << id << ".\n";
        return a;
    }

    // Write to a temp file first so a crash can't corrupt the real data.
    void save() const {
        ofstream out(DATA_FILE + ".tmp");
        for (const auto& a : accts) out << a.id << '|' << a.name << '|' << a.cents << '\n';
        out.close();
        error_code ec;
        fs::rename(DATA_FILE + ".tmp", DATA_FILE, ec);
        if (out.fail() || ec) cout << "  Warning: could not save data to disk!\n";
    }

public:
    void load() {
        ifstream in(DATA_FILE);
        string line;
        while (getline(in, line)) {
            istringstream ss(line);
            string id, name, cents;
            if (!getline(ss, id, '|') || !getline(ss, name, '|') || !getline(ss, cents)) continue;
            try {
                Account a{stoi(id), name, stoll(cents)};
                if (a.id < 1 || a.id > 999999 || a.cents < 0 || find(a.id)) continue;
                accts.push_back(a);
                nextId = max(nextId, a.id + 1);
            } catch (...) { continue; }  // skip corrupted lines
        }
        cout << "Loaded " << accts.size() << " account(s).\n";
    }

    void create() {
        if (nextId > 999999) { cout << "  Account limit reached.\n"; return; }
        string name;
        while (true) {
            name = readLine("Account holder name: ");
            if (name.size() > 30) cout << "  Maximum 30 characters.\n";
            else if (name.find('|') != string::npos) cout << "  The '|' character is not allowed.\n";
            else break;
        }
        accts.push_back({nextId, name, 0});
        cout << "Account created. Account number: " << nextId++ << "\n";
        save();
    }

    void deposit() {
        Account* a = ask("Account number: ");
        if (!a) return;
        long long amt = readAmount("Amount to deposit: ");
        if (a->cents + amt > MAX_CENTS) { cout << "  That would exceed the maximum balance.\n"; return; }
        a->cents += amt;
        cout << "Deposited " << money(amt) << ". New balance: " << money(a->cents) << "\n";
        save();
    }

    void withdraw() {
        Account* a = ask("Account number: ");
        if (!a) return;
        long long amt = readAmount("Amount to withdraw: ");
        if (amt > a->cents) { cout << "  Insufficient funds. Balance: " << money(a->cents) << "\n"; return; }
        a->cents -= amt;
        cout << "Withdrew " << money(amt) << ". New balance: " << money(a->cents) << "\n";
        save();
    }

    void transfer() {
        Account* from = ask("From account number: ");
        if (!from) return;
        Account* to = ask("To account number: ");
        if (!to) return;
        if (from == to) { cout << "  Cannot transfer to the same account.\n"; return; }
        long long amt = readAmount("Amount to transfer: ");
        if (amt > from->cents) { cout << "  Insufficient funds. Balance: " << money(from->cents) << "\n"; return; }
        if (to->cents + amt > MAX_CENTS) { cout << "  Receiving account would exceed the maximum balance.\n"; return; }
        from->cents -= amt;
        to->cents += amt;
        cout << "Transferred " << money(amt) << " from " << from->name << " to " << to->name << ".\n";
        save();
    }

    void balance() {
        if (Account* a = ask("Account number: "))
            cout << a->name << " (#" << a->id << ") balance: " << money(a->cents) << "\n";
    }

    void list() const {
        if (accts.empty()) { cout << "No accounts yet.\n"; return; }
        cout << left << setw(10) << "Number" << setw(32) << "Name" << "Balance\n";
        for (const auto& a : accts)
            cout << left << setw(10) << a.id << setw(32) << a.name << money(a.cents) << "\n";
    }
};

int main() {
    Bank bank;
    cout << "=== Bank Account System ===\n";
    bank.load();
    while (true) {
        cout << "\n1. Create account\n2. Deposit\n3. Withdraw\n4. Transfer\n"
             << "5. Check balance\n6. List accounts\n0. Exit\n";
        int choice = readInt("Choose an option: ", 0, 6);
        cout << "\n";
        switch (choice) {
            case 1: bank.create(); break;
            case 2: bank.deposit(); break;
            case 3: bank.withdraw(); break;
            case 4: bank.transfer(); break;
            case 5: bank.balance(); break;
            case 6: bank.list(); break;
            case 0: cout << "Goodbye!\n"; return 0;
        }
    }
}