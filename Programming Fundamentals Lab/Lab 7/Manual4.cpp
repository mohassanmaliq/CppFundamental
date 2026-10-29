#include <iostream>
using namespace std;
void counter()
{
    static int statics = 0;  
    int normal = 0;     
    statics++;
    normal++;
    cout << "static = " << statics << ", normal = " << normal << endl;
}
int main()
{
    for (int i = 0; i < 3; i++)
        counter();
    return 0;
}