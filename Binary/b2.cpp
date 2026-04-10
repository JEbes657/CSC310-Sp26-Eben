#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    fstream ftxt, fbin;

    ftxt.open("file.dat");

    if (ftxt)
    {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (auto c : arr)
        {
            ftxt << c;
            fbin.write(reinterpret_cast<char*>(arr), sizeof(arr));
            fbin.close();
        }
        else
        {
            
        }

    }
}