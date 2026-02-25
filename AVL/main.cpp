#include "avl.h"

int main() {
    AVLTree avl;
    
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "Constructed AVL tree:\n";
    avl.print();

    avl.remove(30);
    
    cout << "After deleting 30:\n";
    avl.print();

    return 0;
}
