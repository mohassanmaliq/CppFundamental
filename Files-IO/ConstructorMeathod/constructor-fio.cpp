#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream out("abc2.txt");
	out << "Hello World" << endl;
	out << "This is a file handling program " << endl;
	out << "This is a C++ program" << endl;
	out << "This is done using constructor meathod" << endl;
	out.close();
	cout << "Data written to the file successfully." << endl;

	ifstream in("abc2.txt");
	string str;
	while (getline(in,str))
	{
		cout << str << endl;
	}
	in.close();
	return 0;
}