#include "red_black_tree.h"

// Constructor
RedBlackTree::RedBlackTree(){
    TNULL_ = new RBNode;
    TNULL_->key_ = INT_MIN;
    TNULL_->color_ = BLACK;
    TNULL_->left_ = TNULL_->right_ = TNULL_->parent_ = NULL;
    root_ = TNULL_;
}

void RedBlackTree::leftRotate(RBNode *x){
    RBNode *y = x->right_;
    x->right_ = y->left_;
    if (y->left_ != TNULL_){
        y->left_->parent_ = x;
    }
    y->parent_ = x->parent_;
    if (x->parent_ == TNULL_){
        root_ = y;
    }
    else if (x = x->parent_->left_){
        x->parent_->left_ = y;
    }
    else{
        x->parent_->right_ = y;
    }
    y->left_ = x;
    x->parent_ = y;
}

void RedBlackTree::rightRotate(RBNode *y){
    RBNode *x = y->left_;
    y->left_ = x->right_;
    if (x->right_ != TNULL_){
        x->right_->parent_ = y;
    }
    x->parent_ = y->parent_;
    if (y->parent_ == TNULL_){
        root_ = x;
    }
    else if (y = y->parent_->left_){
        y->parent_->left_ = x;
    }
    else{
        y->parent_->right_ = x;
    }
    x->right_ = y;
    y->parent_ = x;
}

void RedBlackTree::RBInsert(RBNode *z){
    RBNode *y = TNULL_;
    RBNode *x = root_;
    
    while (x != TNULL_){
        y = x;
        if (z->key_ < x->key_){
            x = x->left_;
        }
        else{
            x = x->right_;
        }
    }
    z->parent_ = y;
    if (y == TNULL_){
        root_ = z;
    }
    else if (z->key_ < y->key_){
        y->left_ = z;
    }
    z->left_ = TNULL_;
    z->right_ = TNULL_;
    z->color_ = RED;
    RBInsertFixUp(z);
}

void RedBlackTree::RBInsertFixUp (RBNode *z){
    while (z->parent_->color_ == RED){
        if (z->parent_ == z->parent_->parent_->left_){
            /* If x's parent is a left, y is x's right 'uncle' */
            RBNode *y = z->parent_->parent_->right_;
            if (y->color_ == RED){
                /* case 1 - change the colours */
                z->parent_->color_ = BLACK;
                y->color_ = BLACK;
                z->parent_->parent_->color_ = RED;
                /* Move x up the tree */
                z = z->parent_->parent_;
            }
            else {
                /* y is a black node */
                if (z = z->parent_->right_){
                    /* and x is to the right */ 
                   /* case 2 - move x up and rotate */
                    z = z->parent_;
                    leftRotate(z);
                }
                /* case 3 */
                z->parent_->color_ = BLACK;
                z->parent_->parent_->color_ = RED;
                rightRotate(z->parent_->parent_);
            }
        }
        else{
            // The process is the same, with opposite side
            // right_ and left_ are exchanged
            RBNode *y = z->parent_->parent_->left_;
            if (y->color_ == RED){
                z->parent_->color_ = BLACK;
                y->color_ = BLACK;
                z->parent_->parent_->color_ = RED;
                z = z->parent_->parent_;
            }
            else {
                if (z = z->parent_->left_){
                    z = z->parent_;
                    leftRotate(z);
                }
                z->parent_->color_ = BLACK;
                z->parent_->parent_->color_ = RED;
                rightRotate(z->parent_->parent_);
            }
        }
    }
    root_->color_ = BLACK;
}

void RedBlackTree::RBTransplant(RBNode *u, RBNode *v){
    if (u->parent_ == TNULL_){
        root_ = v;
    }
    else if(u = u->parent_->left_){
        u->parent_->left_ = v;
    }
    else{
        u->parent_->right_ = v;
    }
    v->parent_ = u->parent_;
}

void RedBlackTree::RBDelete(RBNode *z){
    RBNode *y = z;
    
}