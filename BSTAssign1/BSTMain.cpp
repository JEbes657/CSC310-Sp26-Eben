#include <iostream>
#include <fstream>
using namespace std;

#include "BSTAssign.h"

int main(int argc, char *argv[])
{
        bstree t;
        bool r;

        ifstream fp;
        fp.open(argv[1]);

        int num1, num2, num3;

        while (fp >> num1 >> num2)
        {
                if (num1 == 1)
                {
                        t.insert(num2);
                }
                else if (num1 == 2)
                {
                        r = t.search(num2);

                        if (r == true)
                        {
                                cout << "Number was found" << endl;
                        }
                        else
                        {
                                cout << "Number was not found" << endl;
                        }
                }
                else if (num1 == 3)
                {
                        t.pre();
                }
                else if (num1 == 4)
                {
                        t.in();
                }
                else if (num1 == 5)
                {
                        t.post();
                }
                else if (num1 == 6)
                {
                        num2 = t.height();
                        cout << "Height is: " << num2 << endl;
                }
                else if (num1 == -1)
                {
                        t.remove(num2);
                }
                else if (num1 == 7)
                {
                        num3 = t.numnodes();
                        cout << "Number of nodes is: " << num3 << endl;
                }
                else if (num1 == 8)
                {
                        num3 = t.height();
                        cout << "Height is: " << num3 << endl;
                }
                else if (num1 == 9)
                {
                        r = t.bigger();
                        if (r == true)
                                cout << "Left side is bigger" << endl;
                        else
                                cout << "Right side is bigger" << endl;
                }
                else if (num1 == 0)
                {
                    t.printBST();
                    cout << endl;
                }
                else if (num1 == -2)
                {
                        num3 = t.nodeHeight(num2);
                        cout << "Node height: " << num3 << endl;
                }
                else
                {
                        break;
                }
        }
}