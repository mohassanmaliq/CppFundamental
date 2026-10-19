#include <iostream>
#include <fstream>
using namespace std;
ofstream out;
ifstream imp;
int main()
{
    cout << "......................................." << endl;
    int a;
    int b;
    cout << "enter two number diff by space" << endl;
    cin >> a >> b;
    int sum = a + b;
    cout << "sum is :" << sum << endl;
    out.open("data.txt");
    out << sum << endl;
    out.close();
    cout << "saved" << endl;
    return 0;
}