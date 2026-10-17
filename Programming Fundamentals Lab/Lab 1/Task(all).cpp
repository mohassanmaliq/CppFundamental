#include <iostream>
#include <string>
using namespace std;
int main()
{
 cout << "......................................................." << endl;
cout << "LAB TASK 02 AND TASK 03" << endl; //initializing variables
 //double data type is used for values in points
 double num1, num2, add1, add2, sub1, sub2 ,mul1, mul2, div1, div2 ;
 // taking numbers from user
 cout << "Enter first number= " << endl;
 cin >> num1;
 cout << "Enter second number= " << endl;
 cin >> num2;
 // output of the calculations
 cout << "...... Calculation Results ......" << endl;
 cout << "Addition (" << num1 << " + " << num2 << ") = " << (num1 + num2) << 
endl;
 cout << "Subtraction (" << num1 << " - " << num2 << ") = " << (num1 - num2) << 
endl;
 cout << "Multiplication (" << num1 << " * " << num2 << ") = " << (num1 * num2) << 
endl;
 cout << "Division(" << num1 << " /" << num2 << ")=" << (num1 / num2) << endl;
 cout << "......................................................." << endl;
 cout << "LAB TASK 04" << endl;
 //For addition
 cout << "Enter two numbers for addition" << endl;
 cin >> add1 >> add2;
 //For subtraction
 cout << "Enter two numbers for subtraction" << endl;
 cin >> sub1 >> sub2;
 //For multiplication
 cout << "Enter two numbers for multiplication" << endl;
 cin >> mul1 >> mul2;
 //For division cout << "Enter two numbers for division" << endl;
 cin >> div1 >> div2;
 // output of the calculations
 cout << "...... Calculation Results ......" << endl;
 cout << "Addition (" << add1 << " + " << add2 << ") = " << (add1 + add2) << endl;
 cout << "Subtraction (" << sub1 << " - " << sub2 << ") = " << (sub1 - sub2) << 
endl;
 cout << "Multiplication (" << mul1 << " * " << mul2 << ") = " << (mul1 * mul2) << 
endl;
 cout << "Division(" << div1 << " /" << div2 << ")=" << (div1 / div2) << endl;
 cout << "......................................................." << endl;
 cout << "LAB TASK 01" << endl;
 cout << " *" << endl;
 cout << " ***" << endl;
 cout << " *****" << endl;
 cout << " *******" << endl;
 cout << " *********" << endl;
 cout << "......................................................." << endl;
 cout << "LAB TASK 05" << endl;
 cout << "--- Size of C++ Data Types ---" << endl;
 cout << "Size of char: " << sizeof(char) << " byte(s)" << endl;
 //int
 cout << "Size of short: " << sizeof(short) << " byte(s)" << endl;
 cout << "Size of int" << sizeof(int) << " byte(s)" << endl;
 cout << "Size of long: " << sizeof(long) << " byte(s)" << endl;
 cout << "Size of long long: " << sizeof(long long) << " byte(s)" << endl;
 //float
 cout << "Size of float : " << sizeof(float) << " byte(s)" << endl; cout << "Size of double: " << sizeof(double) << " byte(s)" << endl;
 cout << "Size of long double" << sizeof(long double) << " byte(s)" << endl;
 
 return 0;
}