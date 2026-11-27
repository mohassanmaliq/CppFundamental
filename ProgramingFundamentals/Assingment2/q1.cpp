#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

const int len = 10;
void intDungeon(int dungeon[len][len]);
void disDungeon(int dungeon[len][len]);
void expoDungeon(int dungeon[len][len], int r, int c, int &score, int &health);
int countTreasures(int dungeon[len][len], int row, int col);
int calculateFinalScore(int score);
void saveScore(string name, int score);
void showTopScores();

int main()
{
    // 0= empty 1=treasure 2=monster 3=0found 4=1found 5=2found
    srand(time(0));
    int dungeon[len][len];
    int health=100;
    int score=0 , treasurecount=0;
    int r,c;
    intDungeon(dungeon);
    void setup(map);
    void addelements(map);
    disDungeon(dungeon);
    while(health>0 && countTreasures(dungeon, 0, 0) > 0){
        disDungeon(dungeon);
        cout<<"Your health :"<<health<<endl;
        cout<<"Your current Score :"<<score<<endl;
        cout<<"Enter Your choice"<<endl;
        cout<<"Row :";
        cin>>r;
        cout<<endl<<"Column :";
        cin>>c;
        expoDungeon(dungeon, r, c, score, health);
    }
      if (health <= 0)
        cout << "You died." << endl;
    else
        cout << "You found all the treasures!" << endl;
     int finalScore = calculateFinalScore(score);
    cout << "Final score : " << finalScore << endl;
    string name;
    cout << "Enter your name (one word) : ";
    cin >> name;
    saveScore(name, finalScore);
    showTopScores();
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

int countTreasures(int dungeon[len][len], int row, int col){
    if (row == len)
        return 0;
    int nextRow = row;
    int nextCol = col + 1;
    if (col == len - 1){
        nextRow = row + 1;
        nextCol = 0;
    }
    if (dungeon[row][col] == 1)
        return 1 + countTreasures(dungeon, nextRow, nextCol);
    return countTreasures(dungeon, nextRow, nextCol);
}

int calculateFinalScore(int score){
    return score;
}

void saveScore(string name, int score){
    ofstream file("scores.txt", ios::app);
    file << name << " " << score << endl;
    file.close();
}

void showTopScores(){
    string names[100];
    int scores[100];
    int n = 0;
    ifstream file("scores.txt");
    if (!file){
        cout << "No scores yet." << endl;
        return;
    }
    while (n < 100 && file >> names[n] >> scores[n])
        n++;
    file.close();
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (scores[j] < scores[j + 1]){
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
    cout << "Top 5 scores" << endl;
    for (int i = 0; i < n && i < 5; i++)
        cout << i + 1 << ". " << names[i] << " - " << scores[i] << endl;
}