
#ifndef AVL_TREE_
#define AVL_TREE_

#include "binary_search_tree.cpp"

enum Colour {RED, BLACK};

struct RBNode{
    int key_;
    enum Colour color_;
    RBNode *left_, *right_, *parent_;
};


class RedBlackTree {
    public:
    RBNode *root_;
    RBNode *TNULL_;

    void leftRotate(RBNode *);
    void rightRotate(RBNode *);
    void RBInsert(RBNode *);
    void RBInsertFixUp(RBNode *);

    void RBTransplant(RBNode *, RBNode *);
    void RBDelete(RBNode *);

    RedBlackTree();
};

#endif // AVL_TREE_