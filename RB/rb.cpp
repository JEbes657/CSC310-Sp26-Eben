#include "rb.h"

// ++++++++++++++++++++++++++++++ PUBLIC +++++++++++++++++++++++++++++++++++++++

RBTREE::RBTREE()
{


}

RBTREE::~RBTREE()
{
    deleteSubtree(root);
}

void RBTREE::insert(int key)
{

}

void RBTREE::remove(int key)
{
    removeR(root, key);
}

void RBTREE::printTree()
{
    if(root == TNULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    print(root, 0);
}

// ++++++++++++++++++++++++++++++ PRIVATE +++++++++++++++++++++++++++++++++++++++++++++

void RBTREE::leftRotate(Node* y)
{
    Node* x = y->right;
    if (x == TNULL || x == nullptr) return;  // Prevent invalid rotation
    y->right = x->left;  // adoption

    if(x->left != TNULL) // updating parent of adopted left child
        x->left->parent = y; 

    // update parent of x
    x->parent = y->parent;
    if(y->parent == nullptr)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->left = y;
    y->parent = x;
    
}

void RBTREE::rightRotate(Node* y)
{
    Node* x = y->left;
    if (x == TNULL || x == nullptr) return;  // Prevent invalid rotation
    y->left = x->right;  // adoption

    if(x->right != TNULL) // updating parent of adopted left child
        x->right->parent = y; 

    // update parent of x
    x->parent = y->parent;
    if(y->parent == nullptr)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void RBTREE::insertR(Node*& root, Node*& node)
{
    if(root == TNULL)
    {
        root = node;
        return;
    }

    if(node->data < root->data)
    {
        if(root->left == TNULL)
        {
            root->left = node;
            node->parent = root;
        } else {
            insertR(root->left, node);
        }
    } else {
        if(root->right == TNULL)
        {
            root->right = node;
            node->parent = root;
        } else {
            insertR(root->right, node);
        }
    }
}

void RBTREE::insertFix(Node* k)
{

}


void RBTREE::removeR(Node*& node, int key)
{
    if (node == TNULL)
        return;

    if (key < node->data)
        removeR(node->left, key);
    else if (key > node->data)
        removeR(node->right, key);
    else //found the node
    {
        Node* z = node; //node to delete
        Node* y = node;
        Node* x; // replacement
        Color y_original_color = y->color;

        if (node->left == TNULL && node->right != TNULL) // CASE 1
        {
            x = node->right;
            transplant(node, node->right);
        }
        else if (node->left != TNULL && node->right == TNULL) // CASE 2
        {
            x = node->left;
            transplant(node, node->left);
        }
        else if (node->left == TNULL && node->right == TNULL)
        {
            x = TNULL;
            transplant(node, TNULL);
        }
        else // CASE 3
        {
            y = successor(node->right);
            y_original_color = x->color;
            x = y->right; // replacement for successor

            if (y->parent != node)
            {
                transplant(y, y->right);

                y->right = node->right;
                y->right->parent = y;
            }

            y->left = node->left;
            y->left->parent = y;
            transplant(node, y);
            y->color = node->color;
        }

        if (y_original_color == BLACK)
        {
            deleteFix(x);
        }

        delete z;
    }
    root->color = BLACK;
}

void RBTREE::deleteFix(Node* x) {
   Node* sibling;

   while (x != root && x->color == BLACK)
   {
        // x is left child
        if (x == x->parent->left)
        {
            sibling = x->parent->right;

            if (sibling->color == RED) // CASE 1
            {
                sibling->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                sibling = x->parent->right;
            }
            
            if (sibling->left->color == BLACK && sibling->right == BLACK) // CASE 2
            {
                sibling->color = RED;
                x = x->parent;
            }
            else // CASE 3
            {
                if (sibling->right->color == BLACK) // CASE 3
                {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rightRotate(sibling);
                    sibling = x->parent->right;
                }

                // CASE 4
                sibling->color = x->parent->color;
                x->parent->color = BLACK;
                sibling->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        }
        else // x is right child (the symmetric variant)
        {
            sibling = x->parent->left;

            if (sibling->color == RED) // CASE 1
            {
                sibling->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                sibling = x->parent->right;
            }
            
            if (sibling->left->color == BLACK && sibling->right == BLACK) // CASE 2
            {
                sibling->color = RED;
                x = x->parent;
            }
            else // CASE 3
            {
                if (sibling->right->color == BLACK) // CASE 3
                {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    leftRotate(sibling);
                    sibling = x->parent->right;
                }

                // CASE 4
                sibling->color = x->parent->color;
                x->parent->color = BLACK;
                sibling->right->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
   }
   x->color = BLACK;
}

void RBTREE::transplant(Node*& u, Node*& v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if(v != TNULL)
        v->parent = u->parent;
}

Node* RBTREE::successor(Node* node) {
    if (node == TNULL) 
        return TNULL;
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

void RBTREE::deleteSubtree(Node* node) {
    if (node != TNULL) {
        deleteSubtree(node->left);
        deleteSubtree(node->right);
        delete node;
    }
}


void RBTREE::print(Node* root, int space ) {
    if (root == TNULL || root == nullptr)
        return;

    space += 10;
    print(root->right, space);

    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";

        
    string color_code = (root->color == RED) ? RED_COLOR : BLACK_COLOR;
    cout << color_code << root->data << RESET_COLOR;
    cout << endl;
    print(root->left, space);
}
