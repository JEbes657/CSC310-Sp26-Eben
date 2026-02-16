#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
using namespace std;

class SplayTree {
    private:
        struct Node {
            int key;
            Node* left;
            Node* right;
            Node* parent;
            Node(int k) {
                key = k;
                left = nullptr;
                right = nullptr; 
                parent = nullptr;
            }
        };

        Node* root;

        Node* rotateRight(Node* x);
        Node* rotateLeft(Node* x);
        //Node* splay(Node* x, int key);
        void splay(Node* x);
        //Node* insertNode(Node* root, int key);
        void insertNode(int key);
        Node* deleteNode(Node* root, int key);
        Node* searchNode(int key);

        void printTree(Node* root, int space);

        int rotations;
        int totaldepth;
        int searchCount;

        int findDepth(Node* root, int key, int depth);
    public:
        SplayTree();
        void insert(int key);
        void remove(int key);
        bool search(int key);
        void display();

        void resetNumbers();
        void benchmarkSearch(int key);
        void displayNumbers();
        int findRotations();
        int findDepth();
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
