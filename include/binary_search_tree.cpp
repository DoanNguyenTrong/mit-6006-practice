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
template <class T, typename Node_>
BStree<T, Node_>::BStree(){
    root_ = NULL;
}

// // --------------------------------------------------
// //               Build Tree
// // --------------------------------------------------

// Create a new BST Node
template <class T, typename Node_>
Node_ *BStree<T, Node_>::newNode (T key){
    Node_ *temp = new Node_;
    temp->key_ = key;
    temp->left_ =temp->right_ = temp->parent_ = NULL;
    return temp;
}
// Insert a Node to the BST
template <class T, typename Node_>
void BStree<T, Node_>::treeInsert(Node_ *z){
    Node_ *y = NULL;
    Node_ *x = root_;
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
template <class T, typename Node_>
void BStree<T, Node_>::makeTreeFromArr(T arr[], int N){\
    for (int i = 0; i < N; i++){
        Node_ *temp = newNode(arr[i]);
        treeInsert(temp);
    }
}

// // --------------------------------------------------
//          Tree travesal and print in sorted order
// // --------------------------------------------------
template <class T, typename Node_>
void BStree<T, Node_>::inorder(Node_ *root){
    if (root != NULL){
        inorder(root->left_);
        std::cout << root->key_ << " ";
        inorder(root->right_);
    }
}

template <class T, typename Node_>
void BStree<T, Node_>::inorderTreeWalk (){
    inorder(root_);
}


// --------------------------------------------------
//          3. Tree travesal and searh for a key
// // --------------------------------------------------
template <class T, typename Node_>
Node_ *BStree<T, Node_>::treeSearch (Node_ *root, T key){
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
template <class T, typename Node_>
void BStree<T, Node_>::treeSearchPrint(T key){
    std::cout << "\nSearch " << key << ": ";
    Node_ *pos = treeSearch(root_, key);
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
template <class T, typename Node_>
Node_ *BStree<T, Node_>::treeMin(Node_ *root){
    while (root->left_ != NULL){
        root = root->left_;
    }
    return root;
}

template <class T, typename Node_>
Node_ *BStree<T, Node_>::treeMax(Node_ *root){
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
template <class T, typename Node_>
Node_ *BStree<T, Node_>::treeSuccessor(Node_ *position){
    if (position->right_ != NULL){
        return treeMin(position->right_);
    }
    else{
        Node_ *curr = position;
        Node_ *par = curr->parent_;
        while (par != NULL && par->right_ == curr){
            curr = par;
            par = curr->parent_;
        }
        return par;
    }
}   

template <class T, typename Node_>
void BStree<T, Node_>::treeSuccPrint(T key){
    std::cout << "\nSuccessor of " << key << ": ";
    Node_ *pos = treeSearch(root_, key);
    if (pos == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        Node_ *succ = treeSuccessor(pos);
        std::cout << " Successor value: " << succ->key_ << "\n";
    }
}


// // Predeccessor of a node x is the node with
// // the greatest key smaller than x:key
template <class T, typename Node_>
Node_ *BStree<T, Node_>::treePredecessor(Node_ *position){
    if (position->left_ != NULL){
        return treeMax(position->left_);
    }
    else{
        Node_ *curr = position;
        Node_ *par = curr->parent_;
        while (par != NULL && curr == par->left_){
            curr = par;
            par = curr->parent_;
        }
        return par;
    }
}

template <class T, typename Node_>
void BStree<T, Node_>::treePredesPrint(T key){
    std::cout << "\nPredeccessor of " << key << ": ";
    Node_ *position = treeSearch(root_, key);
    if (position == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        Node_ *predes = treePredecessor(position);
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
template <class T, typename Node_>
void BStree<T, Node_>::transplant(Node_ *u, Node_ *v){
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

template <class T, typename Node_>
void BStree<T, Node_>::treeDelete(Node_ *z){
    if (z->left_ == NULL){
        transplant(z, z->right_);
    }
    else if (z->right_ == NULL){
        transplant(z, z->left_);
    }
    else{
        Node_ *y = treeMin(z->right_);
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

template <class T, typename Node_>
void BStree<T, Node_>::treeDeletePrint(T key){
    std::cout << "\nDelete: " << key << "\n";
    Node_ *position = treeSearch(root_, key);
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
//           Main function
// --------------------------------------------------

void binary_search(int arr[], int N){
    BStree<int, Node<int> > tree;
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
template class BStree<int, Node<int> >;