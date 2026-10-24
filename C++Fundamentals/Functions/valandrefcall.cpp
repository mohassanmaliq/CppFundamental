#include<iostream>
using namespace std;

void refpoint(int*a,int*b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void refvar(int&a,int&b){
    int temp= a;
    a=b;
    b=temp;
}
int& refvar2(int&a,int&b){
    int temp= a;
    a=b;
    b=temp;
    return a;
}

int main(){
    int x =4, y=5;
    // cout<<"The sum of 4 and 5 is "<<sum(a, b);
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    // swap(x, y); // This will not swap a and b
    refpoint(&x, &y); //This will swap a and b using pointer reference
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    refvar(x, y); //This will swap a and b using reference variables
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    refvar2(x, y) = 766; //This will swap a and b using reference variables
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    return 0;
}