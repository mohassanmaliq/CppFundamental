/*
==================== GAME LEADERBOARD MANAGER ====================

WHAT THE PROGRAM IS ABOUT
A game has up to 20 players. Each player has an ID and a score.
They are stored in two parallel arrays: id[i] is the player whose
score is score[i]. The program shows a menu and lets the user
search and sort these scores using different algorithms, then
compares how much work each technique does.

INPUT
Read n (number of players, n <= 20), then the ID and score of each
player. (Your code currently uses hardcoded arrays instead.)

KEY IDEA
The ORIGINAL arrays must never be changed. Every sort works on a
COPY, so the original stays unsorted for the linear search.
Whenever two scores swap or shift, their IDs must move with them
so each ID stays attached to its own score.

------------------------------------------------------------------
OPTION 1: LINEAR SEARCH
- Look through the original (unsorted) scores one by one for a
  score the user enters.
- Show the IDs of ALL players with that score (not just the first),
  the number of matches and the number of comparisons.
- If nobody has that score, show a proper message.

OPTION 2: BUBBLE SORT (LEADERBOARD)
- Sort a copy in DESCENDING order (highest score first).
- Swap the IDs along with the scores.
- Use a swapped flag so the sort stops early if a pass makes no
  swaps. The inner loop runs only up to n - 1 - pass.
- Show the array after every pass, then the total comparisons,
  swaps and passes.
- Show the final leaderboard as Rank, ID, Score.

OPTION 3: INSERTION SORT
- Sort another copy in ASCENDING order.
- Show the key being inserted and the array after each iteration.
- Count the total number of shifts.

OPTION 4: BINARY SEARCH
- First check that the ascending array is sorted. If Option 3 has
  not been run, print "Scores are not sorted. Run Option 3 first."
  and return to the menu.
- Search the ascending array and print low, high and mid at every
  step, plus the number of comparisons.
- If the score is not found, show the index where it should be
  inserted to keep the array sorted (the final value of low).

OPTION 5: COMPARE TECHNIQUES
- Ask for a score. Search it with linear search (stop at the first
  match) on the original array, and with binary search on the
  sorted array. Show both comparison counts side by side.
- Show the swaps made by bubble sort and the shifts made by
  insertion sort.
- Answer these three questions, in your own words, as comments:
    1. Why did binary search need fewer comparisons?
    2. Why can binary search not be used on the original array?
    3. Which sort does less work on an already sorted array, and why?

OPTION 6: EXIT
- End the program.
==================================================================
*/
#include<iostream>
using namespace std;
int main() {
	int opt;
	int id[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int score[] = { 56,67,69,87,45,87,87,90,65,34,34,68,89,74,25,52,11 ,34,45,32 };
	//int cid[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	//int cscore[] = { 56,67,69,87,45,87,87,90,65,34,34,68,89,74,25,52,11 ,34,45,32 };
	int n = sizeof(id) / sizeof(id[0]);
	do {
		cout << "---------MENU---------" << endl;
		cout << "Enter the option you want" << endl;
		cout << "1. Search a score" << endl;
		cout << "2. Show leaderboard" << endl;
		cout << "3. Sort scores in ascending order" << endl;
		cout << "4. Search a score" << endl;
		cout << "5. Compare techniques" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> opt;
		switch (opt) {
		case 1:{
			int pid ,indexno;
			cout << "Enter the player ID :";
			cin >> pid;
			for (int i = 0; i < 20; i++) {
				if (pid == id[i]) {
					cout << "Player ID found" << endl;
					indexno = i;
				}
			}
			if (pid == id[indexno])
				cout << "The value of player " << pid << " is " << score[indexno] << endl;
			else
				cout << "Player not found , Try again!" << endl;
			break;
		}
		case 2:
		{
            int cid[20];
			int cscore[20];
			for(int i=0;i<20;i++){
				cid[i] = id[i];
				cscore[i] = score[i];
			}
			int passes =0, comparisons = 0, swaps = 0;
			for (int i=0; i <n; i++){
				bool swapped = false;
				passes++;
				for(int j=0; j<n-1-i;j++){
					comparisons++;
					if(cscore[j] < cscore[j+1]){
						int temp = cscore[j];
						cscore[j]=cscore[j+1];
						cscore[j+1]=temp;
						temp = cid[j];
						cid[j]=cid[j+1];
						cid[j+1]=temp;
						swaps++;
						swapped=true;
				}
			}
			cout<<"After Pass "<<passes<<": ";
			for(int k=0;k<n;k++){
				cout<<cscore[k]<<" ";
			}
			cout<<endl;	
		}
		cout << endl << "Total passes: " << passes << endl;
			cout << "Total comparisons: " << comparisons << endl;
			cout << "Total swaps: " << swaps << endl << endl;
			cout << "Rank\tID\tScore" << endl;
			for (int k = 0; k < n; k++)
				cout << k + 1 << "\t" << cid[k] << "\t" << cscore[k] << endl;
		break;
	}
		case 3:{
				int ascore[20];
				int aid[20];
				for (int i = 0; i < n; i++) {
				aid[i] = id[i];
				ascore[i] = score[i];
			}
			
			break;
		}
		case 4:{
			break;
		}
		case 5: {
			break;
		}
		case 6:{
			cout << "Exiting the program" << endl;
			break;
		}
		default:{
			cout << "wrong option entered" << endl;
		}}
	} while (!(opt == 6));

	return 0;
}