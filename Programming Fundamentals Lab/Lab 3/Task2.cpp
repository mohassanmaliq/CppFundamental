#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4, num5;
    cout << "Enter five numbers: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    if (num1 % 3 == 0)
        cout << "the number is divisible by three"<< endl;
    else
        cout << "The number is not divisible by three" << endl;
    if (num2 % 3 == 0)
        cout << "the number is divisible by three" << endl;
    else
        cout << "The number is not divisible by three" << endl;
    if (num3 % 3 == 0)
        cout << "the number is divisible by three" << endl;
    else
        cout << "The number is not divisible by three" << endl;
    if (num4 % 3 == 0)
        cout << "the number is divisible by three" << endl;
    else
        cout << "The number is not divisible by three" << endl;
    if (num5 % 3 == 0)
        cout << "the number is divisible by three" << endl;
    else
        cout << "The number is not divisible by three" << endl;
    return 0;
}