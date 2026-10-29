#include<iostream>
using namespace std;
void convertTime(int totalSeconds, int& hours, int& minutes, int& seconds);
int main() {
  int total, hours, minutes, seconds; 
  cout << "Enter the total number of seconds: ";
  cin >> total;  
  if (total < 0)                        
  {
    cout << "The seconds can not be negative" << endl;
    return 0;
  }
  convertTime(total, hours, minutes, seconds);
  cout << total << " seconds = " << hours << " h " << minutes << " min " << seconds << " s" << endl;
  return 0;
}
void convertTime(int totalSeconds, int& hours, int& minutes, int& seconds) {
  hours = totalSeconds / 3600;
  minutes = (totalSeconds % 3600) / 60;
  seconds = totalSeconds % 60;
}