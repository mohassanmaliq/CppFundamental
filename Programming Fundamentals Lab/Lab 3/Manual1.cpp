#include <iostream>
using namespace std;
int number;
int main() {
    cout << "Enter a number" << endl;
    cin >> number;
    if (number < 0)
        number = -1 * number;
    cout << "The number is " << number << endl;
    return 0;
}