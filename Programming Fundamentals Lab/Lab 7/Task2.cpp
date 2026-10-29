#include <iostream>
using namespace std;
double totalSalary(double basic, double bonus = 5000);
int main() {
    double basic = 40000;
    double bonus = 8000;
    cout << "Total salary (default bonus): Rs. " << totalSalary(basic) << endl;
    cout << "Total salary (bonus = " << bonus << "): Rs. "<< totalSalary(basic, bonus) << endl;
    return 0;
}
double totalSalary(double basic, double bonus) {
    return basic + bonus;
}