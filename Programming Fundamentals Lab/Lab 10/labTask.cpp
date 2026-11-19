#include<iostream>
using namespace std;
int main() {
	int opt;
	int id[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int score[] = { 56,67,69,87,45,87,87,90,65,34,34,68,89,74,25,52,11 ,34,45,32 };
	int cid[20];     // copy for descending (bubble sort)
	int cscore[20];
	int aid[20];     // copy for ascending (insertion sort)
	int ascore[20];
	int n = sizeof(id) / sizeof(id[0]);
	bool ascSorted = false;   // becomes true once Option 3 has been run

	do {
		cout << "---------MENU---------" << endl;
		cout << "Enter the option you want" << endl;
		cout << "1. Search a score (Linear Search)" << endl;
		cout << "2. Show leaderboard (Bubble Sort - descending)" << endl;
		cout << "3. Sort scores in ascending order (Insertion Sort)" << endl;
		cout << "4. Search a score (Binary Search)" << endl;
		cout << "5. Compare techniques" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> opt;
		switch (opt) {
		case 1: {
			int target, comparisons = 0, matches = 0;
			cout << "Enter the score to search : ";
			cin >> target;
			cout << "Players with score " << target << ": ";
			for (int i = 0; i < n; i++) {
				comparisons++;
				if (score[i] == target) {
					cout << "ID " << id[i] << "  ";
					matches++;
				}
			}
			cout << endl;
			if (matches == 0)
				cout << "No player has the score " << target << "." << endl;
			cout << "Number of matches: " << matches << endl;
			cout << "Number of comparisons: " << comparisons << endl;
			break;
		}
		case 2:
		{
			// fresh copy of the original every time
			for (int i = 0; i < n; i++) {
				cid[i] = id[i];
				cscore[i] = score[i];
			}
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
		case 3: {
			// fresh copy of the original every time
			for (int i = 0; i < n; i++) {
				aid[i] = id[i];
				ascore[i] = score[i];
			}
			int shifts = 0;
			for (int i = 1; i < n; i++) {
				int key = ascore[i];
				int keyId = aid[i];
				int j = i - 1;
				while (j >= 0 && ascore[j] > key) {
					ascore[j + 1] = ascore[j];
					aid[j + 1] = aid[j];
					shifts++;
					j--;
				}
				ascore[j + 1] = key;
				aid[j + 1] = keyId;

				cout << "Key = " << key << " | Array: ";
				for (int k = 0; k < n; k++)
					cout << ascore[k] << " ";
				cout << endl;
			}
			ascSorted = true;
			cout << endl << "Total shifts: " << shifts << endl;
			cout << "Ascending order (ID : Score):" << endl;
			for (int k = 0; k < n; k++)
				cout << aid[k] << " : " << ascore[k] << endl;
			break;
		}
		case 4: {
			if (!ascSorted) {
				cout << "Scores are not sorted. Run Option 3 first." << endl;
				break;
			}
			int target, low = 0, high = n - 1, comparisons = 0;
			bool found = false;
			cout << "Enter the score to search : ";
			cin >> target;
			while (low <= high) {
				int mid = (low + high) / 2;
				comparisons++;
				cout << "low = " << low << ", high = " << high << ", mid = " << mid << endl;
				if (ascore[mid] == target) {
					found = true;
					cout << "Score " << target << " found at index " << mid << endl;
					// duplicates sit next to each other in a sorted array
					cout << "Player ID(s) with this score: ";
					int l = mid, r = mid;
					while (l > 0 && ascore[l - 1] == target) l--;
					while (r < n - 1 && ascore[r + 1] == target) r++;
					for (int k = l; k <= r; k++)
						cout << aid[k] << " ";
					cout << endl;
					break;
				}
				else if (ascore[mid] < target)
					low = mid + 1;
				else
					high = mid - 1;
			}
			if (!found) {
				cout << "Score " << target << " not found." << endl;
				cout << "It should be inserted at index " << low << " to keep the array sorted." << endl;
			}
			cout << "Number of comparisons: " << comparisons << endl;
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			cout << "Exiting the program" << endl;
			break;
		}
		default:
			cout << "wrong option entered" << endl;

		}
	} while (!(opt == 6));

	return 0;
}