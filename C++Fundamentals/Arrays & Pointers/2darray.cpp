#include<iostream>
using namespace std;
int main(){
  int arr[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };
for(i=0;i=<3,i++){
    for(i=0;i=<3,i++){
        cout << arr[i][j] << " ";
    }
}
  return 0;
}