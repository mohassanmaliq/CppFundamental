#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number that you want to repeat the iteration for:  ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}