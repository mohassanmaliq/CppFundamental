#include <iostream>
using namespace std;
double area(double length = 11 , double width = 1.0);
int main()
{
    cout << area(5, 4) << endl;  
    cout << area(5) << endl;  
    cout << area() << endl;
    return 0;
}
double area(double length, double width)
{
    return length * width;
}