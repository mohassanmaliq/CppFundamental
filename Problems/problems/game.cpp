#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void showStatus(int playerHealth, int potions, int enemyHealth[]){
    cout<<endl;
    cout<<"Your health: "<<playerHealth<<"   Potions: "<<potions<<endl;
    for(int i = 0; i < 3; i++){
        cout<<"Enemy "<<i+1<<": ";
        if(enemyHealth[i] == 0){
            cout<<"defeated"<<endl;
        }
        else{
            cout<<enemyHealth[i]<<endl;
        }
    }
}

int main(){
    srand(time(0));
    int enemyHealth[3] = {40, 60, 80};
    int enemyPower[3] = {5, 8, 12};
    int playerHealth = 100;
    int potions = 2;
    int enemiesAlive = 3;
    int turn = 1;
    int choice, target, damage;

    while(enemiesAlive > 0 && playerHealth > 0){
        cout<<endl<<"Turn "<<turn<<endl;
        showStatus(playerHealth, potions, enemyHealth);
        cout<<"1. Attack"<<endl;
        cout<<"2. Heavy attack (50% chance to miss)"<<endl;
        cout<<"3. Use potion"<<endl;
        cout<<"Choose an action: ";
        cin>>choice;

        if(choice < 1 || choice > 3){
            cout<<"Invalid action"<<endl;
            continue;
        }

        if(choice == 3){
            if(potions == 0){
                cout<<"You have no potions left"<<endl;
                continue;
            }
            potions--;
            playerHealth = playerHealth + 30;
            if(playerHealth > 100){
                playerHealth = 100;
            }
            cout<<"You healed 30 health"<<endl;
        }
        else{
            cout<<"Choose an enemy (1-3): ";
            cin>>target;
            if(target < 1 || target > 3){
                cout<<"Invalid enemy number"<<endl;
                continue;
            }
            if(enemyHealth[target-1] == 0){
                cout<<"That enemy is already defeated"<<endl;
                continue;
            }

            if(choice == 1){
                damage = 10 + rand() % 11;
            }
            else{
                if(rand() % 100 < 50){
                    damage = 0;
                }
                else{
                    damage = 25 + rand() % 16;
                }
            }

            if(damage == 0){
                cout<<"Your heavy attack missed"<<endl;
            }
            else{
                enemyHealth[target-1] = enemyHealth[target-1] - damage;
                cout<<"You dealt "<<damage<<" damage to enemy "<<target<<endl;
                if(enemyHealth[target-1] <= 0){
                    enemyHealth[target-1] = 0;
                    enemiesAlive--;
                    cout<<"Enemy "<<target<<" is defeated"<<endl;
                }
            }
        }

        for(int i = 0; i < 3; i++){
            if(enemyHealth[i] > 0){
                int hit = 1 + rand() % enemyPower[i];
                playerHealth = playerHealth - hit;
                cout<<"Enemy "<<i+1<<" hits you for "<<hit<<endl;
            }
        }
        if(playerHealth < 0){
            playerHealth = 0;
        }
        turn++;
    }

    cout<<endl;
    if(playerHealth == 0){
        cout<<"You were defeated. Game over"<<endl;
    }
    else{
        cout<<"All enemies are defeated, you win in "<<turn-1<<" turns"<<endl;
    }
    return 0;
}