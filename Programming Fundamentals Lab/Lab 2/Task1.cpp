#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream o;
    string firstName;
    string regNo;
    string department;
    int semester;
    double cgpa;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter registration no: ";
    cin >> regNo;
    cout << "Enter department: ";
    cin >> department;
    cout << "Enter semester: ";
    cin >> semester;
    cout << "Enter CGPA: ";
    cin >> cgpa;
    o.open("data.txt");
    o << "=============================" << endl;
    o << "     STUDENT PROFILE CARD    " << endl;
    o << "=============================" << endl;
    o << "Name         : " << firstName << endl;
    o << "Registration : " << regNo << endl;
    o << "Department   : " << department << endl;
    o << "Semester     : " << semester << endl;
    o << "CGPA         : " << cgpa << endl;
    o << "=============================" << endl;
    o.close();
    cout << "Profile saved to data.txt" << endl;
    return 0;
}