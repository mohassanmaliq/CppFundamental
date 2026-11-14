#include <iostream>
using namespace std;
int main() {

//-----------------Task 1

    int map[5][5];
    cout << "Enter value (1 to 50) for the 5x5 map:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Cell [" << i << "][" << j << "]: ";
            cin >> map[i][j];
        }
    }
    int map2[5][5] = {
        {5, 15, 20, 10, 30},
        {12, 8, 25, 40, 6},
        {33, 4, 17, 22, 9},
        {18, 29, 2, 35, 11},
        {44, 13, 7, 26, 19}
    };

    int choice;
    int score = 0;

//-----------------Task 5

    do {
        cout << endl << "----- MAP ----" << endl;
        cout << "1. Display Map" << endl;
        cout << "2. Totals" << endl;
        cout << "3. Largest value and Diagonal" << endl;
        cout << "4. Add 2 Maps" << endl;
        cout << "5. Search a value" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Task 1
            cout << endl << "Map:" << endl;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cout << map[i][j] << "\t";
                }
                cout << endl;
            }
            score = score + 5;
        }

        else if (choice == 2) {
            // Task 2
            int totalTreasure = 0;
            int rowsum[5] = {0, 0, 0, 0, 0};
            int rowcol[5] = {0, 0, 0, 0, 0};
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    totalTreasure += map[i][j];
                    rowsum[i] = rowsum[i] + map[i][j];
                    rowcol[j] = rowcol[j] + map[i][j];
                }
            }
            cout << endl << "Total of all cells: " << totalTreasure << endl;
            cout << "Row sums: " << endl;
            for (int i = 0; i < 5; i++) {
                cout << rowsum[i] << " - ";
            }
            cout << endl << "Column sums: " << endl;
            for (int i = 0; i < 5; i++) {
                cout << rowcol[i] << " - ";
            }
            cout << endl;
            score = score + 10;
        }

        else if (choice == 3) {
            // Task 3
            int maxval = map[0][0];
            int maxrow = 0, maxcol = 0;
            int diagonalSum = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (map[i][j] > maxval) {
                        maxval = map[i][j];
                        maxrow = i;
                        maxcol = j;
                    }
                }
            }
            cout << endl << "Maximum value: " << maxval << " at position [" << maxrow << "][" << maxcol << "]" << endl;
            for (int i = 0; i < 5; i++) {
                diagonalSum += map[i][i];
            }
            cout << "Sum of diagonal elements: " << diagonalSum << endl;
            score = score + 10;
        }

        else if (choice == 4) {
            // Task 4
            int combinedMap[5][5];
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    combinedMap[i][j] = map[i][j] + map2[i][j];
                }
            }
            cout << endl << "Combined Map:" << endl;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cout << combinedMap[i][j] << " - ";
                }
                cout << endl;
            }
            score = score + 15;
        }

        else if (choice == 5) {
            // Task 5
            int target;
            int count = 0;
            cout << endl << "Enter target number to search: ";
            cin >> target;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (map[i][j] == target) {
                        cout << "Found at Row " << i << ", Column " << j << endl;
                        count = count + 1;
                    }
                }
            }
            if (count > 0) {
                cout << "Target found! Bonus +20" << endl;
                score = score + 20;
            } else {
                cout << "Not found" << endl;
                score = score + 5;
            }
        }

        else if (choice != 0) {
            cout << "Invalid choice! Enter 0 to 5." << endl;
        }

    } while (choice != 0);

    cout << endl << "Final Score: " << score << endl;
    return 0;
}