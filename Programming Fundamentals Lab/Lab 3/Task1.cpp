#include <iostream>
using namespace std;

int main() {
    int monthNumber;
    cout << "Enter a month number (1-12): ";
    cin >> monthNumber;

    if (monthNumber == 1)
        cout << "JANUARY"<< endl;
    else if (monthNumber == 2)
        cout << "FEBRUARY" << endl;
    else if (monthNumber == 3)
        cout << "MARCH" << endl;
    else if (monthNumber == 4)
        cout << "APRIL" << endl;
    else if (monthNumber == 5)
        cout << "MAY" << endl;
    else if (monthNumber == 6)
        cout << "JUNE" << endl;
    else if (monthNumber == 7)
        cout << "JULY" << endl;
    else if (monthNumber == 8)
        cout << "AUGUST" << endl;
    else if (monthNumber == 9)
        cout << "SEPTEMBER" << endl;
    else if (monthNumber == 10)
        cout << "OCTOBER" << endl;
    else if (monthNumber == 11)
        cout << "NOVEMBER" << endl;
    else if (monthNumber == 12)
        cout << "DECEMBER" << endl;
    else
        cout << "Invalid input! Please enter a number between 1 and 12." << endl;
    return 0;
}