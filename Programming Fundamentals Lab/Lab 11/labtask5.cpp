#include <iostream>
using namespace std;
int main(){
    const int lol = 6;
    int id[lol] = { 101, 205, 330, 412, 518, 620 };
    int *found = nullptr;
    int search;
    cout << "Enter player ID to search: ";
    cin >> search;
    for (int *p = id; p < id + lol; p++){
        if (*p == search){
            found = p;
            break;
        }}
    if (found != nullptr){
        cout << "Found at index " << found - id << endl;
        cout << "Enter new ID: ";
        cin >> *found;
        cout << "Updated list: ";
        for (int *p = id; p < id + lol; p++)
            cout << *p << " ";
        cout << endl;
    }
    else{
        cout << "Player ID " << search << " not found." << endl;
    }
    return 0;
}