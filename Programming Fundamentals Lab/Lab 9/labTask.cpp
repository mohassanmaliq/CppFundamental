#include <iostream>
using namespace std;
int main() {
//-----------------Task 1
    /*int map[5][5];
    cout << "Enter treasure points (1 to 50) for the 5x5 map:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Cell [" << i << "][" << j << "]: ";
            cin >> map[i][j];
        }
    }
    cout << endl << "Treasure Map:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
    */
   int map[5][5] = {
    {10, 25, 5, 40, 15},
    {30, 12, 45, 8, 22},
    {7, 50, 18, 33, 3},
    {27, 14, 36, 1, 48},
    {20, 9, 42, 31, 16}
};
    
//-----------------Task 2
    int totalTreasure = 0;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            totalTreasure += map[i][j];
        }
    }
    int rowsum[5]={0,0,0,0,0,} ;
    int rowcol[5]={0,0,0,0,0,};
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
        rowsum[i] = rowsum[i] + map[i][j];
        rowcol[j] = rowcol[j] + map[i][j];
        }
    }
    cout << endl << "Total of all cells: " << totalTreasure << endl;
    cout<< "Row sums: "<<endl;
    for (int i=0; i<=5;i++){
        cout<<rowsum[i]<<" - ";
    }
    cout<< endl << "Column sums: "<<endl;
    for (int i=0; i<=5;i++){
        cout<<rowcol[i]<<" - ";
    }
//-----------------Task 3
int maxval = map[0][0];
int maxrow ,maxcol;
int diagonalSum = 0;
for (int i=0; i<=5;i++){
    for (int j=0; j<=5;j++){
        if (map[i][j]>maxval){
            maxval = map[i][j];
            maxrow = i;
            maxcol = j;
        }
    }
}
cout<<endl<<"Maximum value: "<<maxval<<" at position ["<<maxrow<<"]["<<maxcol<<"]"<<endl;
for(int i=0; i<5;i++){
    diagonalSum += map[i][i];
}
cout<<"Sum of diagonal elements: "<<diagonalSum<<endl;

//-----------------Task 4
 int map2[5][5] = {
        {5, 15, 20, 10, 30},
        {12, 8, 25, 40, 6},
        {33, 4, 17, 22, 9},
        {18, 29, 2, 35, 11},
        {44, 13, 7, 26, 19}
    };
int combinedMap[5][5];
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        combinedMap[i][j] = map[i][j] + map2[i][j];
    }
}
cout<<endl<<"Combined Map:"<<endl;
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        cout << combinedMap[i][j] << " - ";
    }
    cout << endl;
}

//-----------------Task 5

return 0;
}