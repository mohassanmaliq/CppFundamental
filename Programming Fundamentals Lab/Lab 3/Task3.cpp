#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    if (num1 > num2)
        cout << "Number1: " << num1 << " is Greater than Number2: " << num2 << endl;
    else if (num2 > num1)
        cout << "Number2: " << num2 << " is Greater than Number1: " << num1 << endl;
    else
        cout << "Both numbers are equal" << endl;
    return 0;
}