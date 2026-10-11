#include <iostream>
using namespace std;
int main() {
    int choice;
    cout << "Enter the number of day of the week (1-7): ";
    cin >> choice;
    if(choice>=1 && choice<=7)
        cout<<"Today the day is ";
    switch (choice) {
        case 1:
            cout << "Monday\n";
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        case 4:
            cout << "Thursday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        case 6:
            cout << "Saturday\n";
            break;
        case 7:
            cout << "Sunday\n";
            break;
        default:
            cout << "Invalid choice\n";
    }
    return 0;
}