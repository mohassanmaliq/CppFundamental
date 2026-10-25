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
    int hall, tickets, price;
    char seatClass;
    cout<<"Enter Hall class (A or B): "<<endl;
    cin>>seatClass;
    cout<<"Enter number of tickets: "<<endl;
    cin>>tickets;
    seatClass=toupper(seatClass);
    switch(seatClass){
        case 'A':{
            cout<<"Hall A selected "<<endl;
            break;
        }
        case 'B':{
            cout<<"Hall B selected "<<endl;
            break;
        }
        default:{
            cout<<"Wrong command entered, exiting the program"<<endl;
            break;
        }
    }
    return 0;
}