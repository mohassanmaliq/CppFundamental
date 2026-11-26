#include <iostream>
using namespace std;
int main(){
    int coins[] = { 5, 12, 7, 20, 3, 15 };
    int *p = coins;
    for (int i = 0; i < 6; i++){
        cout << "Address " << p << " : " << *p << endl;
        p++;
    }
    cout << "Reverse display: ";
    p = coins + 5;
    for (int i = 0; i < 6; i++){
        cout << *p << " ";
        p--;
    }
    cout << endl;
    int *left = coins;
    int *right = coins + 5;
    while (left < right){
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    cout << "Reversed array : ";
    for (int i = 0; i < 6; i++)
        cout << *(coins + i) << " ";
    cout << endl;
    int *first = coins;
    int *last = coins + 5;
    cout << "Elements between first and last: " << last - first << endl;
    return 0;
}