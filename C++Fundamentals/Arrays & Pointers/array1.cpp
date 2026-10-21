#include <iostream>
using namespace std;
long factorial(int n)
{
long long result = 1;
for (int i = 1; i <= n; i++)
{
result *= i;
}
return result;
}
int main()
{
int number;
cout << "Enter a number (0-20): ";
cin >> number;
if (number < 0 || number > 20)
cout << "Invalid input";
else
cout << "Factorial = " <<
factorial(number);
return 0;
}
