#include <iostream>
using namespace std;
int main() {
    int coins[] = { 5, 12, 7, 20, 3, 15 };
    int total = 0;
    int count = 0;
    cout << "Coins collected: ";
    for (int i = 0; i < 6; i++) {
        cout << coins[i] << " ";
        total += coins[i];
        if (coins[i] > 10) 
            count++;
    }
    cout << endl;
    cout << "Total coins: " << total << endl;
    cout << "Levels with more than 10 coins: " << count << endl;
    return 0;
}