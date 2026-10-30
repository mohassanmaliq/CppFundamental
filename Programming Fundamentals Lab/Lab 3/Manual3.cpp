#include <iostream>
using namespace std;
int main() {
    int number;
    cout << "Enter a number";
    cin >> number ;
    if (number > 90)
        cout << "Garde A";
    else if (number > 80)
        cout << "Grade B";
    else if (number > 50)
        cout << "Grade C";
    else
        cout << "Fail";
    return 0;
}