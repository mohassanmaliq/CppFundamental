#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int len = 10;
void intDungeon(int dungeon[len][len]);
void disDungeon(int dungeon[len][len]);
void expoDungeon(int dungeon[len][len], int r, int c, int &score, int &health);

int main()
{
    // 0= empty 1=treasure 2=monster 3=0found 4=1found 5=2found
    srand(time(0));
    int dungeon[len][len];
    int health=100;
    int score=0 , treasurecount=0;
    int r,c;
    intDungeon(dungeon);
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            cout << dungeon[i][j] << " ";
        }
        cout << endl;  } 
    disDungeon(dungeon);
    while(health>0 && treasurecount<=4 ){
        disDungeon(dungeon);
        cout<<"Enter Your choice"<<endl;
        cout<<"Row :";
        cin>>r;
        cout<<endl<<"Column :";
        cin>>c;
        expoDungeon(dungeon, r, c, score, health);
    }
    return 0;
}

void intDungeon(int dungeon[len][len]){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            dungeon[i][j] = 0;
        }
    }
    int placed = 0;//treasure
    while (placed < 10){
        int a = rand() % len;
        int b = rand() % len;
        if (dungeon[a][b] == 0){
            dungeon[a][b] = 1;
            placed++;
        }
    }
    placed = 0;//monster
    while (placed < 5){
        int a = rand() % len;
        int b = rand() % len;
        if (dungeon[a][b] == 0){
            dungeon[a][b] = 2;
            placed++;
        }
    }
}

void disDungeon(int dungeon[len][len]){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            switch (dungeon[i][j]){
                case 0:
                cout << " ?("<<i<<"-"<<j<<")";
                break;
                case 1:
                cout << " ?("<<i<<"-"<<j<<")";
                break;
                case 2:
                cout << " ?("<<i<<"-"<<j<<")";
                break;
                case 3:
                cout << " .("<<i<<"-"<<j<<")";
                break;
                case 4:
                cout << " T("<<i<<"-"<<j<<")";
                break;
                case 5:
                cout << " M("<<i<<"-"<<j<<")";
                break;
            }
        }
        cout << endl;
    }
}

void expoDungeon(int dungeon[len][len], int r, int c, int &score, int &health){
    switch (dungeon[r][c]){
        case 0:
        cout<<"The cell is empty try another one"<<endl;
        dungeon[r][c]=3;
        break;
        case 1:
        cout<<"Hurray!!! You found a Treasure Cheast"<<endl;
        score=score+10;
        dungeon[r][c]=4;
        break;
        case 2:
        cout<<"Ohhh No!!! A Monster attacked"<<endl;
        health=health-20;
        dungeon[r][c]=5;
        break;
        default:
        cout<<"Already Explored Try another cell"<<endl;
        break;
    }
}