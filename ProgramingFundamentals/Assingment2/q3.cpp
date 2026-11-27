#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;
const int len = 10;
int zombie = 8;
int health = 100;
int score =0;

void setup(int map[SIZE][SIZE]);
void addelements(int map[len][len]);

int main(){
    srand(time(0));
    int map[SIZE][SIZE];

    cout<<"=========================================="<<endl;
    cout<<"++++++++++++  Game Started   +++++++++++++"<<endl;
    cout<<"CONTROLS : W=forward A=left D=right S=down"<<endl;
    cout<<"           1=attack "<<endl;
    cout<<"LEGENDS  :  P=player Z=zombie #=obstacle"<<endl;
    while(health>0 && zombie!=0){
    setup(map);
    addelements(map);
    // for (int i = 0; i < len; i++){
    //     for (int j = 0; j < len; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;  }
    }//whilelooop
}

void setup(int map[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            map[i][j] = 0;
        }
    }
    //zombie
    int placed = 0;
    while (placed < 8){
        int a = rand() % 10;
        int b = rand() % 10;
        if (map[a][b] == 0){
            map[a][b] = 1;
            placed++;
        }
    }
    //obstacles
    placed = 0;
    while (placed < 10){
        int a = rand() % 10;
        int b = rand() % 10;
        if (map[a][b] == 0){
            map[a][b] = 2;
            placed++;
        }
    }
    //Health pack
    placed = 0;
    while (placed < 5){
        int a = rand() % SIZE;
        int b = rand() % SIZE;
        if (map[a][b] == 0){
            map[a][b] = 3;
            placed++;
        }
    }

    placed = 0;
    while (placed <=0){
        int a = rand() % SIZE;
        int b = rand() % SIZE;
        if (map[a][b] == 0){
            map[a][b] = 4;
            placed++;
        }
    }
}


void addelements(int map[len][len]){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            switch (map[i][j]){
                case 0:
                cout << " . ";
                break;
                case 1:
                cout << " Z ";
                break;
                case 2:
                cout << " # ";
                break;
                case 3:
                cout << " H ";
                break;
                case 4:
                cout << " P ";
                break;
                case 5:
                cout << " # ";
                break;
            }
        }
        cout << endl;
    }
}