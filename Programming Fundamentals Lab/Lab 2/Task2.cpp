#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("marks.txt");
    ofstream fout("result.txt");
    int m1, m2, m3, m4, m5, regNo;
    fin >> regNo;
    fin >> m1 >> m2 >> m3 >> m4 >> m5;
    int total = m1 + m2 + m3 + m4 + m5;
    double average = total / 5.0;
    double percentage = total / 5.0;
    //reading
    cout << "Registration No : " << regNo << endl;
    cout << "Marks : " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
    cout << "Total : " << total << " / 500" << endl;
    cout << "Average : " << average << endl;
    cout << "Percentage : " << percentage << " %" << endl;
    //saving
    fout << "Registration No : " << regNo << endl;
    fout << "Marks : " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
    fout << "Total : " << total << " / 500" << endl;
    fout << "Average : " << average << endl;
    fout << "Percentage : " << percentage << " %" << endl;
    fin.close();
    fout.close();
    return 0;
}