#include <iostream>

#include "include/array_sort.h"
#include "include/binary_search_tree.cpp"
// #include "include/avl_tree.cpp"


// void array_sort(int [],const int );

// void binary_search(int [], const int);

// void avl_tree_search(int arr[], const int N){
//     std::cout << "AVL tree\n";
//     AVLtree<int> t;
//     for (int i = 0; i < N; i++){
//         std::cout << i << " : " << arr[i] << "-";
//         AVLNode<int> *temp = newAVLNode(arr[i]);
//         t.treeInsert(temp);
        
//     }
//     std::cout << "Finish Insertion!\n";
//     t.inorderTreeWalk();

//     t.treeDeletePrint(30);
//     // t.inorderTreeWalk();

    
// }

int main()
{   
    // int arr[] = {12, 11, 13, 5, 6, 7 ,222, 435, 65, 19, 3, 4, 219, 4353,1231, 456, 870, 111, 85, 96, 2, 32};
    int arr[] = {100, 70, 30, 3, 2, 4, 75, 80, 77};
    int *ptr_arr = arr;
    const int N = sizeof(arr)/sizeof(arr[0]);

    // array_sort(arr, N);
    binary_search(arr, N);

    // avl_tree_search(arr, N);
    std::cout << "END" << std::endl;
    return 0;
}
