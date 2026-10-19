#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outFile;
    int num1, num2, num3;
    outFile.open("data.txt");
    cout << "Enter 1st number: ";
    cin >> num1;
    cout << "Enter 2nd number: ";
    cin >> num2;
    cout << "Enter 3rd number: ";
    cin >> num3;
    outFile << num1 << endl;
    outFile << num2 << endl;
    outFile << num3 << endl;
    cout << "The numbers are saved to a file." << endl;
    outFile.close();
    cout << "Done." << endl;
    return 0;
}