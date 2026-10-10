#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	//handling file using member functions meathods
	ofstream out;
	out.open("abc.txt");
	out << "Hello World" << endl;
	out << "This is a file handling program " << endl;
	out << "This is a C++ program" << endl;
	out << "This is done using member functions" << endl;
	out.close();

	ifstream in;
	in.open("abc.txt");
	string str;
	while (in.eof() == 0)
	{ 
		getline(in, str);
		cout << str << endl;
	}
	in.close();
	return 0;
}