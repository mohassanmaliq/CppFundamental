/*
  File I/O functions

  g is for get (read), p is for put (write)

  seekg(offset, from)   moves the read position
  seekp(offset, from)   moves the write position
      offset            how many bytes to move
      from              where to count from (ios::beg, ios::cur, ios::end)

  tellg()               returns the current read position
  tellp()               returns the current write position

  ios::in               open for reading
  ios::out              open for writing
  ios::app              add to the end of the file

  File location in the stream statement:
  ifstream f("E:\\folder\\a.txt");
  write \\ for each \ or use /

  !f                    true when the stream failed, i.e. the file cannot be opened
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream f("E:\\VisualStudioCode\\C++Fundamental\\fs.txt", ios::in | ios::out | ios::trunc);
    if (!f) {
        cout << "Can not open the file" << endl;
        return 1;
    }

    f << "ABCDEFGHI";
    cout << "tellp: " << f.tellp() << endl;

    f.seekg(0);
    char c;
    f.get(c);
    cout << c << endl;
    cout << "tellg: " << f.tellg() << endl;

    f.seekp(2);
    f << "xyz";

    f.seekg(0);
    string s;
    getline(f, s);
    cout << s << endl;

    f.close();
    return 0;
}