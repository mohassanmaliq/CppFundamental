#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	int rollno;
	string name, city;
	cout << "Enter your name: " << endl;
	cin >> name;
	cout <<endl<< "Enter your roll number: " << endl;
	cin >> rollno;
	cout <<endl<< "Enter your city: " << endl;
	cin >> city;
	ofstream file;
	file.open("myinfo.txt");
	file << "Your name is " << name << endl;
	file << "Your roll number is " << rollno << endl;
	file << "Your city of residence is " << city << endl;
	file.close();
	cout << "Your data is saved in to the file and the file is sucessfully closed" << endl;
	return 0;
}