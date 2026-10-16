#include <iostream>
using namespace std;

int main()
{
    int category, price, quantity, membership;
    int total, percent, discount, delivery, finalBill;

    cout << "1 Electronics" << endl;
    cout << "2 Clothing" << endl;
    cout << "3 Books" << endl;
    cout << "4 Grocery" << endl;
    cout << "Enter category:" << endl;
    cin >> category;

    if (category < 1 || category > 4)
    {
        cout << "Wrong option entered" << endl;
        cout << "Run the Program again" << endl;
        return 0;
    }

    cout << "Enter product price:" << endl;
    cin >> price;
    cout << "Enter quantity:" << endl;
    cin >> quantity;
    cout << "Enter membership (1 Regular, 2 Silver, 3 Gold):" << endl;
    cin >> membership;

    if (membership == 1)
        percent = 0;
    else if (membership == 2)
        percent = 5;
    else if (membership == 3)
        percent = 10;
    else
    {
        cout << "Wrong membership entered" << endl;
        cout << "Run the Program again" << endl;
        return 0;
    }

    total = price * quantity;
    if (category == 1 && total > 50000)
        percent = percent + 5;

    discount = total * percent / 100;
    if (category == 4 && total > 10000)
        delivery = 0;
    else if (total < 5000)
        delivery = 300;
    else
        delivery = 0;

    finalBill = total + delivery - discount;
    cout << "Total: Rs " << total << endl;
    cout << "Discount: Rs " << discount << endl;
    cout << "Delivery: Rs " << delivery << endl;
    cout << "Final bill: Rs " << finalBill << endl;
    return 0;
}
