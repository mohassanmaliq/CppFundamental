#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
  int i=0;
  srand(time(0));
  for(;i<=10;i++)
    cout<< rand()%6<< endl;
  cout<< "all random numbers printed";
  return 0;
}