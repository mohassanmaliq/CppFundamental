#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string item1, item2;
    int amount1, amount2;
    cout << "Enter item 1 and amount: ";
    cin >> item1 >> amount1;
    cout << "Enter item 2 and amount: ";
    cin >> item2 >> amount2;
    int total = amount1 + amount2;
    ofstream out("expenses.txt", ios::app);
    out << item1 << "  " << amount1 << endl;
    out << item2 << "  " << amount2 << endl;
    out << "Day total: " << total << endl;
    out << "------------------" << endl;
    cout << "Entries added to expenses.txt" << endl;
}