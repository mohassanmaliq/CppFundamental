#include <iostream>
using namespace std;

int binarySearch(int array[], int size, int value)
{
int first = 0, // First array element
last = size - 1, // Last array element
middle, // Mid point of search
position = -1; // Position of search value
bool found = false; // Flag
while (!found && first <= last)
{
middle = (first + last) / 2; // Calculate mid point
if (array[middle] == value) // If value is found at mid
{
found = true;
position = middle;
}
else if (array[middle] > value) // If value is in lower half
last = middle - 1;
else
first = middle + 1; // If value is in upper half
}
return position;
}
int main(){
    int arr[25] = {3,4,5,5,5,5,6,6,7,7,7,12,12,20,34,35,54,56,57,57,234,313,547,567};
    int n = sizeof(arr) / sizeof(arr[0]);
    int desire;
    int ans;
    cout << "Enter the value you want to find" << endl;
    cin >> desire;
    ans = binarySearch(arr,n,desire);
    if(ans == -1){
        cout<<"Number not found"<<endl;
        return 0;
    }
    cout << "the desired value is at index no : " << ans << endl;
    return 0;
}