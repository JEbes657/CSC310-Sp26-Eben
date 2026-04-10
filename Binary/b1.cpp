#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    fstream ftxt, fbin;

    unsigned short num = 310;

    ftxt.open("b1.txt", ios::out);
    fbin.open("binary.dat", ios::out | ios::binary);

    // write to file
    if (ftxt)
    {
        ftxt << num;
        ftxt.close();
    }
    else
    {
        cout << "Error opening text file!" << endl;
    }

    if (fbin)
    {
        fbin.write(reinterpret_cast<char*>(&num), sizeof(num));
        fbin.close();
    }
    else
    {
        cout << "Error opening binary file!" << endl;
    }

    ftxt.open("b1.txt", ios::in);
    fbin.open("binary.dat", ios::in | ios::binary);

    if (fbin)
    {
        unsigned short value;
        fbin.read(reinterpret_cast<char*>(&value), sizeof(unsigned short));
        cout << "Value read from binary file: " << value << endl;
        fbin.close();
    }

    return 0;


}