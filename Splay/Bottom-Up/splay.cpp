#include "splayHeader.h"

// this is the bottom up implimentation of the splay tree

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
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    // ------------------
    if (y->right)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent)
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    // ------------------

    y->right = x;
    // ------------------
    x->parent = y;
    // ------------------
    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    // ------------------
    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent)
    {
        if (x->parent->right == x)
            x->parent->right = y;
        else
            x->parent->left = y;
    }
    // ------------------

    y->left = x;
    // ------------------
    x->parent = y;
    // ------------------
    return y;
}

// Splaying :)
// bottom-up approach
void SplayTree::splay(Node* x) {
    if (x == nullptr)
        return;

    while(x->parent != nullptr)
    {
        Node* p = x->parent;
        Node* g = p->parent;

        if (!g)
        {
            if (p->left == x)
                rotateRight(p);
            else
                rotateLeft(p);
        }

        else if (g->left == p && p->left == x)
        {
            rotateRight(g);
            rotateLeft(g);
        }
        else if (g->right == p && p->right == x)
        {
            rotateLeft(g);
            rotateLeft(p);
        }
        else if (g->left == p && p->right == x)
        {
            rotateLeft(p);
            rotateRight(p);
        }
        else
        {
            rotateRight(p);
            rotateLeft(g);
        }
    }
    root = x;    
}

//1 pass
void SplayTree::insertNode(int key) {
    if(!root)
    {
        root = new Node(key);
        return;
    }

    Node* curr = root;
    Node* parent = nullptr;

    while(curr)
    {
        parent = curr;
        if (key == curr->key)
            throw MyException("Duplicate Key");
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    Node* n = new Node(key);
    n->parent = parent;

    if (key < parent->key)
        parent->left = n;
    else
        parent->right = n;
    
    splay(n);
}

SplayTree::Node* SplayTree::deleteNode(Node* root, int key) {
    if (root == nullptr) 
        return nullptr;
    
    Node* curr = root;
    while (curr != nullptr) 
    {
        if (key < curr->key) 
        {
            curr = curr->left;
        } 
        else if (key > curr->key) 
        {
            curr = curr->right;
        } 
        else 
        {
            break;
        }
    }
    
    if (curr == nullptr || curr->key != key) 
    {
        return root;
    }
    
    splay(curr);
    
    if (curr->left == nullptr && curr->right == nullptr) 
    {
        delete curr;
        return nullptr;
    }
    else if (curr->left == nullptr) 
    {
        Node* newRoot = curr->right;
        newRoot->parent = nullptr;
        delete curr;
        return newRoot;
    }
    else if (curr->right == nullptr) 
    {
        Node* newRoot = curr->left;
        newRoot->parent = nullptr;
        delete curr;
        return newRoot;
    }
    else 
    {
        Node* maxLeft = curr->left;
        while (maxLeft->right != nullptr) 
        {
            maxLeft = maxLeft->right;
        }
        
        Node* leftSubtree = curr->left;
        Node* rightSubtree = curr->right;
        leftSubtree->parent = nullptr;
        rightSubtree->parent = nullptr;
        
        delete curr;
        
        root = leftSubtree;
        splay(maxLeft);

        maxLeft->right = rightSubtree;
        rightSubtree->parent = maxLeft;
        
        return maxLeft;
    }
}


void SplayTree::insert(int key) {
    insertNode(key);
}


void SplayTree::remove(int key) {
    root = deleteNode(root, key);
}


bool SplayTree::search(int key) {
    splay(root);
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
