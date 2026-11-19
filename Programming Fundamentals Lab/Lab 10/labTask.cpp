#include<iostream>
using namespace std;
int main() {
	int opt;
	int id[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int score[] = { 56,67,69,87,45,87,87,90,65,34,34,68,89,74,25,52,11 ,34,45,32 };
	int cid[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int cscore[] = { 56,67,69,87,45,87,87,90,65,34,34,68,89,74,25,52,11 ,34,45,32 };
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
			int passes = 0, comparisons = 0, swaps = 0;
			for (int i = 0; i < n - 1; i++)
			{
				bool swapped = false;
				passes++;
				for (int j = 0; j < n - 1 - i; j++)
				{
					comparisons++;
					if (cscore[j] < cscore[j + 1])
					{
						int temp = cscore[j];
						cscore[j] = cscore[j + 1];
						cscore[j + 1] = temp;
						int tempId = cid[j];
						cid[j] = cid[j + 1];
						cid[j + 1] = tempId;
						swaps++;
						swapped = true;
					}
				}
				cout << "After pass " << passes << ": ";
				for (int k = 0; k < n; k++)
					cout << cscore[k] << " ";
				cout << endl;
				if (!swapped)
					break;
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
		default:
			cout << "wrong option entered" << endl;

		}
	} while (!(opt == 6));

	return 0;
}