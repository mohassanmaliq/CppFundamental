#include <iostream>
using namespace std;
bool isEven(int n)
{
    return n % 2 == 0; 
}
int main()
{
    int x = 14;
    if (isEven(x))
        cout << x << " is even" << endl;
    else
        cout << x << " is odd" << endl;
    return 0;
}