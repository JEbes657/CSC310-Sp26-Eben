#include "splayHeader.h"
#include <chrono>
#include <fstream>
#include <iostream>

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

void getSemiData(const string& fileText)
{
    ifstream file(fileText);

    int num = 0;
    SplayTree tree2;

    auto start = chrono::steady_clock::now();

    while (file >> num)
    {
        tree2.benchmarkWeightedSearch(num);

        if (!tree2.search(num))
        {
            tree2.insert(num);
        }
    }

    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    tree2.displayNumbers();

    cout << "Time: " << duration << endl << endl;

    file.close();
}

void getWeightedData(const string& fileText)
{
    ifstream file(fileText);

    int num = 0;
    SplayTree tree3;

    auto start = chrono::steady_clock::now();

    while (file >> num)
    {
        tree3.benchmarkWeightedSearch(num);

        if (!tree3.search(num))
        {
            tree3.insert(num);
        }
    }

    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    tree3.displayNumbers();

    cout << "Time: " << duration << endl << endl;

    file.close();
}

int main() {

    cout << "Top-Down" << endl << endl;

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

    // ----------------------------------------------------------
    cout << "Semi-Splay" << endl << endl;

    cout << "sequential" << endl;
    file = "../accessPattern/sequential.txt";
    getSemiData(file);

    cout << "uniform random" << endl;
    file = "../accessPattern/uniform_random.txt";
    getSemiData(file);

    cout << "skewed" << endl;
    file = "../accessPattern/zipf_skewed.txt";
    getSemiData(file);

    cout << "working set" << endl;
    file = "../accessPattern/working_set.txt";
    getSemiData(file);

    // ----------------------------------------------------------

    cout << "Weighted Splay" << endl << endl;

    cout << "sequential" << endl;
    file = "../accessPattern/sequential.txt";
    getWeightedData(file);

    cout << "uniform random" << endl;
    file = "../accessPattern/uniform_random.txt";
    getWeightedData(file);

    cout << "skewed" << endl;
    file = "../accessPattern/zipf_skewed.txt";
    getWeightedData(file);

    cout << "working set" << endl;
    file = "../accessPattern/working_set.txt";
    getWeightedData(file);
}