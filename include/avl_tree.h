#ifndef AVL_TREE_
#define AVL_TREE_

#include <iostream>

#include "binary_search_tree.h"

// AVLNode cannot inherit from Node (BStree)
// Node in BStree points to Node, not AVL node
// This will lead to incorrect operations
template <class T>
struct AVLNode{
    T key_; 
    int balance_;
    AVLNode *left_, *right_, *parent_;
};


template <class T, typename Node_>
class AVLtree : public BStree<T, Node_>{
    public:
    AVLtree();
    // void makeTreeFromArr(T [], int);
    
    protected:
    // Node_ *root_; // ?????
    Node_ *newNode(T);

    // Unique of AVL tree to balancing the tree
    int height(Node_ *);
    void setBalance(Node_ *);
    void rotateLeft(Node_ *x);
    void rotateRight(Node_ *y);
    void rotateLeftThenRight(Node_ *n);
    void rotateRightThenLeft(Node_ *n);
    void reBalance(Node_ *);
    void treeInsert(Node_ *);
    // need re-balance after delete a node
    void treeDelete( Node_ *);
};

#endif // AVL_TREE_