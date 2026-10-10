#include<iostream>
using namespace std;
int main()
{
	// do-while loop: runs the body first, then checks the condition
	// so the body always runs at least once
	int i = 1;
	do
	{
		cout << "Count: " << i << endl;
		i++;
	} while (i <= 5);
	// repeat until the user enters a positive number
	int n;
	do
	{
		cout << "Enter a positive number: ";
		cin >> n;
	} while (n <= 0);
	cout << "You entered " << n << endl;
	return 0;
}