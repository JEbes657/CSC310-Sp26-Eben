#include "splayHeader.h"

MyException::MyException(void){
    this->errString = "No Error Set";
}

MyException::MyException(const string &err){
    this->errString = err;
}

MyException::MyException(const char *err){
    this->errString = err;
}

SplayTree::SplayTree() 
{
    root = nullptr;
    rotations = 0;
    totaldepth = 0;
    searchCount = 0;
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) {
    rotations++;
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    rotations++;
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splaying :)
// top-down approach
SplayTree::Node* SplayTree::splay(Node* root, int key) {
    
    if (root == nullptr || root->key == key)
        return root;
    
    //key in left subtree
    if (key < root->key)
    {
        if (root->left == nullptr)
            return root;

        // Zig Zig
        if (key < root->left->key)
        {
            root->left->left = splay(root->left->left, key);
            root = rotateRight(root);
        }
        // Zig Zag
        else if (key > root->left->key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = rotateLeft(root->left);
        }
        
        if (root->left == nullptr)
            return root;
        else
            return rotateRight(root);
    }

    //key in right subtree
    if (key > root->key)
    {
        if (root->right == nullptr)
            return root;

        // Zag Zag
        if (key > root->right->key)
        {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        //Zag Zig
        else if (key < root->right->key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rotateRight(root->right);
        }
        
        if (root->right == nullptr)
            return root;
        else
            return rotateLeft(root);
    }

    return root;
}


SplayTree::Node* SplayTree::insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    
    root = splay(root, key);

    if (root->key == key)
        return root;

    Node* newNode = new Node(key);

    if (key < root->key)
    {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    }
    else
    {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    return newNode;
}


SplayTree::Node* SplayTree::deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    root = splay(root, key);

    if (root->key != key)
        return root;

    root = splay(root, key);

    if (root->key != key)
        return root;

    if (root->left == nullptr)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }

    if (root->right == nullptr)
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    Node* leftSub = root->left;
    Node* rightSub = root->right;

    Node* maxNode = leftSub;

    while (maxNode->right != nullptr)
    {
        maxNode = maxNode->right;
    }
    
    leftSub = splay(leftSub, maxNode->key);

    leftSub->right = rightSub;

    delete root;
    return leftSub;
}

SplayTree::Node* SplayTree::searchNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    root = semiSplay(root, key, 3);

    return root;
}

SplayTree::Node* SplayTree::semiSplay(Node* root, int key, int limit) {
    if (root == nullptr || root->key == key || limit <= 0)
        return root;

    if (key < root->key)
    {
        if (root->left == nullptr)
            return root;

        // Zig Zig
        if (key < root->left->key)
        {
            root->left->left = semiSplay(root->left->left, key, limit - 1);
            root = rotateRight(root);
        }
        // Zig Zag
        else if (key > root->left->key)
        {
            root->left->right = semiSplay(root->left->right, key, limit - 1);
            if (root->left->right != nullptr)
                root = rotateLeft(root->left);
        }
        
        if (root->left == nullptr || limit <= 1)
            return root;
        else
            return rotateRight(root);
    }

    if (key > root->key)
    {
        if (root->right == nullptr)
            return root;

        // Zag Zag
        if (key > root->right->key)
        {
            root->right->right = semiSplay(root->right->right, key, limit - 1);
            root = rotateLeft(root);
        }
        // Zag Zig
        else if (key < root->right->key)
        {
            root->right->left = semiSplay(root->right->left, key, limit - 1);
            if (root->right->left != nullptr)
                root->right = rotateRight(root->right);
        }

        if (root->right == nullptr || limit <= 1)
            return root;
        else
            return rotateLeft(root);
    }

    return root;
}

SplayTree::Node* SplayTree::weightedSplay(Node* root, int key) {
    if (root == nullptr || root->key == key) 
    {
        if (root != nullptr && root->key == key) 
        {
            root->weight++;
        }
        return root;
    }
    
    if (key < root->key) 
    {
        if (root->left == nullptr)
            return root;

        // Zig Zig
        if (key < root->left->key)
        {
            root->left->left = weightedSplay(root->left->left, key);
            
            if (root->left->left != nullptr && root->left->left->weight >= root->left->weight) 
            {
                root = rotateRight(root);
            }
        }
        // Zig Zag
        else if (key > root->left->key) 
        {
            root->left->right = weightedSplay(root->left->right, key);
            
            if (root->left->right != nullptr && root->left->right->weight >= root->left->weight) 
            {
                root->left = rotateLeft(root->left);
            }
        }

        if (root->left != nullptr && root->left->weight >= root->weight)
        {
            return rotateRight(root);
        }
        return root;
    }

    if (key > root->key) 
    {
        if (root->right == nullptr)
            return root;

        // Zag Zag
        if (key > root->right->key) 
        {
            root->right->right = weightedSplay(root->right->right, key);
            
            if (root->right->right != nullptr && root->right->right->weight >= root->right->weight) 
            {
                root = rotateLeft(root);
            }
        }
        // Zag Zig
        else if (key < root->right->key) 
        {
            root->right->left = weightedSplay(root->right->left, key);
            
            if (root->right->left != nullptr && root->right->left->weight >= root->right->weight) 
            {
                root->right = rotateRight(root->right);
            }
        }
        
        if (root->right != nullptr && root->right->weight >= root->weight) 
        {
            return rotateLeft(root);
        }
        return root;
    }

    return root;
}

void SplayTree::insert(int key) {
    root = insertNode(root, key);
}

void SplayTree::remove(int key) {
    root = deleteNode(root, key);
}

bool SplayTree::search(int key) {
    if (root == nullptr)
        return false;
        
    root = searchNode(root, key);
    return (root && root->key == key);
}

void SplayTree::printTree(Node* root, int space) {
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

void SplayTree::display() {
    printTree(root, 0);
    cout << endl;
}

void SplayTree::resetNumbers() {
    rotations = 0;
    totaldepth = 0;
    searchCount = 0;
}

int SplayTree::getDepth(Node* root, int key, int depth) {
    if (root == nullptr)
        return -1;

    if (root->key == key)
        return depth;

    if (key < root->key)
        return getDepth(root->left, key, depth + 1);
    else
        return getDepth(root->right, key, depth + 1);
}

void SplayTree::benchmarkSearch(int key) {
    int depth = getDepth(root, key, 0);
    if (depth >= 0)
    {
        totaldepth += depth;
        searchCount++;
    }
    root = splay(root,key);
}

void SplayTree::benchmarkSemiSearch(int key, int limit) {
    int depth = getDepth(root, key, 0);
    if (depth >= 0)
    {
        totaldepth += depth;
        searchCount++;
    }
    root = semiSplay(root, key, limit);
}

void SplayTree::benchmarkWeightedSearch(int key) {
    int depth = getDepth(root, key, 0);
    if (depth >= 0)
    {
        totaldepth += depth;
        searchCount++;
    }
    root = weightedSplay(root, key);
}

void SplayTree::displayNumbers() {
    cout << "Rotations: " << rotations << endl;
    cout << "Searches: " << searchCount << endl;
    if (searchCount > 0)
    {
        cout << "Search Depth: " << (double)totaldepth / searchCount << endl;
    }
}

int SplayTree::findRotations() {
    return rotations;
}

int SplayTree::findDepth() {
    if (searchCount == 0) return 0;
    return totaldepth / searchCount;
}

bool SplayTree::weightedSearch(int key) {
    root = weightedSplay(root, key);
    return (root && root->key == key);
}