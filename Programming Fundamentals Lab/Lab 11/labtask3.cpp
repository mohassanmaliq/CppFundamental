#include <iostream>
using namespace std;
int main(){
    const int def = 6;
    int score[def];
    int* p = score;
    for (int i = 0; i < def; i++){
        cout << "Enter score " << i + 1 << ": ";
        cin >> *(p + i);
    }
    int sum = 0;
    int max = *p;
    int min = *p;
    for (int i = 0; i < def; i++){
        sum += *(p + i);
        if (*(p + i) > max)
            max = *(p + i);
        if (*(p + i) < min)
            min = *(p + i);
    }
    double average = (double)sum / def;
    cout << "Sum     : " << sum << endl;
    cout << "Average : " << average << endl;
    cout << "Maximum : " << max << endl;
    cout << "Minimum : " << min << endl;
    return 0;
}