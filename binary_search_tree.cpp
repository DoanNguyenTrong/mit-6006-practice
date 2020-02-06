#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <iostream>

struct Node
{
    int key_;
    Node *left_, *right_, *parent_;
};


// Create a new BST Node
Node *newNode (int key){
    Node *temp = new Node;
    temp->key_ = key;
    temp->left_ =temp->right_ = temp->parent_ = NULL;
    return temp;
}

// --------------------------------------------------
// 1. Insert a Node to the BST
// Node *treeInsert (Node *node, int key){
//     if (node == NULL) return newNode(key);
//     if (key <= node->key_){
//         Node *lchild = treeInsert(node->left_, key);
//         node->left_ = lchild;
//         lchild->parent_ = node;
//     }
//     else if (key > node->key_){
//         Node *rchild = treeInsert(node->right_, key);
//         node->right_ = rchild;
//         rchild->parent_ = node;
//     }
//     return node;
// }

Node *treeInsert(Node *root, Node *z){
    Node *y = NULL;
    Node *x = root;
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
        root = z;
    }
    else if (z->key_ < y->key_){
        y->left_ = z;
    }
    else {
        y->right_ = z;
    }
    return root;
}

Node *makeTreeFromArr(int arr[], int N){
    Node *root = NULL;
    
    for (int i = 0; i < N; i++){
        Node *temp = newNode(arr[i]);
        root = treeInsert(root, temp);
    }
    return root;
}


// Stores inoder traversal of the BST in arr[]
void storeSorted (Node *root, int arr[], int &i){
    if (root != NULL){
        storeSorted(root->left_, arr, i);
        arr[i++] = root->key_;
        storeSorted(root->right_, arr, i);
    }
}


// Tree travesal and print in sorted order
void inorderTreeWalk (Node *root){
    if (root != NULL){
        inorderTreeWalk(root->left_);
        std::cout << root->key_ << " ";
        inorderTreeWalk(root->right_);
    }
}

// --------------------------------------------------
// 3. Tree travesal and searh for a key
Node *treeSearch(Node *root, int key){
    if (root == NULL || root->key_ == key){
        // if (root->key_ == key){
        //     std::cout << "---" << root->key_ << ":" << key << "--";
        // }
        return root;
    }
    if (root->key_ > key){
        return treeSearch(root->left_, key);
    }
    else if(root->key_ < key){
        return treeSearch(root->right_, key);
    }
}

// Search throgh the BST to find whether the key is founded?
void treeSearchPrint(Node *root, int key){
    std::cout << "\nSearch " << key << ": ";
    Node *position = treeSearch(root, key);
    if (position != NULL){
        std::cout << "Founded!";
    }
    else{
        std::cout << "NOT Founded!";
    }
}


// --------------------------------------------------
// 4. Tree Minimum and Maximum
Node *treeMin(Node *root){
    while (root->left_ != NULL){
        root = root->left_;
    }
    return root;
}

Node *treeMax(Node *root){
    while (root->right_ != NULL){
        root = root->right_;
    }
    return root;
}

// --------------------------------------------------
// 5. BST find Successor and Predecessor
// successor of a node x is the node with
// the smallest key greater than x:key
Node *treeSuccessor(Node *position){
    if (position->right_ != NULL){
        return treeMin(position->right_);
    }
    else{
        Node *curr = position;
        Node *par = curr->parent_;
        while (par != NULL && par->right_ == curr){
            curr = par;
            par = curr->parent_;
        }
        return par;
    }
}   

void treeSuccPrint(Node *root, int key){
    std::cout << "\nSuccessor of " << key << ": ";
    Node *position = treeSearch(root, key);
    if (position == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        Node *succ = treeSuccessor(position);
        std::cout << " Successor value: " << succ->key_ << "\n";
    }
}

// Predeccessor of a node x is the node with
// the greatest key smaller than x:key
Node *treePredecessor(Node *position){
    if (position->left_ != NULL){
        return treeMax(position->left_);
    }
    else{
        Node *curr = position;
        Node *par = curr->parent_;
        while (par != NULL && curr == par->left_){
            curr = par;
            par = curr->parent_;
        }
        return par;
    }
}

void treePredesPrint(Node *root, int key){
    std::cout << "\nPredeccessor of " << key << ": ";
    Node *position = treeSearch(root, key);
    if (position == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        Node *predes = treePredecessor(position);
        std::cout << " Predeccessor value: " << predes->key_ << "\n";
    }
}

// --------------------------------------------------
// 2. Delete a Node from the tree
// transplant() create a connection between parent of u
// and v
// u->parent->child = v
// v->parent = u->parent

void transplant(Node *root, Node *u, Node *v){
    if (u->parent_ == NULL){
        root = v;
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
    delete u;
}

void treeDelete(Node *root, Node *z){
    if (z->left_ == NULL){
        transplant(root, z, z->right_);
    }
    else if (z->right_ == NULL){
        transplant(root, z, z->left_);
    }
    else{
        Node *y = treeMin(z->right_);
        if (y != z->right_){
            transplant(root, y, y->right_);
            y->right_ = z->right_;
            y->right_->parent_ = y;
        }
        transplant(root, z, y);
        y->left_ = z->left_;
        y->left_->parent_ = y;
    }
}
void treeDeletePrint(Node * root, int key){
    std::cout << "\nDelete: " << key << "\n";
    Node *position = treeSearch(root, key);
    if (position == NULL){
        std::cout << "You key does not in the BST\n";
    }
    else{
        // treeDelete(position);
        treeDelete(root, position);
        inorderTreeWalk(root);
    }
}


#endif // #define BINARY_SEARCH_TREE_