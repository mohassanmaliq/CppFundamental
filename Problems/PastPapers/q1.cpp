// Q1 (20 marks)
// Imagine you have a game menu where the player can select an option by entering
// a number from 1 to 5:
// 1. Start Game
// 2. Load Game
// 3. Settings
// 4. Help
// 5. Exit
// Should you use a switch statement or an if-else-if ladder?
// I.  State your choice and give a strong reason why it is better suited for this scenario.
// II. If the input was a string command like "start", "load", "settings", etc.,
//     what should you prefer to use and why?



// answer
// I. Choice: switch statement.
// The player enters a single number from 1 to 5, and each number maps to exactly
// one menu option. A switch is made for this: every case matches one fixed value,
// so the code looks like the menu itself and is easy to read. The default case
// handles invalid input, and adding a new option later only needs one more case.
// An if-else-if ladder would repeat the same comparison for every option.

// II. Choice: if-else-if ladder.
// If the input is a string like "start" or "load", switch can't be used because
// C++ switch only works with integers and characters. Strings have to be compared
// with ==, so an if-else-if ladder is the right choice here.




#include<iostream>
using namespace std;
int main(){
    int opt;
    cout << "1. Start Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Settings" << endl;
    cout << "4. Help" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> opt;
    cin>>opt;
    switch (opt){
        case 1:{
            cout<<"Starting the game/n";
        }
        case 2:{
            cout<<"Loading previously loaded game progress/n";
        }
        case 3:{
            cout<<"Settings/n";
        }
        case 4:{
            cout<<"Opening user support/n";
        }
        case 5:{
            cout<<"Exiting the game/n";
        }
        default:{
            cout<<"invalid input/n";
        }
    }    
    return 0;
}
