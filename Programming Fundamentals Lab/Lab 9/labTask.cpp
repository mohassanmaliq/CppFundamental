#include <iostream>
using namespace std;
int main() {
    int map[5][5];
    cout << "Enter treasure points (1 to 50) for the 5x5 map:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Cell [" << i << "][" << j << "]: ";
            cin >> map[i][j];
        }
    }
    cout << endl << "Treasure Map:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}