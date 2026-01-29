#include <iostream>
#include <fstream>
using namespace std;

// tree node for linked BST
struct treenode
{
    int dat;
    treenode *lchild;
    treenode *rchild;
};

class bstree
{
 public:
        bstree();
        void in( );
        void pre( );
        void post( );
        bool insert( int x );
        void remove( int x );
        bool search( int x );
        int numnodes(); // must compute, not a variable in class
        int height(); // must compute, not a variable in class
        bool bigger(); //tell which side  is larger
        void printBST();
 private:
        void in(treenode *t);
        void pre(treenode *t);
        void post(treenode *t);
        void insertI(int x);
        bool insertR(treenode *t, int x);
        bool searchI(int x);
        bool searchR(treenode *t, int x);
        int height(treenode *t);
        int numnodes(treenode *t);
        treenode* remove(treenode *t, int x);
        bool bigger(treenode *t);
        treenode *root;
        void printBST(treenode* t, int blank);
};