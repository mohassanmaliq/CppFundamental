#include <iostream>
using namespace std;
int maxOf(int a, int b);
double maxOf(double a, double b);
int maxOf(int a, int b, int c);
int main()
{
    int x, y, z;
    double p, q;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "Larger integer = " << maxOf(x, y) << endl;         
    cout << "Enter two decimal numbers: ";
    cin >> p >> q;
    cout << "Larger decimal = " << maxOf(p, q) << endl;        
    cout << "Enter three integers: ";
    cin >> x >> y >> z;
    cout << "Largest of three = " << maxOf(x, y, z) << endl;    
    return 0;
}
int maxOf(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
    cout << "Function no 1" << endl;
}
double maxOf(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
    cout << "Function no 2" << endl;

}
int maxOf(int a, int b, int c)
{
    int largest = a;
    if (b > largest)
        largest = b;
    if (c > largest)
        largest = c;
    return largest;
    cout << "Function no 3" << endl;
}