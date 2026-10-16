#include <iostream>
using namespace std;

int main()
{
    int item, price, quantity, total, percent, discount, tax, finalTotal;

    cout << "--------------------" << endl;
    cout << "1 Burger Rs 500" << endl;
    cout << "2 Pizza Rs 1200" << endl;
    cout << "3 Pasta Rs 800" << endl;
    cout << "4 Sandwich Rs 400" << endl;
    cout << "5 Drink Rs 150" << endl;
    cout << "--------------------" << endl;
    cout << "Choose an item ->" << endl;
    cin >> item;

    if (item == 1)
        price = 500;
    else if (item == 2)
        price = 1200;
    else if (item == 3)
        price = 800;
    else if (item == 4)
        price = 400;
    else if (item == 5)
        price = 150;
    else
    {
        cout << "Wrong option entered" << endl;
        cout << "Run the application again!" << endl;
        return 0;
    }

    cout << "Enter quantity:" << endl;
    cin >> quantity;
    total = price * quantity;

    if (total >= 5000)
        percent = 15;
    else if (total >= 3000)
        percent = 10;
    else if (total >= 2000)
        percent = 5;
    else
        percent = 0;

    discount = total * percent / 100;
    tax = (total - discount) * 8 / 100;
    finalTotal = total - discount + tax;

    cout << "--------------------" << endl;
    if (item == 1)
        cout << "Burger";
    else if (item == 2)
        cout << "Pizza";
    else if (item == 3)
        cout << "Pasta";
    else if (item == 4)
        cout << "Sandwich";
    else
        cout << "Drink";
    cout << " x " << quantity << "  Rs: " << total << endl;

    if (item == 2 && quantity >= 2)
        cout << "Free Drink  Rs: 0" << endl;

    cout << "--------------------" << endl;
    cout << "Discount  Rs: " << discount << endl;
    cout << "Tax  Rs: " << tax << endl;
    cout << "--------------------" << endl;
    cout << "Final total  Rs: " << finalTotal << endl;
    cout << "--------------------" << endl;
    return 0;
}
