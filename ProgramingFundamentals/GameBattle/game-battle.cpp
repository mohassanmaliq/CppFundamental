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
#include<string>
using namespace std;
int main(){
  int health=100, damage;
  char attack;
  srand(time(0));
  do{
    cout<<endl<<"Do you want to attacck or defend?(For Yes press y)";
    cin >> attack;
    if(attack=='y')
    {
      damage= 10+(rand()%((25-10)+1));
      health= health-damage;
      ofstream out;
      out.open("record.txt", ios::app);
      out<<"Health Remaining = "<<health<<endl;
      out<<"Damaged dealt = "<<damage<<endl;
      out.close();
      cout<<"Health Remaining = "<<health<<endl;
      cout<<"Damaged dealt = "<<damage<<endl;
    }
    else{
      cout <<endl<<"Attack blocked"<<endl;
      ofstream out2;
      out2.open("record.txt", ios::app);
      out2<<"Health Remaining = "<<health<<endl;
      out2<<"Damaged dealt = 0"<<endl;
      out2.close();
      cout<<"Health Remaining = "<<health<<endl;
      cout<<"Damaged dealt = 0"<<endl;
    }
  }
  while(health>=0);
    if(health<=0)
      cout<<endl<<"GAME OVER"<<endl;
  ifstream in;
  in.open("record.txt");
  string line;
  while(getline(in, line))
    cout<<line<<endl;
  in.close();
  return 0;
}