#include <iostream>
using namespace std;
int main(){
    int health = 100;
    float speed = 2.5;
    char grade = 'A';
    int *hPtr = &health;
    float *sPtr = &speed;
    char *gPtr = &grade;
    cout << "health : value = " << health << "  address = " << &health << "  hPtr = " << hPtr << "  *hPtr = " << *hPtr << endl;
    cout << "speed  : value = " << speed << "  address = " << &speed << "  sPtr = " << sPtr << "  *sPtr = " << *sPtr << endl;
    cout << "grade  : value = " << grade << "    address = " << (void*)&grade << "  gPtr = " << (void*)gPtr << "  *gPtr = " << *gPtr << endl;
    cout << "Enter new health: ";
    cin >> *hPtr;
    cout << "health is now " << health << endl;
    return 0;
}