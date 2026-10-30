#include <iostream>
using namespace std;
int main() {
    double s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
    cout << "Enter the salaries of 10 employees:"<<endl;
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 >> s10;
    double maxSalary = s1;
    double minSalary = s1;
    // Check Employee 2
    if (s2 > maxSalary) maxSalary = s2;
    if (s2 < minSalary) minSalary = s2;
    // Check Employee 3
    if (s3 > maxSalary) maxSalary = s3;
    if (s3 < minSalary) minSalary = s3;
    // Check Employee 4
    if (s4 > maxSalary) maxSalary = s4;
    if (s4 < minSalary) minSalary = s4;
    // Check Employee 5
    if (s5 > maxSalary) maxSalary = s5;
    if (s5 < minSalary) minSalary = s5;
    // Check Employee 6
    if (s6 > maxSalary) maxSalary = s6;
    if (s6 < minSalary) minSalary = s6;
    // Check Employee 7
    if (s7 > maxSalary) maxSalary = s7;
    if (s7 < minSalary) minSalary = s7;
    // Check Employee 8
    if (s8 > maxSalary) maxSalary = s8;
    if (s8 < minSalary) minSalary = s8;
    // Check Employee 9
    if (s9 > maxSalary) maxSalary = s9;
    if (s9 < minSalary) minSalary = s9;
    // Check Employee 10
    if (s10 > maxSalary) maxSalary = s10;
    if (s10 < minSalary) minSalary = s10;
    cout <<endl << "Maximum Salary: " << maxSalary << endl;
    cout <<endl<< "Minimum Salary: " << minSalary << endl;
    return 0;
}