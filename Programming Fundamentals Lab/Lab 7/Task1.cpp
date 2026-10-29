#include <iostream>
#include <iomanip>
using namespace std;
double calculateBill(int units);
double totalBill(double b1, double b2, double b3);
int readUnits(int customerNo);
int main() {
    int units1 = readUnits(1);
    int units2 = readUnits(2);
    int units3 = readUnits(3);
    double bill1 = calculateBill(units1);   
    double bill2 = calculateBill(units2);
    double bill3 = calculateBill(units3);
    cout << fixed << setprecision(2);
    cout << "\n----- Electricity Bills -----" << endl;
    cout << "Customer 1 (" << units1 << " units): Rs. " << bill1 << endl;
    cout << "Customer 2 (" << units2 << " units): Rs. " << bill2 << endl;
    cout << "Customer 3 (" << units3 << " units): Rs. " << bill3 << endl;
    cout << "Total of all bills: Rs. " << totalBill(bill1, bill2, bill3) << endl;
    return 0;
}
int readUnits(int customerNo) {
    int units;
    do {
        cout << "Enter units consumed by customer " << customerNo << ": ";
        cin >> units;
        if (units < 0)
            cout << "Units cannot be negative. Try again." << endl;
    } while (units < 0);
    return units;
}
double calculateBill(int units) {
    if (units <= 100)
        return units * 10;                           
    else if (units <= 200)
        return 100 * 10 + (units - 100) * 15;    
    else
        return 100 * 10 + 100 * 15 + (units - 200) * 20;   
}
double totalBill(double b1, double b2, double b3) {
    return b1 + b2 + b3;
}