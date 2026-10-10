#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
  int i=0;
  srand(time(0));
  for(;i<=10;i++)
    cout<< rand()%6<<" ";
  cout<<endl<<"all random numbers printed"<<endl;
  cout<<"............................"<<endl;
//For random numbers between 0-9
  int j=0;
  srand(time(0));
  for(;j<=10;j++)
    cout<< rand()%10<<" ";
  cout<<endl<<"all random numbers bw 0-9 printed"<<endl;
   cout<<"............................"<<endl;
  //For random numbers bw 0-99
  int k=0;
  srand(time(0));
  for(;k<=10;k++)
    cout<< rand()%100<<" ";
  cout<<endl<<"all random numbers bw 0-99 printed"<<endl;
   cout<<"............................"<<endl;
  //For applying range
  //min + rand() %(max-min+1)
  int l=0;
  srand(time(0));
  for(;l<=10;l++)
    cout<< 50+rand()%51<<" ";
  cout<<endl<<"random numbers bw range"<<endl;
  cout<<"Minimum Number:";
  cout<<"............................"<<endl;
//Taking Range from User
int a, b;
cout<<"Enter the range of random Numbers you want"<<endl;
cout<<"Minimum Number:";
cin>> a;
cout<<endl<<"Mamimum Number:";
cin>> b;
cout<<endl<<"10 Random numbers of range"<<a<<" to "<<b<<" is"<<endl;
srand(time(0));
for(int c=0; c<=10 ;c++)
  cout<< a+rand() %((b-a)+1)<<" ";
cout<<endl<<"............................"<<endl;
return 0;
}