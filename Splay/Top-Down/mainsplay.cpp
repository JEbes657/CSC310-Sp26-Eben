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
    vector<int> seq = readFile("../accessPattern/sequential.txt");
    vector<int> uni = readFile("../accessPattern/uniform_random.txt");
    vector<int> skew = readFile("../accessPattern/zipf_skewed.txt");
    vector<int> work = readFile("../accessPattern/working_set.txt");
    
    // Test sequential pattern
    cout << "Sequential Pattern:" << endl;
    
    SplayTree tree1;
    tree1.resetNumbers();
    auto start = high_resolution_clock::now();
    for (int num : seq) {
        tree1.benchmarkSearch(num);
        if (!tree1.search(num)) {
            tree1.insert(num);
        }
    }
    auto end = high_resolution_clock::now();
    cout << "Top-Down Splay:" << endl;
    tree1.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree2;
    tree2.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : seq) {
        tree2.benchmarkSemiSearch(num, 5);
        if (!tree2.search(num)) {
            tree2.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Semi-Splay:" << endl;
    tree2.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree3;
    tree3.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : seq) {
        tree3.benchmarkWeightedSearch(num);
        if (!tree3.search(num)) {
            tree3.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Weighted-Splay:" << endl;
    tree3.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    
    // Test uniform pattern
    cout << "\nUniform Pattern:" << endl;
    
    SplayTree tree4;
    tree4.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : uni) {
        tree4.benchmarkSearch(num);
        if (!tree4.search(num)) {
            tree4.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Top-Down Splay:" << endl;
    tree4.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree5;
    tree5.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : uni) {
        tree5.benchmarkSemiSearch(num, 5);
        if (!tree5.search(num)) {
            tree5.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Semi-Splay:" << endl;
    tree5.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree6;
    tree6.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : uni) {
        tree6.benchmarkWeightedSearch(num);
        if (!tree6.search(num)) {
            tree6.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Weighted-Splay:" << endl;
    tree6.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    
    // Test skewed pattern
    cout << "\nSkewed Pattern:" << endl;
    
    SplayTree tree7;
    tree7.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : skew) {
        tree7.benchmarkSearch(num);
        if (!tree7.search(num)) {
            tree7.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Top-Down Splay:" << endl;
    tree7.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree8;
    tree8.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : skew) {
        tree8.benchmarkSemiSearch(num, 5);
        if (!tree8.search(num)) {
            tree8.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Semi-Splay:" << endl;
    tree8.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree9;
    tree9.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : skew) {
        tree9.benchmarkWeightedSearch(num);
        if (!tree9.search(num)) {
            tree9.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Weighted-Splay:" << endl;
    tree9.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    
    // Test working set pattern
    cout << "\nWorking Set Pattern:" << endl;
    
    SplayTree tree10;
    tree10.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : work) {
        tree10.benchmarkSearch(num);
        if (!tree10.search(num)) {
            tree10.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Top-Down Splay:" << endl;
    tree10.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree11;
    tree11.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : work) {
        tree11.benchmarkSemiSearch(num, 5);
        if (!tree11.search(num)) {
            tree11.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Semi-Splay:" << endl;
    tree11.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    SplayTree tree12;
    tree12.resetNumbers();
    start = high_resolution_clock::now();
    for (int num : work) {
        tree12.benchmarkWeightedSearch(num);
        if (!tree12.search(num)) {
            tree12.insert(num);
        }
    }
    end = high_resolution_clock::now();
    cout << "Weighted-Splay:" << endl;
    tree12.displayNumbers();
    cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds\n" << endl;
    
    return 0;
}