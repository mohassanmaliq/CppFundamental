//linear search function
int linearSearch(int list[]; int arrlen ; int val){
    int index =0;
    int position = -1;
    bool found =false;
    while(index<arrlen && !found){
        if(list[index]==val){
            found=true;
            position = index;
        }
        index++;
    }
    return position;
}
int main{
    int arr[25]={20,34,54,234,12,313,12,3,4,5,35,5,6,7,56,5,7,57,547,5,67,6,57,567,7}
    int n= sizeof(arr)/sizeof(arr[0])
    int desire;
    int ans;
    cout<<"Enter the value you want to find"<<endl;
    cin>>desire;
    ans = linearsearch(arr[]; n ; desire)
}