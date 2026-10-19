#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream data;
    data.open("data.txt", ios::out);
    cout << "writing data." << endl;
    data << "Adam" << endl;
    data << "alex" << endl;
    data.close();
    data.open("data.txt", ios::app);
    data << "hell0o" << endl;
    data << "yunus" << endl;
    data.close();
    cout << "Completed" << endl;
    return 0;
}