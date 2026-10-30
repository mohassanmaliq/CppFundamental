#include <iostream>
using namespace std;

int main() {
    int status, age, hoursWorked = 0;
    double basePay = 0, overtimePay = 0, grossPay;

    cout << "Are you employed at the moment or not?" << endl;
    cout << "1.Employed" << endl;
    cout << "2.Retired" << endl;
    cout << "Select option one or two by typing 1 or 2." << endl;
    cin >> status;
    if (status == 1) {
        cout << "You are employed" << endl;
        cout << "Enter daily worked hours: ";
        cin >> hoursWorked;

        if (hoursWorked >= 8) {
            basePay = 1000;
            double extraHours = hoursWorked - 8;
            if (extraHours > 3)
                extraHours = 3;
            overtimePay = extraHours * 300;
        }
        else if (hoursWorked > 0) {
            basePay = (1000.0 / 8.0) * hoursWorked;
        }
        else {
            cout << "Invalid worked hours." << endl;
            cout << "Closing the program!" << endl;
            return 0;
        }
        grossPay = basePay + overtimePay;
        cout << endl << "--- Salary Details ---" << endl;
        cout << "Hours Worked: " << hoursWorked << " hours" << endl;
        cout << "Base Pay: " << basePay << " rupees" << endl;
        cout << "Overtime Pay: " << overtimePay << " rupees" << endl;
        cout << "Gross Pay / Net Pay: " << grossPay << " rupees" << endl;
    }
    else if (status == 2) {
        cout << "You are retired" << endl;
        cout << "How old are you?" << endl;
        cin >> age;
        if (age >= 60 && age < 70)
            cout << "Your pension is 30000" << endl;
        else if (age >= 70)
            cout << "Your pension is 40000" << endl;
        else
            cout << "Enter a valid age." << endl;
    }
    else {
        cout << "Invalid option. Please enter 1 or 2." << endl;
    }
    return 0;
}