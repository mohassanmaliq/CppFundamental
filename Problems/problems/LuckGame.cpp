#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int normalAttack() {
    return 10 + rand() % 11;
}

int heavyAttack() {
    return 15 + rand() % 21;
}

int enemyAttack() {
    return 8 + rand() % 18;
}

int main() {
    srand(time(0));

    int health = 100;
    int ehealth = 80 + rand() % 41;
    int opt;

    while (health > 0 && ehealth > 0) {
        cout << "Your health: " << health << endl;
        cout << "Enemy health: " << ehealth << endl;

        do {
            cout << "Choose attack (1 = normal, 2 = heavy): ";
            cin >> opt;
            if (opt != 1 && opt != 2)
                cout << "Wrong option entered, try again." << endl;
        } while (opt != 1 && opt != 2);

        int damage = 0;

        if (opt == 1) {
            damage = normalAttack();
        } else {
            int chance = rand() % 100;
            if (chance < 30) {
                cout << "Heavy attack missed!" << endl;
                damage = 0;
            } else {
                damage = heavyAttack();
            }
        }

        ehealth = ehealth - damage;
        cout << "You dealt " << damage << " damage." << endl;

        if (ehealth <= 0)
            break;

        int edamage = enemyAttack();
        health = health - edamage;
        cout << "Enemy dealt " << edamage << " damage." << endl;
        cout << endl;
    }

    ofstream fout("battlelog.txt");

    if (ehealth <= 0) {
        cout << "Player won" << endl;
        fout << "Player won";
    } else {
        cout << "Enemy won" << endl;
        fout << "Enemy won";
    }

    fout.close();
    return 0;
}