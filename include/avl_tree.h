#ifndef AVL_TREE_
#define AVL_TREE_

#include <iostream>

template <class T>
struct AVLNode{
    T key_; 
    int balance_;
    AVLNode *left_, *right_, *parent_;
};

template <class T>
class AVLtree{
    public:

    void treeInsert(AVLNode<T> *);
    void treeDelete(AVLNode<T> *);
    void inorderTreeWalk();
    void ballancePrint();
    void treeDeletePrint(T);

    AVLtree();
    // ~AVLtree();
    private:
    AVLNode<T> *root_;

    void rotateLeft(AVLNode<T> *x);
    void rotateRight(AVLNode<T> *y);
    void rotateLeftThenRight(AVLNode<T> *n);
    void rotateRightThenLeft(AVLNode<T> *n);

    int height(AVLNode<T> *n);
    void setBalance(AVLNode<T> *n);
    void reBalance(AVLNode<T> *n);

    AVLNode<T> *treeMin(AVLNode<T> *);
    AVLNode<T> *treeMax(AVLNode<T> *);

    AVLNode<T> * treeSearch(AVLNode<T> *, T);
    void treeTraversal(AVLNode<T> *);

    void transplant(AVLNode<T> *, AVLNode<T> *, AVLNode<T> *);
};

#endif // AVL_TREE_