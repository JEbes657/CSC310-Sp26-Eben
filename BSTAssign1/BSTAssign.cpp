#include <iostream>
#include <fstream>
using namespace std;

#include "BSTAssign.h"



// allocate a new node
// not part of the class
treenode *makeatreenode( int x )
{
        treenode *node;
        node = new treenode;
        node->dat = x;
        node->lchild = NULL;
        node->rchild = NULL;

        return node;
}

bstree::bstree()
{
        root = NULL;
}

void bstree::in(treenode *t)
{
        if (t == NULL)
                return;
        in(t->lchild);
        cout << t->dat << " ";
        in(t->rchild);
}

void bstree::pre(treenode *t)
{
        if (t == NULL)
                return;
        cout << t->dat << " ";
        pre(t->lchild);
        pre(t->rchild);
}

void bstree::post(treenode *t)
{
        if (t == NULL)
                return;
        post(t->lchild);
        post(t->rchild);
        cout << t->dat << " ";
}

void bstree::in()
{
        cout << "In: ";
        in(root);
        cout << endl;
}

void bstree::pre()
{
        cout << "Pre: ";
        pre(root);
        cout << endl;
}

void bstree::post()
{
        cout << "Post: ";
        post(root);
        cout << endl;
}

int bstree::numnodes(treenode *t)
{
        if (t == NULL)
                return 0;
        if (t->lchild == NULL && t->rchild == NULL)
                return 1;

        return 1 + numnodes(t->lchild) + numnodes(t->rchild);
}

int bstree::numnodes()
{
        return numnodes(root);
}

bool bstree::bigger(treenode *t)
{
        if (t == NULL)
                return true;
        if (t->lchild == NULL && t->rchild == NULL)
                return true;

        int nL, nR;
        nL = numnodes(t->lchild);
        nR = numnodes(t->rchild);

        if (nL >= nR)
                return true;
        else
                return false;
}

void bstree::remove( int x )
{
        root = remove(root, x);
}

treenode* bstree::remove(treenode *t, int x)
{
    if (t == NULL)
        return t;

    if (x < t->dat)
        {
        t->lchild = remove(t->lchild, x);
    }
        else if (x > t->dat)
        {
        t->rchild = remove(t->rchild, x);
    }
        else
        {

        if (t->lchild == NULL && t->rchild == NULL)
                {
            delete t;
            return NULL;
        }
        else if (t->lchild == NULL)
                {
            treenode *temp = t->rchild;
            delete t;
            return temp;
        }
        else if (t->rchild == NULL)
                {
            treenode *temp = t->lchild;
            delete t;
            return temp;
        }
        else
                {
            treenode *temp = t->rchild;
            treenode *prev = t;
            while (temp->lchild != NULL)
                        {
                prev = temp;
                temp = temp->lchild;
            }

            t->dat = temp->dat;

            if (prev == t)
                        {
                prev->rchild = temp->rchild;
            }
                        else
                        {
                prev->lchild = temp->rchild;
            }
            delete temp;
        }
    }
    return t;
}

bool bstree::bigger()
{
        return bigger(root);
}

void bstree::insertI(int val)
{
        treenode *t = root;

        while (t != NULL)
        {
                if (t->dat = val)
                {
                        return;
                }

                if (t->lchild == NULL)
                {
                        t->lchild == makeatreenode(val);
                }
                else
                {
                        t->rchild == makeatreenode(val);
                }

                if (val < t->dat)
                        t = t->lchild;
                else
                        t = t->rchild;
        }
}

bool bstree::insertR(treenode *t, int val)
{
        if (t->dat == val)
                return false;
        if (val < t->dat)
        {
                if (t->lchild == NULL)
                {
                        t->lchild = makeatreenode(val);
                        return true;
                }
                else
                        return insertR(t->lchild, val);
        }
        else
        {
                if (t->rchild == NULL)
                {
                        t->rchild = makeatreenode(val);
                        return true;
                }
                else
                        return insertR(t->rchild, val);
        }
}

bool bstree::insert( int val )
{
        if (root == NULL)
        {
                root = makeatreenode(val);
                return true;
        }

        return insertR(root, val);
        //return insertI(val);
}

bool bstree::search( int val )
{
        return searchI(val);
        //return searchR(root, val);
}

bool bstree::searchR(treenode *t, int val)
{
        if (t->dat == val)
                return true;
        if (t == NULL)
                return false;

        if (val < t->dat)
                return searchR(t->lchild, val);
        else
                return searchR(t->rchild, val);
}

bool bstree::searchI(int val)
{
        treenode *t = root;

        while (t != NULL)
        {
                if (t->dat == val)
                        return true;

                if (val < t->dat)
                        t = t->lchild;
                else
                        t = t->rchild;
        }

        return false;
}

int bstree::height()
{
        return height(root);
}

int bstree::height(treenode *t)
{
        if (t == NULL)
                return 0;
        if (t->lchild == NULL && t->rchild == NULL)
                return 1;

        int hL, hR;
        hL = height(t->lchild);
        hR = height(t->rchild);

        if (hL >= hR)
                return 1 + hL;
        else
                return 1 + hR;
}

void bstree::printBST(treenode* t, int blank)
{
    if (t == NULL)
        return;

    blank += 10;

    printBST(t->rchild, blank);

    cout << endl;
    for (int i = 10; i < blank; i++)
        cout << " ";
    cout << t->dat << "\n";

    printBST(t->lchild, blank);
}

void bstree::printBST()
{
    printBST(root, 0);
}

int bstree::nodeHeight(int x)
{
    treenode* t = root;

    while (t != NULL)
    {
        if (t->dat == x)
            return height(t);

        if (x < t->dat)
            t = t->lchild;
        else
            t = t->rchild;
    }

    return -1;
}