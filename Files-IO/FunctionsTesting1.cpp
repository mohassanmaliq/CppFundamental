#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("test.txt");
    if (!out.is_open()) {
        cout << "cannot open for writing" << endl;
        return 1;
    }
    out << "Hello World\n";
    out << "Second line\n";
    out << "42 3.14\n";
    cout << "tellp after writing: " << out.tellp() << endl;
    out.seekp(0);
    out << "J";
    cout << "tellp after seekp(0) and one write: " << out.tellp() << endl;
    out.close();

    ifstream in("test.txt");
    if (!in.is_open()) {
        cout << "cannot open for reading" << endl;
        return 1;
    }

    string line;
    getline(in, line);
    cout << "line 1: " << line << endl;
    cout << "tellg: " << in.tellg() << endl;

    getline(in, line);
    cout << "line 2: " << line << endl;

    int n;
    double d;
    in >> n >> d;
    cout << "n: " << n << ", d: " << d << endl;
    cout << "good: " << in.good() << " eof: " << in.eof()
         << " fail: " << in.fail() << " bad: " << in.bad() << endl;

    in.seekg(0);
    cout << "after seekg(0), tellg: " << in.tellg() << endl;

    int count = 0;
    while (getline(in, line)) {
        count++;
    }
    cout << "lines read: " << count << endl;
    cout << "good: " << in.good() << " eof: " << in.eof()
         << " fail: " << in.fail() << " bad: " << in.bad() << endl;

    in.clear();
    in.seekg(0, ios::end);
    cout << "file size: " << in.tellg() << endl;
    in.close();

    ifstream missing("nofile.txt");
    cout << "missing is_open: " << missing.is_open()
         << ", fail: " << missing.fail() << endl;

    return 0;
}