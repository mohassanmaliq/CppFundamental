#include<iostream>
using namespace std;
int main(){
int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Using pointer arithmetic"<<endl;
    for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
            cout<<k<<"-"<<l<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Diagonal prints"<<endl;
    for(int m = 0; m < 3; m++){
        cout<<a[m][m]<<" ";
    }
    cout<<endl;
    return 0;
}