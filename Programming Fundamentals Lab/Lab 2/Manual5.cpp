#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fileReader;
    string userFilePath;
    int val1, val2, val3;
    cout << "Please specify the file name: ";
    cin >> userFilePath;
    fileReader.open(userFilePath.c_str());
    fileReader >> val1 >> val2 >> val3;
    cout << "Extracted numbers: " << val1 << ", " << val2 << ", " << val3 << endl;
    int grandTotal = val1 + val2 + val3;
    cout << "Calculated Sum: " << grandTotal << endl;
    fileReader.close();
}