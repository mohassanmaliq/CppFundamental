#include <iostream>
using namespace std;
int main(){
    int test[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 10; i++)
    {   
        cout<<"The number at index "<<i<<" is :"<<test[i]<<endl;
    }
    cout<<"The number at index 13 is :"<<test[13]<<endl;
    cout<<"The number at index 14 is :"<<test[14]<<endl;
    cout<<"The number at index 15 is :"<<test[15]<<endl;
    cout<<"The number at index 16 is :"<<test[16]<<endl;

    return 0;
}