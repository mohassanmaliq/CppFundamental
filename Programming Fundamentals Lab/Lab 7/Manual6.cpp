#include <iostream>
using namespace std;

void add(int& num)
{
    num = num + 10;
}
int main()
{
    int marks = 50;
    cout << "Before: " << marks << endl; 
    add(marks);
    cout << "After: " << marks << endl;  
    return 0;
}