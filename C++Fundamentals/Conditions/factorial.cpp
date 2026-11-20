#include<iostream>
using namespace std;
long factorial(int n){
    long long result = 1;
    for (int i=1; i<=n; i++ )
    result= result*i;
    return result;
}
int main(){
int num;
cout<<"Enter a number (0-20): ";
cin>>num;
if(num<0 || num>20)
cout<<"Invalid input";
else
cout<<"Factorial = "<<factorial(num);
return 0;
}

