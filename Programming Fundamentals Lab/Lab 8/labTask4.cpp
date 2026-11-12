#include <iostream>
using namespace std;
int main() {
    const int SIZE = 6;
    int ids[SIZE] = { 101, 205, 330, 412, 518, 620 };
    int key;
    int pos = -1;
    cout << "Enter player ID to search: ";
    cin >> key;
    for (int i = 0; i < SIZE; i++) {
        if (ids[i] == key) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        cout << "Found at index " << pos << endl;
        int newId;
        cout << "Enter new ID: ";
        cin >> newId;
        ids[pos] = newId;
        cout << "Updated list: ";
        for (int i = 0; i < SIZE; i++) {
            cout << ids[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Player ID " << key << " not found." << endl;
    }
    return 0;
}