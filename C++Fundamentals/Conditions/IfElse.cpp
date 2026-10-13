#include <iostream>
using namespace std;
int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;
    if (marks >= 90)
        cout << "Grade A\n";
    else if (marks >= 80)
        cout << "Grade B\n";
    else if (marks >= 70)
        cout << "Grade C\n";
    else if (marks >= 60)
        cout << "Grade D\n";
    else if (marks >= 50)
        cout << "Grade E\n";
    else
        cout << "Fail\n";
    return 0;
}