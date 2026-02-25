#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node* left;
    Node* right;

    Node(int val) 
    {
        key = val;
        left = nullptr; 
        right = nullptr;
    } 
};

class AVLTree 
{
    public:
        AVLTree();
        ~AVLTree();
        
        void insert(int key);
        void remove(int key);
        void print();

    private:
        Node* root;

        Node* insert(Node* node, int key);
        Node* remove(Node* node, int key);
        Node* minValueNode(Node* node);  //successor
        
        int height(Node* node);
        int getBalanceFactor(Node* node);

        Node* rotateRight(Node* y);
        Node* rotateLeft(Node* y);

        void printTree(Node* root, int space);
        void destroyTree(Node* node);
};

#endif
