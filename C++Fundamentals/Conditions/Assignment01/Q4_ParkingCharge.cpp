#include <iostream>
using namespace std;

int main()
{
    int vehicle, rate, hours, charge;
    char weekend, vip;

    cout << "--------------------" << endl;
    cout << "1 Motorcycle Rs 50 per hour" << endl;
    cout << "2 Car Rs 100 per hour" << endl;
    cout << "3 SUV Rs 150 per hour" << endl;
    cout << "4 Truck Rs 250 per hour" << endl;
    cout << "--------------------" << endl;
    cout << "Choose a vehicle ->" << endl;
    cin >> vehicle;

    if (vehicle == 1)
        rate = 50;
    else if (vehicle == 2)
        rate = 100;
    else if (vehicle == 3)
        rate = 150;
    else if (vehicle == 4)
        rate = 250;
    else
    {
        cout << "Wrong option entered" << endl;
        cout << "Run the application again!" << endl;
        return 0;
    }

    cout << "Enter number of hours:" << endl;
    cin >> hours;
    cout << "Is it a weekend? (Y/N)" << endl;
    cin >> weekend;
    cout << "Is the customer VIP? (Y/N)" << endl;
    cin >> vip;

    charge = rate * hours;
    if (weekend == 'Y')
        charge = charge + charge * 20 / 100;
    if (vip == 'Y')
        charge = charge - charge * 30 / 100;
    if (hours > 8)
        charge = charge + 500;

    cout << "Total parking charge: Rs " << charge << endl;
    return 0;
}
