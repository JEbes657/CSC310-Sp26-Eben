#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
using namespace std;

class SplayTree {
    private:
        struct Node {
            int key;
            int weight = 0;
            Node* left;
            Node* right;
            Node(int k) {
                key = k;
                weight = 1;
                left = nullptr;
                right = nullptr; 
            }
        };

        int rotations;
        int totaldepth;
        int searchCount;

        int getDepth(Node* root, int key, int depth);

        Node* root;

        Node* rotateRight(Node* x);
        Node* rotateLeft(Node* x);
        Node* splay(Node* x, int key);
        Node* insertNode(Node* root, int key);
        Node* deleteNode(Node* root, int key);
        Node* searchNode(Node* root, int key);
        Node* semiSplay(Node* root, int key, int limit);
        Node* weightedSplay(Node* root, int key);
        void printTree(Node* root, int space);

    public:
        SplayTree();
        void insert(int key);
        void remove(int key);
        bool search(int key);
        void display();

        bool weightedSearch(int key);
        void displayNumbers();
        int findRotations();
        int findDepth();
        void benchmarkSearch(int key);  // For regular splay
        void benchmarkSemiSearch(int key, int limit);  // For semi-splay
        void benchmarkWeightedSearch(int key);  // For weighted splay
        void resetNumbers();
};

class MyException : public exception {
    public:
        MyException(void);
        MyException(const char*);
        MyException(const string&);
        virtual const string what(){
            return this->errString;
        }
    private:
        string errString;
};

#endif 
