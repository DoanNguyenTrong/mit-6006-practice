// // -----------------------------------------------------------
// //                       STRUCTURE
// // - Basic operations: Constructor/Destructor, make tree from array[]
// // - insertion Sort
// // - merge Sort
// // - heap Sort
// // - main 
// // -----------------------------------------------------------

#include <iostream>

#include "binary_search_tree.h"

// Constructor
template <class T>
BStree<T>::BStree(){
    root_ = NULL;
}

// // --------------------------------------------------
// //               Build Tree
// // --------------------------------------------------

// Create a new BST Node
template <class T>
Node<T> *BStree<T>::newNode (T key){
    Node<T> *temp = new Node<T>;
    temp->key_ = key;
    temp->left_ =temp->right_ = temp->parent_ = NULL;
    return temp;
}
// Insert a Node to the BST
template <class T>
void BStree<T>::treeInsert(Node<T> *z){
    Node<T> *y = NULL;
    Node<T> *x = root_;
    // Travel throght the BST down to the leaf that associated with new node z
    while (x != NULL){
        y = x;
        if (z->key_ < x->key_){
            x = x->left_;
        }
        else{
            x = x->right_;
        }
    }
    // Attach z to the BST
    z->parent_ = y; 
    if (y == NULL){
        root_ = z;
    }
    else if (z->key_ < y->key_){
        y->left_ = z;
    }
    else {
        y->right_ = z;
    }
}
template <class T>
void BStree<T>::makeTreeFromArr(T arr[], int N){\
    for (int i = 0; i < N; i++){
        Node<T> *temp = newNode(arr[i]);
        treeInsert(temp);
    }
}

// // --------------------------------------------------
//          Tree travesal and print in sorted order
// // --------------------------------------------------
template <class T>
void BStree<T>::inorder(Node<T> *root){
    if (root != NULL){
        inorder(root->left_);
        std::cout << root->key_ << " ";
        inorder(root->right_);
    }
}

template <class T>
void BStree<T>::inorderTreeWalk (){
    inorder(root_);
}


// --------------------------------------------------
//          3. Tree travesal and searh for a key
// // --------------------------------------------------
template <class T>
Node<T> *BStree<T>::treeSearch (Node<T> *root, T key){
    if (root == NULL || root->key_ == key){
        // if (root->key_ == key){
        //     std::cout << "---" << root->key_ << ":" << key << "--";
        // }
        return root;
    }
    if (root->key_ > key){
        return treeSearch(root->left_, key);
    }
    else{
        return treeSearch(root->right_, key);
    }
}

// Search throgh the BST to find whether the key is founded?
template <class T>
void BStree<T>::treeSearchPrint(T key){
    std::cout << "\nSearch " << key << ": ";
    Node<T> *pos = treeSearch(root_, key);
    if (pos != NULL){
        std::cout << "Founded!";
    }
    else{
        std::cout << "NOT Founded!";
    }
}

// // --------------------------------------------------
// // 4. Tree Minimum and Maximum
// // --------------------------------------------------
template <class T>
Node<T> *BStree<T>::treeMin(Node<T> *root){
    while (root->left_ != NULL){
        root = root->left_;
    }
    return root;
}

template <class T>
Node<T> *BStree<T>::treeMax(Node<T> *root){
    while (root->right_ != NULL){
        root = root->right_;
    }
    return root;
}

// // --------------------------------------------------
// //       find Successor and Predecessor
// // --------------------------------------------------
// // successor of a node x is the node with
// // the smallest key greater than x:key
template <class T>
Node<T> *BStree<T>::treeSuccessor(Node<T> *position){
    if (position->right_ != NULL){
        return treeMin(position->right_);
    }
    else{
        Node<T> *curr = position;
        Node<T> *par = curr->parent_;
        while (par != NULL && par->right_ == curr){
            curr = par;
            par = curr->parent_;
        }
        return par;
    }
}   

template <class T>
void BStree<T>::treeSuccPrint(T key){
    std::cout << "\nSuccessor of " << key << ": ";
    Node<T> *pos = treeSearch(root_, key);
    if (pos == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        Node<T> *succ = treeSuccessor(pos);
        std::cout << " Successor value: " << succ->key_ << "\n";
    }
}


// // Predeccessor of a node x is the node with
// // the greatest key smaller than x:key
template <class T>
Node<T> *BStree<T>::treePredecessor(Node<T> *position){
    if (position->left_ != NULL){
        return treeMax(position->left_);
    }
    else{
        Node<T> *curr = position;
        Node<T> *par = curr->parent_;
        while (par != NULL && curr == par->left_){
            curr = par;
            par = curr->parent_;
        }
        return par;
    }
}

template <class T>
void BStree<T>::treePredesPrint(T key){
    std::cout << "\nPredeccessor of " << key << ": ";
    Node<T> *position = treeSearch(root_, key);
    if (position == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        Node<T> *predes = treePredecessor(position);
        std::cout << " Predeccessor value: " << predes->key_ << "\n";
    }
}

// --------------------------------------------------
//           Delete a Node from the tree
// --------------------------------------------------
// transplant() create a connection between parent of u
// and v
// u->parent->child = v
// v->parent = u->parent
template <class T>
void BStree<T>::transplant(Node<T> *u, Node<T> *v){
    if (u->parent_ == NULL){
        root_ = v;
    }
    else if(u == u->parent_->left_){
        u->parent_->left_ = v;
    }
    else{
        u->parent_->right_ = v;
    }
    if (v != NULL){
        v->parent_ = u->parent_;
    }
}

template <class T>
void BStree<T>::treeDelete(Node<T> *z){
    if (z->left_ == NULL){
        transplant(z, z->right_);
    }
    else if (z->right_ == NULL){
        transplant(z, z->left_);
    }
    else{
        Node<T> *y = treeMin(z->right_);
        if (y != z->right_){
            transplant(y, y->right_);
            y->right_ = z->right_;
            y->right_->parent_ = y;
        }
        transplant(z, y);
        y->left_ = z->left_;
        y->left_->parent_ = y;
    }
    delete z;
}

template <class T>
void BStree<T>::treeDeletePrint(T key){
    std::cout << "\nDelete: " << key << "\n";
    Node<T> *position = treeSearch(root_, key);
    if (position == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        // treeDelete(position);
        treeDelete(position);
        inorderTreeWalk();
    }
}

// --------------------------------------------------
//           Delete a Node from the tree
// --------------------------------------------------

void binary_search(int arr[], int N){
    BStree<int> tree;
    tree.makeTreeFromArr(arr, N);
    
    std::cout << "Tree travesal: ";
    tree.inorderTreeWalk();

    int val = 70;
    tree.treeSearchPrint(val);
    tree.treeSuccPrint(val);
    tree.treePredesPrint(val);
    tree.treeDeletePrint(val);
}

//   AVOID linker error in template class
template class BStree<int>;