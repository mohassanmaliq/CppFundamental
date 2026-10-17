#include <iostream>
#include <string>
using namespace std;
int main()
{
cout << "BSCGD Batch 2026 is live!!!! \n hello There \n PF lab 01"<<endl;
cout << "......................................................." << endl;
string a = "ABC";
int age = 18;
cout << "Name= " << a << endl
<< "age=" << age << endl;
 int age1;
cin >> age1;
cout << "Your age is: " << age1 << endl;
cout << "......................................................." << endl;
int num1, num2, sum;
cout << " Enter Number 1 : "<< endl; cin >> num1;
cout << "Enter Number 2 : "<<endl;
cin >> num2;
sum = num1 + num2;
cout << "The value of sum is " << sum<< endl;
cout << "......................................................." << endl;
int revenue;
int cost, profit;
 cout << "\nEnter total revenue: " << endl;
cin >> revenue;
 cout << "\nEnter total cost: " << endl;
cin >> cost;
 profit = revenue - cost;
cout << "\nYour profit is " << profit<< endl;
cout << "......................................................." << endl;
cout << "Welocme to the Class " << "\n";
cout << "Good luck"<< endl;
cout << "......................................................." << endl;
int short_int = 500;
int illegal_short_int = 35000;
char legal_char = 'M';
char illegal_char = 2;
bool legal_bool = false;
bool illegal_bool = 2;
string documentaryTitle = "Racing Extinction"; float distance = 3.1;
double mass = 33.22;
cout << "......................................................." << endl;
cout << "Legal short integer is:" << short_int<< endl;
cout << "Illegal short integer is:" << illegal_short_int << endl;
cout << "Legal character is:" << legal_char << endl;
cout << "Illegal character is:" << illegal_char << endl;
cout << "Legal boolean is:" << legal_bool << endl;
cout << "Illegal boolean is:" << illegal_bool << endl;
cout << "......................................................." << endl;
cout << "$$$$$$PRACTICE EXAMPLE NUMBER 02$$$$$$" << endl;
int y; 
cout << "Enter value of y: ";
cin >> y;
 int result = 4 * y * (3 - 2) * y + 7;
 cout << "Result = " << result;
cout << "......................................................." << endl;
cout << "$$$$$$PRACTICE EXAMPLE NUMBER 03$$$$$" << endl;
int num = 321;
 cout << num / 10 << endl;
cout << num % 10 << endl;
num = num / 10;
cout << num / 10 << endl;
cout << num % 10 << endl; cout << "......................................................." << endl;
cout << "$$$$$$PRACTICE EXAMPLE NUMBER 04$$$$$$" << endl;
const double PI = 3.14159;
double area, radius;
 cout << "This program calculates the area of a circle." << endl;
cout << "What is the radius of the circle? " << endl;
cin >> radius;
area = PI * pow(radius, 2.0);
cout << "The area is " << area << endl;
cout << "......................................................." << endl;
cout << "......................................................." << endl;
cout << "Practice of Combined assingment operater" << endl;
int appleCount = 10, totalScore = 20, itemPrice = 5, accountBalance = 40, 
remainingDays = 15;
 cout << "--- Compound Assignment Operators ---" << endl;
cout << "appleCount = " << appleCount << endl;
appleCount += 5; 
cout << "After appleCount += 5 : " << appleCount << endl;
 cout << "totalScore = " << totalScore << endl;
totalScore -= 2; 
cout << "After totalScore -= 2 : " << totalScore << endl;
 cout << "itemPrice = " << itemPrice << endl;
itemPrice *= 10; 
cout << "After itemPrice *= 10: " << itemPrice << endl;
 cout << "accountBalance = " << accountBalance << endl; accountBalance /= 8; 
cout << "After accountBalance /= 8 : " << accountBalance << endl;
 cout << "remainingDays = " << remainingDays << endl;
remainingDays %= 4; 
cout << "After remainingDays %= 4 : " << remainingDays << endl;
cout << "......................................................." << endl;
cout << "......................................................." << endl;
int numdd = 5;
cout << "\n--- Increment / Decrement Operators ----" << endl;
cout << "Initial num = " << numdd << endl;
 int postInc = numdd++; 
cout << "postInc = num++ -> postInc: " << postInc << ", num: " << 
numdd << endl;
 int preInc = ++numdd; 
cout << "preInc = ++num -> preInc: " << preInc << ", num: " << numdd << 
endl;
 int postDec = numdd--;
cout << "postDec = num-- -> postDec: " << postDec << ", num: " << 
numdd << endl;
 int preDec = --numdd; 
cout << "preDec = --num -> preDec: " << preDec << ", num: " << numdd 
<< endl;
cout << "......................................................." << endl;
cout << "......................................................." << endl;
return 0;
}