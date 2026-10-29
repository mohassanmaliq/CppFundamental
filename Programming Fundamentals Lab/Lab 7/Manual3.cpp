#include <iostream>
using namespace std;
int total = 100;            
void show()
{
    int total = 5; 
    cout << "Local: " << total << endl<<"Global: " << ::total << endl;
}
int main()
{
    show(); 
    total++;
    cout << "Global in main: " << total << endl;
    return 0;
}