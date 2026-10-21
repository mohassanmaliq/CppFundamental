#include<iostream>
using namespace std;
int main(){
    int a =3;
    int*b = &a;
    cout<<"The adress of a is :"<<b<<endl;
    cout<<"The adress of a is :"<<&a<<endl;
    cout<<"The value at adress b is ;"<<*b<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Using pointers to pointers :"<<endl;
    int** c =&b;
    cout<<"The adress of b is :"<<&b<<endl;
    cout<<"The adress of b is :"<<c<<endl;
    cout<<"The value of adress of c is :"<<*c<<endl;
    cout<<"The value of adress of c(value of adress) is :"<<**c<<endl;
    cout<<"The adress of c is :"<<&c<<endl;

    return 0;
}