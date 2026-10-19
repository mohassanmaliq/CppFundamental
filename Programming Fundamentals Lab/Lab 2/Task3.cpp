#include <iostream>
#include <fstream>
using namespace std;
int main() {
    const double PI = 3.14159;
    double l, w, r;
    ifstream in("data.txt");
    ofstream out("geometry_report.txt");
    in >> l >> w >> r;
    double rectArea = l * w;
    double rectPerimeter = 2 * (l + w);
    double circleArea = PI * r * r;
    double circumference = 2 * PI * r;
    out << "----- GEOMETRY REPORT -----" << endl;
    out << "Rectangle (" << l << " x " << w << ")" << endl;
    out << "  Area = " << rectArea << endl;
    out << "  Perimeter = " << rectPerimeter << endl;
    out << "Circle radius " << r << endl;
    out << "  Area = " << circleArea << endl;
    out << "  Circumference = " << circumference << endl;
}