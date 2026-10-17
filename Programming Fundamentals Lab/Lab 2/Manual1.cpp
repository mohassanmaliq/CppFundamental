#include <iostream> 
#include <fstream> 
using namespace std;
ofstream out;
int main()
{
 ifstream fin;
 fin.open("data.txt");
 int num1, num2;
 fin >> num1;
 fin >> num2;
 cout << "1st Number: " << num1 << endl;
 cout << "2nd Number: " << num2 << endl;
 int sum = num1 + num2;
 cout << "SUM = " << sum << endl;
 fin.close();
 return 0;
}