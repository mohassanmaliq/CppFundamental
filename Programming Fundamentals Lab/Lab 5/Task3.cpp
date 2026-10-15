#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // for loop: we know it runs exactly 10 times
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
    int x;
    int sum = 0;
    cout << "Enter numbers that you want to add up (0 to stop): ";
    cin >> x;
    // while loop is used because the number of timesthe user will run the program in unknown
    while (x != 0) {
        sum = sum + x;
        cin >> x;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}