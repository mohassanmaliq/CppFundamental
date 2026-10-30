#include <iostream>
using namespace std;
int number;
int main() {
    cout << "Enter a number" << endl;
    cin >> number;
    if (number > 50)
        cout << "pass";
    else
        cout << "fail";
    return 0;
}