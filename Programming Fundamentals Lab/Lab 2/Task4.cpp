#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string inName, outName;
    double c1, c2, c3;
    cout << "Enter input filename: ";
    cin >> inName;
    cout << "Enter output filename: ";
    cin >> outName;
    ifstream in(inName.c_str());
    ofstream out(outName.c_str());
    in >> c1 >> c2 >> c3;
    out << "Celsius\tFahrenheit" << endl;
    out << c1 << "\t" << c1 * 9 / 5 + 32 << endl;
    out << c2 << "\t" << c2 * 9 / 5 + 32 << endl;
    out << c3 << "\t" << c3 * 9 / 5 + 32 << endl;
    cout << "Conversion complete. Check " << outName << endl;
}