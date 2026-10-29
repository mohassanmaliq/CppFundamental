#include <iostream>
using namespace std;
int sumNatural(int n);
int power(int base, int exp);
int main() {
    cout << "sumNatural(5) = " << sumNatural(5) << endl;
    cout << "power(2, 5) = " << power(2, 5) << endl;
    return 0;
}
int sumNatural(int n) {
    if (n <= 0)                           // base case
        return 0;
    else
        return n + sumNatural(n - 1);     // recursive case
}
int power(int base, int exp) {
    if (exp == 0)                         // base case
        return 1;
    else
        return base * power(base, exp - 1);   // recursive case
}