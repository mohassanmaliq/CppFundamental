#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	string st;
	ifstream hell;
	hell.open("myinfo.txt");
	while (!hell.eof())
	{
		
		getline(hell,st);
		cout <<st<< endl;
	}
	hell.close();
	return 0;
}