#include<iostream>
using namespace std;
int main()
{
	// while loop: checks the condition first, then runs the body
	// use it when you don't know in advance how many times to repeat
	int i = 1;
	while (i <= 5)
	{
		cout << "Count: " << i << endl;
		i++;
	}
	// reverse a number using while
	int num = 1234, rev = 0;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	cout << "Reversed number = " << rev << endl;
	return 0;
}