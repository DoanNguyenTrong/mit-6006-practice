#include <iostream>

#include "avl_tree.h"

template <class T, typename Node_>
AVLtree<T, Node_>::AVLtree(){
    std::cout << "AVLtree's constructor called: " << this->root_ << std::endl;
    // root_ = NULL;
    // BStree<T, Node_>::BStree();
}

// --------------------------------------------------
//           utility functions
// - create a new node
// - calculate height
// - set balance_ of node
// --------------------------------------------------
template <class T, typename Node_>
Node_ *AVLtree<T, Node_>::newNode(T key){
    Node_ *temp = this->BStree<T, Node_>::newNode(key);
    temp->balance_ = 0;
    return temp;
}

template <class T, typename Node_>
int AVLtree<T, Node_>::height(Node_ *n){
    if (n == NULL){
        return -1;
    }
    int bal = 1 + std::max(this->height(n->left_), this->height(n->right_));
    return bal;
}

template <class T, typename Node_>
void AVLtree<T, Node_>::setBalance(Node_ *n) {
    n->balance_ = height(n->right_) - height(n->left_);
}
// --------------------------------------------------
//           Build tree
// - rotate left
// - rotate right
// - rotate left then right
// - rotate right then left
// - Re-balance
// - insert a node to the tree (`treeInsert())
// --------------------------------------------------

template <class T, typename Node_>
void AVLtree<T, Node_>::rotateLeft(Node_ *x){
    Node_ *y = x->right_;
    x->right_ = y->left_;
    if (y->left_ != NULL){
        y->left_->parent_ = x;
    }
    y->parent_ = x->parent_;
    if (x->parent_ == NULL){
        this->root_ = y;
    }
    else if (x == x->parent_->left_){
        x->parent_->left_ = y;
    }
    else{
        x->parent_->right_ = y;
    }

    y->left_ = x;
    x->parent_ = y;
    setBalance(x);
    setBalance(y);
}

template <class T, typename Node_>
void AVLtree<T, Node_>::rotateRight(Node_ *y){
    Node_ *x = y->left_;
    y->left_ = x->right_;
    if (x->right_ != NULL){
        x->right_->parent_ = y;
    }
    x->parent_ = y->parent_;
    if (y->parent_ == NULL){
        this->root_ = x;
    }
    else if (y == y->parent_->left_){
        y->parent_->left_ = x;
    }
    else{
        y->parent_->right_ = x;
    }
    x->right_ = y;
    y->parent_ = x;
    setBalance(x);
    setBalance(y);
}

template <class T, typename Node_>
void AVLtree<T, Node_>::rotateLeftThenRight(Node_ *n){
    rotateLeft(n->left_);
    rotateRight(n);
}

template <class T, typename Node_>
void AVLtree<T, Node_>::rotateRightThenLeft(Node_ *n){
    rotateRight(n->right_);
    rotateLeft(n);
}

template <class T, typename Node_>
void AVLtree<T, Node_>::reBalance(Node_ *n){
    setBalance(n);
    if (n->balance_ == -2){
        if (height(n->left_->left_) >= height(n->left_->right_)){
            rotateRight(n);
            std::cout << "Rotate Right\n";
        }
        else{
            rotateLeftThenRight(n);
            std::cout << "Rotate Left then Right\n";
        }
    }
    else if (n->balance_ == 2){
        if (height(n->right_->right_) >= height(n->right_->left_)){
            rotateLeft(n);
            std::cout << "Rotate Left\n";
        }
        else{
            rotateRightThenLeft(n);
            std::cout << "Rotate Right then Left\n";
        }
    }
    if (n->parent_ != NULL){
        reBalance(n->parent_);
    }
    else{
        this->root_ = n;
    }
}

template <class T, typename Node_>
void AVLtree<T, Node_>::treeInsert(Node_ *z){
    // // Step 1: Travesal through the tree then attach z to proper positions
    BStree<T, Node_>::treeInsert(z);
    // Step 2:Re-balancing the tree from parent of z upward to root
    // as z is a leaf
    // std::cout << "Step 2\n";
    if (z->parent_ != NULL){
        reBalance(z->parent_);
    }
}
// --------------------------------------------------
//           Delete a node in the tree
// - treeDelete
// --------------------------------------------------


template <class T, typename Node_>
void AVLtree<T, Node_>::treeDelete(Node_* z){
    if (z->left_ == NULL){
        this->transplant(z, z->right_);
        // reBalance from parent of z
        if (z->parent_ != NULL){
            reBalance(z->parent_);
        }
    }
    else if (z->right_ == NULL){
        this->transplant(z, z->left_);
        // reBalance from parent of z
        if (z->parent_ != NULL){
            reBalance(z->parent_);
        }
    }
    else{
        Node_*y = this->treeMin(z->right_);
        Node_*parent_y = y->parent_;
        if (y != z->right_){
            this->transplant (y, y->right_);
            y->right_ = z->right_;
            y->right_->parent_ = y;
        }
        this->transplant(z, y);
        y->left_ = z->left_;
        y->left_->parent_ = y;

        // reBalance from parent of the min Node of (z's right child)
        if (parent_y != NULL){
            reBalance(parent_y);
        }
    }
    // Delete z to avoid memory leak
    delete z;
}

// --------------------------------------------------
//           Main function
// --------------------------------------------------
void avl_tree_search(int arr[], const int N){
    std::cout << "AVL tree\n";
    AVLtree<int, AVLNode<int> > tree;

    tree.makeTreeFromArr(arr, N);
    
    std::cout << "Tree travesal: ";
    tree.inorderTreeWalk();

    int val = 32;
    tree.treeSearchPrint(val);
    tree.treeSuccPrint(val);
    tree.treePredesPrint(val);
    tree.treeDeletePrint(val);
}


// Linker
template class AVLtree<int, AVLNode<int> >;