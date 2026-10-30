#include <iostream>
using namespace std;

int main() {
    double marks;
    cout << "Enter marks: "<<endl;
    cin >> marks;
    if (marks > 90)
        cout << "Grade: A" << endl;
    else if (marks >= 86)
        cout << "Grade: A-" << endl;
    else if (marks >= 81)
        cout << "Grade: B+" << endl;
    else if (marks >= 77)
        cout << "Grade: B" << endl;
    else if (marks >= 72)
        cout << "Grade: B-" << endl;
    else if (marks >= 68)
        cout << "Grade: C+" << endl;
    else if (marks >= 63)
        cout << "Grade: C" << endl;
    else if (marks >= 58)
        cout << "Grade: C-" << endl;
    else if (marks >= 54)
        cout << "Grade: D+" << endl;
    else if (marks >= 50)
        cout << "Grade: D" << endl;
    else
        cout << "Grade: F" << endl;
    return 0;
}