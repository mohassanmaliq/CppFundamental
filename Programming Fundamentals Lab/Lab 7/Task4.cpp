#include <iostream>
using namespace std;
int volume(int side); 
double volume(double radius, double height);   
double volume(double length, double width, double height);   
int main() {
    cout << "Volume of cube (side = 3): " << volume(3) << endl;
    cout << "Volume of cylinder (r = 2.0, h = 5.0): " << volume(2.0, 5.0) << endl;
    cout << "Volume of box (2.0 x 3.0 x 4.0): " << volume(2.0, 3.0, 4.0) << endl;
    return 0;
}
int volume(int side) {
    return side * side * side;
}
double volume(double radius, double height) {
    return 3.14159 * radius * radius * height;
}
double volume(double length, double width, double height) {
    return length * width * height;
}