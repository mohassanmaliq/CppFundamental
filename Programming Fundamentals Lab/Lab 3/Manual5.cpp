#include <iostream>
using namespace std;
int main() {
    int health, level;

    cout << "Enter player health (0–100): "<<endl;
    cin >> health;
    cout << "Enter current level: ";
    cin >> level;
    if (health > 100) {
        health = 100;
    }
    if (health < 0) {
        health = 0;
    }
    if (health > 0)
        cout << "Player is alive." << endl;
    else
        cout << "Game Over!" << endl;
    if (health >= 75) {
        cout << "Status: Healthy" << endl;
        cout << "Keep exploring!" << endl;
    }
    else if (health >= 40) {
        cout << "Status: Wounded" << endl;
        cout << "Find a health pack soon.";
    }
    else if (health >= 1) {
        cout << "Status: Critical" << endl;
        cout << "Retreat immediately!" << endl;
    }
    if (level == 10)
        cout << "Warning: Boss level ahead!" << endl;
    if (level != 10)
        cout << "Normal level." << endl;

    return 0;
}