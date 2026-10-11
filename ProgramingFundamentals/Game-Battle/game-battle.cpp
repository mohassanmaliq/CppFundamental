 /*
   Question No. 1. Develop a simple Dungeon Survival Game using the following requirements:
   1. Generate random enemy damage between 5 and 20.
   2. Classify player health:
      o Above 70: "Healthy"
      o From 31 to 70: "Injured"
      o From 1 to 30: "Critical"
      o Zero or below: "Dead"
   3. Use switch to let the player select Attack, Heal, or Exit. For an Attack player gets 10 score,
      for a Heal player will loss 5 score, and for Exit the loop runs next iteration.
   4. Continue the game until the player dies.
   5. Save the player's final score to dungeon_scores.txt.
   6. At the end of program, read and display previously saved scores from the file.
   */

   #include <iostream>
   #include <fstream>
   #include <string>
   #include <cstdlib>
   #include <ctime>
   #include <cctype>
   using namespace std;
   int main() {
       srand(time(0));
       int health = 100, score = 0, damage,i=0;
       char choice;
       do {
           i++;
           cout<<"--------------------------"<<endl;
           cout<<"Round = "<<i<<endl;
           if (health > 70) {
               cout << "Health: " << health << " (Healthy)  Score: " << score << endl;
           }
           else if (health >= 31) {
               cout << "Health: " << health << " (Injured)  Score: " << score << endl;
           }
           else if (health >= 1) {
               cout << "Health: " << health << " (Critical)  Score: " << score << endl;
           }
           else {
               cout << "Health: " << health << " (Dead)  Score: " << score << endl;
           }

           cout << "A. Attack"<<endl<<  "B. Heal"<<endl<<  "C. Exit"<<endl<<"Your choice = ";
           cin >> choice;
           choice = toupper(choice);

           switch (choice) {
               case 'A':
                   score += 10;
                   damage = 5 + rand() % 16;
                   health -= damage;
                   cout << "Enemy hits for " << damage << endl;
                   break;
               case 'B':
                   health += 5;
                   score -= 5;
                   damage = 5 + rand() % 16;
                   health -= damage;
                   cout << "Enemy hits for " << damage << endl;
                   break;
               case 'C':
                   break;
               default:
                   cout << "Invalid option" << endl;
           }
       } while (health > 0 && choice != 'C');

       if (health > 70) {
           cout << "Status: Healthy" << endl;
       }
       else if (health >= 31) {
           cout << "Status: Injured" << endl;
       }
       else if (health >= 1) {
           cout << "Status: Critical" << endl;
       }
       else {
           cout << "Status: Dead" << endl;
       }
       // save the final score
       ofstream out;
       out.open("dungeon_scores.txt", ios::app);
       out << "Score = " << score << endl;
       out << "Round = " << i << endl;
       out.close();
       // read and display the saved scores
       ifstream in;
       in.open("dungeon_scores.txt");
       string line;
       cout << "Previous scores:" << endl;
       while (getline(in, line))
           cout << line << endl;
       in.close();
       return 0;
   }