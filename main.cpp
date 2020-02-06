#include <iostream>
// #include <array>

#include "array_sort.h"
#include "binary_search_tree.cpp"
#include "avl_tree.cpp"

void array_search(int arr[], int N){
    Search S(arr, N);
    S.printArray();
    // S.insertionSort();
    // S.mergeSort();
    S.heapSort();
    S.printArray();
}

void binary_search(int arr[], int N){
    Node *root = makeTreeFromArr(arr, N);
    
    std::cout << "Tree travesal: ";
    inorderTreeWalk(root);

    int val = 70;
    
    treeSuccPrint(root, val);
    treePredesPrint(root, val);
    treeDeletePrint(root, val);
}

void avl_tree_search(int arr[], const int N){
    std::cout << "AVL tree\n";
    AVLtree<int> t;
    for (int i = 0; i < N; i++){
        std::cout << i << " : " << arr[i] << "-";
        AVLNode<int> *temp = newAVLNode(arr[i]);
        t.treeInsert(temp);
        
    }
    std::cout << "Finish Insertion!\n";
    t.inorderTreeWalk();
    
}

int main()
{   
    // int arr[] = {12, 11, 13, 5, 6, 7 ,222, 435, 65, 19, 3, 4, 219, 4353,1231, 456, 870, 111, 85, 96, 2, 32};
    int arr[] = {100, 70, 30, 3, 2, 4, 75, 80, 77};
    const int N = sizeof(arr)/sizeof(arr[0]);
    // array_search(arr, N);
    // binary_search(arr, N);

    avl_tree_search(arr, N);
    std::cout << "END" << std::endl;
    return 0;
}
