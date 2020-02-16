#include <iostream>

#include "avl_tree.h"

// template <class T>
// AVLNode<T> *newAVLNode(T key){
//     AVLNode<T> *temp = new AVLNode<T>;
//     temp->key_ = key;
//     temp->parent_ = temp->left_ = temp->right_ = NULL;
//     temp->balance_ = 0;
//     return temp;
// }
// template <class T>
// AVLtree<T>::AVLtree(){
//     root_ = NULL;
// }

// template <class T>
// int AVLtree<T>::height(AVLNode<T> *n){
//     if (n == NULL){
//         return -1;
//     }
//     return 1 + std::max(height(n->left_), height(n->right_));
// }

// template <class T>
// void AVLtree<T>::setBalance(AVLNode<T> *n) {
//     n->balance_ = height(n->right_) - height(n->left_);
// }

// template <class T>
// void AVLtree<T>::rotateLeft(AVLNode<T> *x){
//     AVLNode<T> *y = x->right_;
//     x->right_ = y->left_;
//     if (y->left_ != NULL){
//         y->left_->parent_ = x;
//     }
//     y->parent_ = x->parent_;
//     if (x->parent_ == NULL){
//         root_ = y;
//     }
//     else if (x == x->parent_->left_){
//         x->parent_->left_ = y;
//     }
//     else{
//         x->parent_->right_ = y;
//     }
//     y->left_ = x;
//     x->parent_ = y;
//     setBalance(x);
//     setBalance(y);
// }

// template <class T>
// void AVLtree<T>::rotateRight(AVLNode<T> *y){
//     AVLNode<T> *x = y->left_;
//     y->left_ = x->right_;
//     if (x->right_ != NULL){
//         x->right_->parent_ = y;
//     }
//     x->parent_ = y->parent_;
//     if (y->parent_ == NULL){
//         root_ = x;
//     }
//     else if (y == y->parent_->left_){
//         y->parent_->left_ = x;
//     }
//     else{
//         y->parent_->right_ = x;
//     }
//     x->right_ = y;
//     y->parent_ = x;
//     setBalance(x);
//     setBalance(y);
// }

// template <class T>
// void AVLtree<T>::rotateLeftThenRight(AVLNode<T> *n){
//     rotateLeft(n->left_);
//     rotateRight(n);
// }

// template <class T>
// void AVLtree<T>::rotateRightThenLeft(AVLNode<T> *n){
//     rotateRight(n->right_);
//     rotateLeft(n);
// }

// template <class T>
// void AVLtree<T>::reBalance(AVLNode<T> *n){
//     setBalance(n);
//     if (n->balance_ == -2){
//         if (height(n->left_->left_) >= height(n->left_->right_)){
//             rotateRight(n);
//             std::cout << "Rotate Right\n";
//         }
//         else{
//             rotateLeftThenRight(n);
//             std::cout << "Rotate Left then Right\n";
//         }
//     }
//     else if (n->balance_ == 2){
//         if (height(n->right_->right_) >= height(n->right_->left_)){
//             rotateLeft(n);
//             std::cout << "Rotate Left\n";
//         }
//         else{
//             rotateRightThenLeft(n);
//             std::cout << "Rotate Right then Left\n";
//         }
//     }
//     // else{
//     //     std::cout << "balance: " << n->balance_ << std::endl;
//     // }

//     if (n->parent_ != NULL){
//         reBalance(n->parent_);
//     }
//     else{
//         root_ = n;
//     }
// }

// template <class T>
// void AVLtree<T>::treeInsert(AVLNode<T> *z){
//     // Step 1: Travesal through the tree then attach z to proper positions
//     AVLNode<T> *y = NULL;
//     AVLNode<T> *x = root_;
//     while (x != NULL){
//         y = x;
//         if (z->key_ < y->key_){
//             x = x->left_;
//         }
//         else{
//             x = x->right_;
//         }
//     }
//     // Attach z to the BST
//     z->parent_ = y; 
//     if (y == NULL){
//         root_ = z;
//     }
//     else if (z->key_ < y->key_){
//         y->left_ = z;
//     }
//     else {
//         y->right_ = z;
//     }
    
//     // Step 2:Re-balancing the tree from parent of z upward to root
//     // as z is a leaf
//     // std::cout << "Step 2\n";
//     if (z->parent_ != NULL){
//         reBalance(z->parent_);
//     }
// }

// template <class T>
// void AVLtree<T>::treeTraversal(AVLNode<T> *x){
//     if (x != NULL){
//         treeTraversal(x->left_);
//         std::cout << x->key_ << " ";
//         treeTraversal(x->right_);
//     }
// }
// template <class T>
// void AVLtree<T>::inorderTreeWalk(){
//     std::cout << "Tree Walk to print indorder!\n";
//     AVLNode<T> *x = root_;
//     treeTraversal(x);
//     std::cout << " END\n";
// }


// template <class T>
// void AVLtree<T>::transplant(AVLNode<T> *root, AVLNode<T> *u, AVLNode<T> *v){
//     if(u->parent_ == NULL){
//         root = v;
//     }
//     else if(u == u->parent_->left_){
//         u->parent_->left_ = v;
//     }
//     else{
//         u->parent_->right_ = v;
//     }
//     if (v != NULL){
//         v->parent_ = u->parent_;
//     }
// }
// template <class T>
// AVLNode<T> *AVLtree<T>::treeMin(AVLNode<T> *n){
//     while (n->left_ != NULL){
//         n = n->left_;
//     }
//     return n;
// }
// template <class T>
// AVLNode<T> *AVLtree<T>::treeMax(AVLNode<T> *n){
//     while (n->right_ != NULL){
//         n = n->right_;
//     }
//     return n;
// }


// template <class T>
// void AVLtree<T>::treeDelete(AVLNode<T> *z){
//     if (z->left_ == NULL){
//         transplant(root_, z, z->right_);
//         // reBalance from parent of z
//         if (z->parent_ != NULL){
//             reBalance(z->parent_);
//         }
//     }
//     else if (z->right_ == NULL){
//         transplant(root_, z, z->left_);
//         // reBalance from parent of z
//         if (z->parent_ != NULL){
//             reBalance(z->parent_);
//         }
//     }
//     else{
//         AVLNode<T> *y = treeMin(z->right_);
//         AVLNode<T> *parent_y = y->parent_;
//         if (y != z->right_){
//             transplant(root_, y, y->right_);
//             y->right_ = z->right_;
//             y->right_->parent_ = y;
//         }
//         transplant(root_, z, y);
//         y->left_ = z->left_;
//         y->left_->parent_ = y;

//         // reBalance from parent of the min Node of (z's right child)
//         if (parent_y != NULL){
//             reBalance(parent_y);
//         }
//     }
//     // Delete z to avoid memory leak
//     delete z;
// }
// template <class T>
// AVLNode<T> *AVLtree<T>::treeSearch(AVLNode<T> *r, T key){
//     if (r == NULL || r->key_ == key){
//         return r;
//     }
//     if(r->key_ > key){
//         return treeSearch(r->left_, key);
//     }
//     else{
//         return treeSearch(r->right_, key);
//     }
// }
// template <class T>
// void AVLtree<T>::treeDeletePrint(T key){
//     std::cout << "\nAVL Delete: " << key << "\n";
//     AVLNode<T> *position = treeSearch(root_, key);
//     if (position == NULL){
//         std::cout << "You key does not in the BST\n";
//     }
//     else{
//         // treeDelete(position);
//         treeDelete(position);
//         inorderTreeWalk();
//     }
// }

// --------------------------------------------------
//           Main function
// --------------------------------------------------


template class AVLtree<int>;