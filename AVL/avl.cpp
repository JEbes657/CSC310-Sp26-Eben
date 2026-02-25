#include "avl.h"

AVLTree::AVLTree()
{
    root = nullptr; 
}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

int AVLTree::height(Node* node) {
    if(node)
        return node->height;
    else
        return -1; 
}

int AVLTree::getBalanceFactor(Node* node) {
    if(node)
        return height(node->right) - height(node->left);
    else 
        return 0;
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;

    return x;
}

Node* AVLTree::rotateLeft(Node* y) {
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    return x;
}

Node* AVLTree::insert(Node* node, int key) {


}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* AVLTree::remove(Node* node, int key) {

}

void AVLTree::remove(int key) {
    root = remove(root, key);
}

void AVLTree::printTree(Node* root, int space) {
    const int COUNT = 10; 

    if (root == nullptr) {
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->right, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->key << endl;

    // Print the left child
    printTree(root->left, space);
}

void AVLTree::print() {
    printTree(root, 0);
    cout << endl;
}
