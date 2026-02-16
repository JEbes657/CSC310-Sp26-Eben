#include "splayHeader.h"
#include <chrono>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
using namespace chrono;

vector<int> readFile(string filename) {
    vector<int> nums;
    ifstream file(filename);
    int n;
    while (file >> n) {
        nums.push_back(n);
    }
    file.close();
    return nums;
}

int main() {
    // Read the files
    vector<int> seq = readFile("../access_pattern/sequential.txt");
    vector<int> uni = readFile("../access_pattern/uniform.txt");
    vector<int> skew = readFile("../access_pattern/skewed.txt");
    vector<int> work = readFile("../access_pattern/workingset.txt");
    
    // Test sequential pattern
    cout << "Sequential Pattern:" << endl;
    
    SplayTree tree1;
    tree1.resetNumbers();
    auto start = high_resolution_clock::now();
    for (int num : seq) {
        tree1.benchmarkSearch(num);
        if (!tree1.search(num)) {
            try {
                tree1.insert(num);
            } catch (MyException& e) {
                // Duplicate, skip
            }
        }
    }
    auto end = high_resolution_clock::now();
    cout << "Bottom-Up Splay:" << endl;
    tree1.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    
    // Test uniform pattern
    cout << "Uniform Pattern:" << endl;
    
    SplayTree tree2;
    tree2.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : uni) {
        tree2.benchmarkSearch(num);
        if (!tree2.search(num)) {
            try {
                tree2.insert(num);
            } catch (MyException& e) {
                // Duplicate, skip
            }
        }
    }
    end = high_resolution_clock::now();
    cout << "Bottom-Up Splay:" << endl;
    tree2.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    
    // Test skewed pattern
    cout << "Skewed Pattern:" << endl;
    
    SplayTree tree3;
    tree3.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : skew) {
        tree3.benchmarkSearch(num);
        if (!tree3.search(num)) {
            try {
                tree3.insert(num);
            } catch (MyException& e) {
                // Duplicate, skip
            }
        }
    }
    end = high_resolution_clock::now();
    cout << "Bottom-Up Splay:" << endl;
    tree3.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    
    // Test working set pattern
    cout << "Working Set Pattern:" << endl;
    
    SplayTree tree4;
    tree4.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : work) {
        tree4.benchmarkSearch(num);
        if (!tree4.search(num)) {
            try {
                tree4.insert(num);
            } catch (MyException& e) {
                // Duplicate, skip
            }
        }
    }
    end = high_resolution_clock::now();
    cout << "Bottom-Up Splay:" << endl;
    tree4.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    return 0;
}