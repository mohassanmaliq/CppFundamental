#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int weather, health;
    char jacket, umbrella, flashlight;

    cout << "1 Sunny" << endl;
    cout << "2 Rainy" << endl;
    cout << "3 Storm" << endl;
    cout << "4 Snow" << endl;
    cout << "Enter weather:" << endl;
    cin >> weather;
    cout << "Did you bring a jacket? (Y/N)" << endl;
    cin >> jacket;
    cout << "Did you bring an umbrella? (Y/N)" << endl;
    cin >> umbrella;
    cout << "Did you bring a flashlight? (Y/N)" << endl;
    cin >> flashlight;

    srand(100);
    health = rand() % 100;
    cout << "Health: " << health << endl;

    if (health < 30)
        cout << "Health too low. Return to camp." << endl;
    else if (weather == 1)
        cout << "Can continue." << endl;
    else if (weather == 2 && umbrella == 'Y')
        cout << "Can continue." << endl;
    else if (weather == 2)
        cout << "Risky." << endl;
    else if (weather == 3 && flashlight == 'Y')
        cout << "Wait for storm." << endl;
    else if (weather == 3)
        cout << "Return to camp." << endl;
    else if (weather == 4 && jacket == 'Y')
        cout << "Can continue." << endl;
    else
        cout << "Return to camp." << endl;

    return 0;
}
