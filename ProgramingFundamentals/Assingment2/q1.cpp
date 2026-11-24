#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int len = 10;
void disDungeon(int dungeon[len][len]);
int main(){
    srand(time(0));
    return 0;
}
void disDungeon(int dungeon[len][len]){
    for (int i = 0; i < len; i++){
    for (int j = 0; j < len; j++)
        dungeon[i][j] = 0;
    }
    //treasure
    for(int i=0; i<=10;i++){
        int a =rand()%10;
        int b =rand()%10;
        dungeon[a][b] = 1;
    }
        //monster
        for(int i=0; i<=5;i++){
        int a =rand()%10;
        int b =rand()%10;
        dungeon[a][b] = 2;
    }
}