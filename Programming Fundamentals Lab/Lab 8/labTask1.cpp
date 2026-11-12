#include <iostream>
using namespace std;
int main() {
    const int SIZE = 5;
    int temps[SIZE] = {31, 28, 35, 30, 27};
    for (int i = 0; i < SIZE; i++) {
        cout << "Day " << i + 1 << ": " << temps[i] << " C" << endl;
    }
    return 0;
}
