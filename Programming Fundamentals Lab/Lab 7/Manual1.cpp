#include <iostream>
using namespace std;
double average(int a, int b, int c);      
int main()
{
    double avg = average(70, 85, 90);     
    cout << "Average = " << avg << endl;
    return 0;
}
double average(int a, int b, int c)
{
    return (a + b + c) / 3.0;             
}