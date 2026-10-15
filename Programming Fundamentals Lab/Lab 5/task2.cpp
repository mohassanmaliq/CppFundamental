#include<iostream>
using namespace std;
int main() {
	int num=1;
    for (int i = 1; i <= 5; i++) {
        for (int s = 1; (s <= 5 - i); s++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << num << "   ";
            num++;
        }
        cout << endl;
    }
    for (int i = 4; i >= 1; i--) {
        for (int s = 1; s <= 5 - i; s++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << num << "   ";
            if (num < 10) {
                cout << " ";
            }
            num++;
        }
        cout << endl;
    }
	return 0;
}