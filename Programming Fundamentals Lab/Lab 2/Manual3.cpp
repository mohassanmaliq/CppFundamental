#include <iostream>
#include <fstream>
using namespace std;
ofstream out;
ifstream imp;
int main()
{
    cout << "enter lines" << endl;
    out.open("data.txt");
    out << "adam" << endl;
    out << "ali" << endl;
    out << "hassan" << endl;
    out.close();
    cout << "done" << endl;
}