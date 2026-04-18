#include "binomial.h"

int main() {
    BinomialHeap bh;
    bh.insert(10);
    bh.insert(20);
    bh.insert(5);
    bh.insert(30);
    bh.insert(1);
    bh.insert(14);
    bh.insert(27);
    bh.insert(8);
    bh.insert(3);
    bh.insert(12);
    
    cout << "Heap after insertions:" << endl;
    bh.printHeap();
    
    cout << endl << "Minimum key: " << bh.findMin() << endl;

    cout << "\nDeleting minimum element..." << endl;
    bh.deleteMin();
    bh.printHeap();
    cout << endl << "Minimum key after deleteMin: " << bh.findMin() << endl;

    cout << "\nDecreasing key 14 to 2..." << endl;
    bh.decreaseKey(14, 2);
    bh.printHeap();
    cout << endl << "Minimum key after decreaseKey: " << bh.findMin() << endl;

    cout << "\nDeleting minimum element again..." << endl;
    bh.deleteMin();
    bh.printHeap();
    cout << endl << "Minimum key after second deleteMin: " << bh.findMin() << endl;
    return 0;
}