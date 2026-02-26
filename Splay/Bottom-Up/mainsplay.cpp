#include "splayHeader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

void getData(const string& fileText)
{
    ifstream file(fileText);

    int num = 0;
    SplayTree tree1;

    auto start = chrono::steady_clock::now();

    while (file >> num)
    {
        tree1.benchmarkSearch(num);

        if (!tree1.search(num))
        {
            tree1.insert(num);
        }
    }

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    tree1.displayNumbers();

    cout << "Time: " << duration << endl << endl;

    file.close();
}

int main() {

    cout << "Bottom-Up" << endl;

    cout << "sequential" << endl;
    string file = "../accessPattern/sequential.txt";
    getData(file);

    cout << "uniform random" << endl;
    file = "../accessPattern/uniform_random.txt";
    getData(file);

    cout << "skewed" << endl;
    file = "../accessPattern/zipf_skewed.txt";
    getData(file);

    cout << "working set" << endl;
    file = "../accessPattern/working_set.txt";
    getData(file);
}