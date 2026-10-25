// Q2 (25 marks)
// Given an array of N integers and a target value K, apply (arrays, loop, if-else)
// to find the index number from the array whose value is equal to the target value K.
// Input: arr[] = {1, 5, 7, -1, 4}, K = 7
// Output: 2
// Explanation: Target value 7 is stored at 3rd index of the array, which is index value = 2.
// Input: arr[] = {1, 1, 1, 1}, K = 2
// Output: 6

#include<iostream>
using namespace std;
int main(){
    int arr[] = {1, 5, 7, -1, 4};
    int k=7,index, val=5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr);
    cout<<"The size of the array is "<< m<<endl;
    cout<<"The length of the array is "<< n<<endl;
    for (index=0;index<val;index++){
        if(k==arr[index]){
        cout<<"Target value "<<k<<" is stored at index "<<index<<endl;
        break;
        }
    }
    return 0;
}