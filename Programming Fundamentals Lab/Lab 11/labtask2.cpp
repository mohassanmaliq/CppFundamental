#include <iostream>
using namespace std;
int main(){
    int a, b;
    cout << "Enter the value for player 1 :";
    cin >> a;
    cout << "Enter the value for player 2 :";
    cin >> b;
    int *p1 = &a;
    int *p2 = &b;
    int *maxPtr;
    if (*p1 > *p2)
        maxPtr = p1;
    else
        maxPtr = p2;
    cout << "Higher score: " << *maxPtr << endl;
    cout << "Before swap: Player 1 = " << *p1 << ", Player 2 = " << *p2 << endl;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << "After swap : Player 1 = " << a << ", Player 2 = " << b << endl;
    return 0;
}