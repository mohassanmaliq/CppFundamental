#include<iostream>
#include<time.h>
using namespace std;
//for dice 
int main(){
  int i=0;
  for(;i<=5;i++)
    cout<< rand()%6+1 << endl;
  return 0;
}
