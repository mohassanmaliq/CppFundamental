#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;
const int ZOMBIES = 8;

char arena[SIZE][SIZE];
bool visited[SIZE][SIZE];
int pr, pc;                    // player row, column
int health = 100;
int zr[ZOMBIES], zc[ZOMBIES];  // zombie rows, columns
bool alive[ZOMBIES];
int killed = 0;
int lastRow, lastCol;          // where placeItem() put the last item

void setup();
void placeItem(char symbol);
void show();
bool movePlayer(char dir);
void attack();
void moveZombies();
int countZombies(int i);
bool pathExists(int r, int c, int tr, int tc);
void saveResult(bool survived, int score);

int main()
{
    srand(time(0));
    setup();

    cout << "P=You Z=Zombie #=Obstacle H=Health pack\n";
    cout << "w/a/s/d = move, f = attack, c = check path\n";

    while (health > 0 && countZombies(0) > 0)
    {
        show();
        cout << "Health: " << health << "  Zombies left: " << countZombies(0) << "\n";
        cout << "Move: ";
        char cmd;
        cin >> cmd;

        if (cmd == 'c')
        {
            int tr, tc;
            cout << "Target row and column: ";
            cin >> tr >> tc;
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    visited[i][j] = false;
            if (pathExists(pr, pc, tr, tc))
                cout << "Path exists\n";
            else
                cout << "No path\n";
            continue;
        }
        else if (cmd == 'f')
            attack();
        else if (cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd')
        {
            if (!movePlayer(cmd))
            {
                cout << "Blocked!\n";
                continue;
            }
        }
        else
            continue;

        moveZombies();
    }

    show();
    bool survived = (health > 0);
    int score = killed * 10 + health;
    if (survived)
        cout << "You survived!\n";
    else
        cout << "Game over!\n";
    cout << "Score: " << score << "\n";
    saveResult(survived, score);
    return 0;
}

void setup()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            arena[i][j] = '.';

    placeItem('P');
    pr = lastRow;
    pc = lastCol;

    for (int i = 0; i < ZOMBIES; i++)
    {
        placeItem('Z');
        zr[i] = lastRow;
        zc[i] = lastCol;
        alive[i] = true;
    }
    for (int i = 0; i < 10; i++)
        placeItem('#');
    for (int i = 0; i < 5; i++)
        placeItem('H');
}

// puts the symbol on a random empty cell
void placeItem(char symbol)
{
    do
    {
        lastRow = rand() % SIZE;
        lastCol = rand() % SIZE;
    } while (arena[lastRow][lastCol] != '.');
    arena[lastRow][lastCol] = symbol;
}

void show()
{
    cout << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arena[i][j] << " ";
        cout << "\n";
    }
}

bool movePlayer(char dir)
{
    int nr = pr, nc = pc;
    if (dir == 'w') nr--;
    if (dir == 's') nr++;
    if (dir == 'a') nc--;
    if (dir == 'd') nc++;

    if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE)
        return false;
    if (arena[nr][nc] == '#' || arena[nr][nc] == 'Z')
        return false;

    if (arena[nr][nc] == 'H')
    {
        health += 10;
        cout << "Health pack! +10\n";
    }
    arena[pr][pc] = '.';
    pr = nr;
    pc = nc;
    arena[pr][pc] = 'P';
    return true;
}

// kills zombies standing right next to the player
void attack()
{
    for (int i = 0; i < ZOMBIES; i++)
    {
        int distance = abs(zr[i] - pr) + abs(zc[i] - pc);
        if (alive[i] && distance == 1)
        {
            alive[i] = false;
            arena[zr[i]][zc[i]] = '.';
            killed++;
        }
    }
}

void moveZombies()
{
    for (int i = 0; i < ZOMBIES; i++)
    {
        if (!alive[i])
            continue;

        int r = zr[i], c = zc[i];
        int nr = r, nc = c;

        // try to step toward the player's row first
        if (r < pr) nr++;
        else if (r > pr) nr--;

        // if that is blocked (or already in the same row), step along the column
        if (arena[nr][nc] == '#' || arena[nr][nc] == 'Z' || arena[nr][nc] == 'H')
        {
            nr = r;
            if (c < pc) nc++;
            else if (c > pc) nc--;
        }

        if (arena[nr][nc] == 'P')
        {
            health -= 20;
            if (health < 0) health = 0;
            alive[i] = false;          // zombie is used up after hitting
            arena[r][c] = '.';
            cout << "A zombie hit you! -20\n";
        }
        else if (arena[nr][nc] == '.')
        {
            arena[r][c] = '.';
            arena[nr][nc] = 'Z';
            zr[i] = nr;
            zc[i] = nc;
        }
    }
}

// recursive: counts alive zombies from index i onward
int countZombies(int i)
{
    if (i == ZOMBIES)
        return 0;
    if (alive[i])
        return 1 + countZombies(i + 1);
    return countZombies(i + 1);
}

// recursive: is there a path that avoids obstacles?
bool pathExists(int r, int c, int tr, int tc)
{
    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE)
        return false;
    if (arena[r][c] == '#' || visited[r][c])
        return false;
    if (r == tr && c == tc)
        return true;

    visited[r][c] = true;
    return pathExists(r - 1, c, tr, tc) || pathExists(r + 1, c, tr, tc) ||
           pathExists(r, c - 1, tr, tc) || pathExists(r, c + 1, tr, tc);
}

void saveResult(bool survived, int score)
{
    ofstream file("result.txt");
    file << "Score: " << score << "\n";
    file << "Status: " << (survived ? "Survived" : "Dead") << "\n";
    file.close();
    cout << "Saved to result.txt\n";
}