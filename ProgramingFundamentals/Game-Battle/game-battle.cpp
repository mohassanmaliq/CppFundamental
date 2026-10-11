/*
Question No. 1.
A player starts with 100 health points. Each enemy attack reduces health
by a random amount between 10 and 25.

Write a program using a loop that:
- Continues attacking while the player's health is above zero.
- Generates a random damage value (10 to 25) for each attack.
- Player can defend also when enemy attack. In this case, the damage will
  not effect player's health and run the next iteration of loop.
- Store the 'attack number' and 'damage value' and 'remaining health' in a file.
- Displays "GAME OVER" when the player's health reaches zero or below.
*/

#include<iostream>
#include<fstream>
#include<cstdlib> //random functions
#include<ctime>
using namespace std;
int main(){
  int health=100, damage;
  char attack;
  srand(time(0));
  do{
    cout<<"Do you want to attacck or defend?(For Yes press y)";
    cin >> attack;
    if(attack=='y')
    {
      damage= 10+(rand()%((25-10)+1));
      health= health-damage;
      ofstream out;
      out.open("record.txt");
      out<<"Health Remaining"<<health;
      out<<"Damaged dealt"<<damage;
      out.close();
      cout<<"Health Remaining"<<health;
      cout<<"Damaged dealt"<<damage;
    }
    else
      cout <<endl<<"Attack blocked"<<endl;
      ofstream out2;
      out2.open("record.txt");
      out2<<"Health Remaining"<<health;
      out2<<"Damaged dealt = 0";
      out2.close();
      cout<<"Health Remaining"<<health;
      cout<<"Damaged dealt = 0";
  }
  while(health>=0);
    if(health<=0)
      cout<<"GAME OVER";
  return 0;
}