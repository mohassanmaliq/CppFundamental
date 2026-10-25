#include<iostream>
using namespace std;
int main(){
  double result, a, b; 
  char oper;
  cout<<"Enter two numbers to perform a mathematical operation."<<endl;
  cout<<"Enter the first number: ";
  cin>> a;
  cout<<endl<<"Enter the second number: ";
  cin>> b;
  cout<< "Enter the operation you want to perform--> + , - , x , /"<< endl;
  cin>> oper;
  switch (oper){
    case '+' :
    result = a+b;
    break;
    case '-' :
    result = a-b;
    break;
    case 'x' :
    result = a*b;
    break;
    case '/' :
    if (b==0){
      cout<<"Number cannot be divided by Zero(0)"<<endl;
      return 0;
    }
    else
      result = a/b;
    break;
    default :
    cout<<"Invalid operator"<<endl;
    return 0;
  }
  cout<<a<<" "<<oper<<" "<<b<<" = "<<result; 

  return 0;
}