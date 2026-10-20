#include <iostream>
using namespace std;
int main(){
    int j,num, num2;
    cout <<"Enter the initial number of list that you want to use :";
    cin>>num;
    int test[num];
    for (int i = 0 ; i <= num; i++)
    {
        cout<<"Enter the number for index "<<i<<":";
        cin>>test[i];
        j++;
    }
    for (int i = 0; i < j; i++)
    {
        cout<<"The number at index "<<i<<" is :"<<test[i]<<endl;
    }
    cout<<endl<<"---------------------------------"<<endl;
    cout <<"Enter the initial number of list that you want to use :";
    cin>>num2;
    int test2[num2];
    int k=0;
    for (int i = 0 ; i <= (num2+3); i++)
    {
        cout<<"Enter the number for index "<<i<<":";
        cin>>test2[i];
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        cout<<"The number at index "<<i<<" is :"<<test[i]<<endl;
    }
    return 0;
} 