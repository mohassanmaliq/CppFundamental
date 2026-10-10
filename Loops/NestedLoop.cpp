#include<iostream>
using namespace std;
int main()
{
	// nested loop: a loop inside another loop
	// the inner loop runs fully for every single pass of the outer loop
	// multiplication table of 1 to 3
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
	// star triangle
	for (int row = 1; row <= 5; row++)
	{
		for (int star = 1; star <= row; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}