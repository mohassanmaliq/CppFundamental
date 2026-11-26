#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int imax = 10;
static int totalPlayer = 0;

void addPlayer(int ids[], string names[], int scores[]);
void displayPlayers(int ids[], string names[], int scores[]);
void linearSearch(int ids[], string names[], int scores[], int key);
void binarySearch(int ids[], string names[], int scores[], int key);
void sortById(int ids[], string names[], int scores[]);
void bubbleSort(int ids[], string names[], int scores[]);
void selectionSort(int ids[], string names[], int scores[]);
void showHighest(int ids[], string names[], int scores[]);
void saveResults(int ids[], string names[], int scores[]);
void loadResults(int ids[], string names[], int scores[]);
void swapPlayers(int ids[], string names[], int scores[], int i, int j);

int main(){
    int id[imax];
    int score[imax];
    string names[imax];
    int choice, key;
    loadResults(id, names, score);

    do{
        cout <<endl<< "1. Enter players"<<endl;
        cout << "2. Display all players"<<endl;
        cout << "3. Linear search by ID"<<endl;
        cout << "4. Binary search by ID"<<endl;
        cout << "5. Bubble sort by score"<<endl;
        cout << "6. Selection sort by score"<<endl;
        cout << "7. Highest scorer"<<endl;
        cout << "8. Save results"<<endl;
        cout << "0. Save and exit"<<endl;
        cout << "Choice: "<<endl;
        cin >> choice;

 switch (choice) {
        case 1:
            addPlayer(id, names, score);
            break;
        case 2:
            displayPlayers(id, names, score);
            break;
        case 3:
            cout << "Enter ID: ";
            cin >> key;
            linearSearch(id, names, score, key);
            break;
        case 4:
            sortById(id, names, score);
            cout << "Enter ID: ";
            cin >> key;
            binarySearch(id, names, score, key);
            break;
        case 5:
            bubbleSort(id, names, score);
            cout << "Sorted."<<endl;
            break;
        case 6:
            selectionSort(id, names, score);
            cout << "Sorted."<<endl;
            break;
        case 7:
            showHighest(id, names, score);
            break;
        case 8:
            saveResults(id, names, score);
            break;
        case 0:
            saveResults(id, names, score);
            break;
        default:
            cout << "Invalid choice."<<endl;
        }
    } while (choice != 0);

    return 0;
}

void swapPlayers(int ids[], string names[], int scores[], int i, int j) {
    int tempId = ids[i];
    ids[i] = ids[j];
    ids[j] = tempId;

    string tempName = names[i];
    names[i] = names[j];
    names[j] = tempName;

    int tempScore = scores[i];
    scores[i] = scores[j];
    scores[j] = tempScore;
}

void addPlayer(int ids[], string names[], int scores[]) {
    if (totalPlayer == imax) {
        cout << "Tournament is full.\n";
        return;
    }
    cout << "ID: ";
    cin >> ids[totalPlayer];
    cout << "Name: ";
    cin >> names[totalPlayer];
    cout << "Score: ";
    cin >> scores[totalPlayer];
    totalPlayer++;
}

void displayPlayers(int ids[], string names[], int scores[]) {
    for (int i = 0; i < totalPlayer; i++)
        cout << ids[i] << " " << names[i] << " " << scores[i] << endl;
    cout << "Total players: " << totalPlayer << endl;
}

void linearSearch(int ids[], string names[], int scores[], int key) {
    for (int i = 0; i < totalPlayer; i++) {
        if (ids[i] == key) {
            cout << names[i] << " has " << scores[i] << " points.\n";
            return;
        }
    }
    cout << "Player not found.\n";
}

void binarySearch(int ids[], string names[], int scores[], int key) {
    int low = 0, high = totalPlayer - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ids[mid] == key) {
            cout << names[mid] << " has " << scores[mid] << " points."<<endl;
            return;
        }
        else if (ids[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Player not found."<<endl;
}

void sortById(int ids[], string names[], int scores[]) {
    for (int i = 0; i < totalPlayer - 1; i++)
        for (int j = 0; j < totalPlayer - i - 1; j++)
            if (ids[j] > ids[j + 1])
                swapPlayers(ids, names, scores, j, j + 1);
}

void bubbleSort(int ids[], string names[], int scores[]) {
    for (int i = 0; i < totalPlayer - 1; i++)
        for (int j = 0; j < totalPlayer - i - 1; j++)
            if (scores[j] < scores[j + 1])
                swapPlayers(ids, names, scores, j, j + 1);
}

void selectionSort(int ids[], string names[], int scores[]) {
    for (int i = 0; i < totalPlayer - 1; i++) {
        int max = i;
        for (int j = i + 1; j < totalPlayer; j++)
            if (scores[j] > scores[max])
                max = j;
        swapPlayers(ids, names, scores, i, max);
    }
}

void showHighest(int ids[], string names[], int scores[]) {
    if (totalPlayer == 0) {
        cout << "No players yet."<<endl;
        return;
    }
    int best = 0;
    for (int i = 1; i < totalPlayer; i++)
        if (scores[i] > scores[best])
            best = i;
    cout << "Highest: " << names[best] << " (ID " << ids[best]
         << ") with " << scores[best] << " points"<<endl;
}

void saveResults(int ids[], string names[], int scores[]) {
    ofstream out("tournament.txt");
    out << totalPlayer << endl;
    for (int i = 0; i < totalPlayer; i++)
        out << ids[i] << " " << names[i] << " " << scores[i] << endl;
    cout << "Results saved."<<endl;
}

void loadResults(int ids[], string names[], int scores[]) {
    ifstream in("tournament.txt");
    if (!in)
        return;
    in >> totalPlayer;
        if (totalPlayer > imax)
        totalPlayer = imax;
    for (int i = 0; i < totalPlayer; i++)
        in >> ids[i] >> names[i] >> scores[i];
    cout << "Previous results loaded."<<endl;
}
