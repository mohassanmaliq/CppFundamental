// Q3 (25 marks)
// There are 2 seating halls (1-2) at a Rawalpindi stadium with 2 classes (A and B) each.
// Class A seats cost 1500 and Class B seats cost 1200. There are conditions of getting
// a discount in each hall according to the number of tickets to be purchased.
// For example:
//             5 or more tickets
// Hall-1      8%
// Hall-2      10%
// Apply (if-else, if else-if or switch) to solve this problem by asking the user
// ticket class (A or B), no. of tickets, and Hall-no. Display the discount and total
// cost after discount. Your program should not run if the user entered an invalid entry.
// Input: Hall=1, NumberOfTickets >=5, class=A
// Output: (1500*NaumberOfTickets)*0.08

#include<cctype>
#include<iostream>
using namespace std;
int main(){
    int hall, tickets, price=0;
    char seatClass;
    double rate=0, total, discount;
    cout<<"Enter hall number (1 or 2): "<<endl;
    cin>>hall;
    cout<<"Enter ticket class (A or B): "<<endl;
    cin>>seatClass;
    cout<<"Enter number of tickets: "<<endl;
    cin>>tickets;
    seatClass=toupper(seatClass);
    if(tickets<=0){
        cout<<"Wrong number of tickets entered, exiting the program"<<endl;
        return 0;
    }
    switch(seatClass){
        case 'A':{
            price=1500;
            break;
        }
        case 'B':{
            price=1200;
            break;
        }
        default:{
            cout<<"Wrong class entered, exiting the program"<<endl;
            return 0;
        }
    }
    switch(hall){
        case 1:{
            rate=0.08;
            break;
        }
        case 2:{
            rate=0.10;
            break;
        }
        default:{
            cout<<"Wrong hall entered, exiting the program"<<endl;
            return 0;
        }
    }
    if(tickets<5){
        rate=0;
    }
    total=price*tickets;
    discount=total*rate;
    cout<<"Discount: "<<discount<<endl;
    cout<<"Total cost after discount: "<<total-discount<<endl;
    return 0;
}