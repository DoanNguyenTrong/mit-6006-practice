#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

template <class T>
struct Node
{
    T key_;
    Node *left_, *right_, *parent_;
};

template <class T>
class BStree{
    public:
    BStree();
    void makeTreeFromArr(T [], int);
    void inorderTreeWalk();
    void treeSearchPrint(T);
    void treeSuccPrint(T);
    void treePredesPrint(T);
    void treeDeletePrint(T);

    private:
    Node<T> *root_;
    // Make tree
    Node<T> *newNode(T);
    void treeInsert(Node<T> *);
    // print ordered
    void inorder(Node<T> *);
    // Search for a key
    Node<T> *treeSearch(Node<T> *, T);
    // Min-Max
    Node<T> *treeMin(Node<T> *);
    Node<T> *treeMax(Node<T> *);
    // Find Successor and Predecessor
    Node<T> *treeSuccessor(Node<T> *);
    Node<T> *treePredecessor(Node<T> *);
    // Delete
    void transplant(Node<T> *, Node<T> *);
    void treeDelete(Node<T> *);

    
};

#endif // #define BINARY_SEARCH_TREE_