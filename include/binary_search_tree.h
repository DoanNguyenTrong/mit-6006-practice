#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

// #include "avl_tree.h"

template <class T>
struct Node
{
    T key_;
    Node *left_, *right_, *parent_;
};

template <class T, typename Node_>
class BStree{
    public:
    BStree();
    void makeTreeFromArr(T [], int);
    void inorderTreeWalk();
    void treeSearchPrint(T);
    void treeSuccPrint(T);
    void treePredesPrint(T);
    void treeDeletePrint(T);

    protected:
    Node_ *root_;
    // Make tree
    Node_ *newNode(T);
    virtual void treeInsert(Node_ *);
    // print ordered
    void inorder(Node_ *);
    // Search for a key
    Node_ *treeSearch(Node_ *, T);
    // Min-Max
    Node_ *treeMin(Node_ *);
    Node_ *treeMax(Node_ *);
    // Find Successor and Predecessor
    Node_ *treeSuccessor(Node_ *);
    Node_ *treePredecessor(Node_ *);
    // Delete
    void transplant(Node_ *, Node_ *);
    virtual void treeDelete(Node_ *);
};


#endif // #define BINARY_SEARCH_TREE_