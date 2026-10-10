#include<iostream>
using namespace std;
int main()
{
	// for loop: use it when you know how many times to repeat
	// for (start; condition; step)
	for (int i = 1; i <= 5; i++)
	{
		cout << "Count: " << i << endl;
	}
	// counting backwards
	for (int i = 5; i >= 1; i--)
	{
		cout << i << " ";
	}
	cout << endl;
	// sum of numbers 1 to 10
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	cout << "Sum of 1 to 10 = " << sum << endl;
	return 0;
}