#include <iostream>
using namespace std;
int main() {
    const int SIZE = 6;
    int scores[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> scores[i];
    }
    double sum = 0;
    int maxScore = scores[0];
    int minScore = scores[0];
    for (int i = 0; i < SIZE; i++) {
        sum += scores[i];
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
        if (scores[i] < minScore) {
            minScore = scores[i];
        }
    }
    double average = (sum) / SIZE;
    cout << "Sum     : " << sum << endl;
    cout << "Average : " << average << endl;
    cout << "Maximum : " << maxScore << endl;
    cout << "Minimum : " << minScore << endl;
    return 0;
}