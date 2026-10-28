// Q4 (30 marks), numbered 3 again on the paper
// Apply these concepts (arrays, loop, if-else) to solve the Mini Battle Game as
// explained in the scenario below.
// Scenario: The player fights 3 enemies. Each enemy has a fixed amount of health
// (stored in an array). In each round, the player chooses which enemy to attack and
// how much damage to deal. If an enemy's health drops to 0, they are defeated.

#include<iostream>
using namespace std;
int main(){
    int health[3] = {50, 70, 100};
    int enemy, damage, dead=3;
    while(dead!=0){
        cout<<"Enemy health:"<<endl;
        for(int i = 0; i < 3; i++){
            cout<<"Enemy "<<i+1<<": "<<health[i]<<endl;
        }
        cout<<"Choose an enemy to attack (1-3): ";
        cin>>enemy;
        if(enemy<1 || enemy>3){
            cout<<"Invalid enemy number"<<endl;
            continue;
        }
        if(health[enemy-1]==0){
            cout<<"That enemy is already defeated"<<endl;
            continue;
        }
        cout<<"Enter the damage to deal: ";
        cin>>damage;
        if(damage<=0){
            cout<<"Damage must be greater than 0"<<endl;
            continue;
        }
        health[enemy-1]=health[enemy-1]-damage;
        if(health[enemy-1]<=0){
            health[enemy-1]=0;
            dead=dead-1;
            cout<<"Enemy "<<enemy<<" is defeated"<<endl;
        }
    }
    cout<<"All enemies are defeated, you win"<<endl;
    return 0;
}