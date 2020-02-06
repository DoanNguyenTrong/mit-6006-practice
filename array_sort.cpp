#include <iostream>

#include "array_sort.h"

// macros for heap
#define PARENT(i) ((int)(i/2))
#define LEFT_CHILD(i) (2*i)
#define RIGHT_CHILD(i)(2*i+1)


Search::Search(int arr[], const int N): N_(N){
     std::copy(arr, arr + N, arr_);
}

void Search::printArray(){
     std::cout << "Print Array     " << std::endl;
     for (int i= 0; i < N_; i++){
          std::cout << i << ": " << arr_[i] << "\n";
     }
     std::cout << std::endl;
}
// -----------------------------------------------------------
//                       INSERTION SORT
// -----------------------------------------------------------
void Search::swap(int i, int j){
     int temp = arr_[i];
     arr_[i] = arr_[j];
     arr_[j] = temp;
}

// Complexity: O(n^2)
void Search::insertionSort(){
     for(int i=1; i < N_; i++){
          int key = arr_[i];
          int j = i - 1;
          // Pop the items before have index i down to make room for it
          while(j >= 0 && arr_[j] > key){
               swap(j+1, j);
               j--;
          }
          // Put it in 
          arr_[j+1] = key;
     }
}
// -----------------------------------------------------------
//                       MERGE SORT
// -----------------------------------------------------------
void Search::merge(int l, int m, int r){
     // Length of two arrays
     int n1 = m - l + 1;
     int n2 = r - m;

     // Create temp arrays and copy data to that array
     int L[n1], R[n2];
     for (int i = 0; i < n1; i++){
          L[i] = arr_[l + i];
     }
     for (int i = 0; i < n2; i++){
          R[i] = arr_[m + 1 + i];
     }

     // Merge the temp arrays back to original arr_
     int i = 0, j = 0, k = l;
     while (i < n1 && j < n2){
          if (L[i] <= R[j]){
               arr_[k] = L[i];
               i++;
          }else{
               arr_[k] = R[j];
               j++;
          }
          k++;
     }
     // Copy the remains in two temp arrays back
     while (i < n1){
          arr_[k] = L[i];
          k++;
          i++;
     }

     while (j < n2){
          arr_[k] = R[j];
          k++;
          j++;
     }
}
void Search::merge_sort(int l, int r){
     if (l < r){
          int m = l + (r - l)/2;
          merge_sort(l, m);
          merge_sort(m+1, r);
          merge(l, m, r);
     }
}

// Complexity: O(n.logn)
void Search::mergeSort(){
     merge_sort(0, N_);
}

// -----------------------------------------------------------
//                       HEAP SORT
// -----------------------------------------------------------
void Search::maxHeapify(int i, int heap_size){
     int l = LEFT_CHILD(i);
     int r = RIGHT_CHILD(i);
     int largest = i;
     if (l < heap_size && arr_[l] > arr_[largest]){
          largest = l;
     }
     if (r < heap_size && arr_[r] > arr_[largest]){
          largest = r;
     }
     if (largest != i){
          swap(i, largest);
          maxHeapify(largest, heap_size);
     }
}

void Search::buildMaxHeap(){
     for (int i = N_/2; 0 <= i; i--){
          maxHeapify(i, N_);
     }
}
// Complexity: O(n.logn)
// Combine the advantage of insertion + merge sorts
void Search::heapSort(){
     buildMaxHeap();
     int heap_size = N_;
     for (int i = N_ - 1; 0 < i; i--){
          // Gradually heapify to make arr_[0] is the largest of the array
          // then push it back to the end.
          swap(0, i); 
          heap_size--;
          maxHeapify(0, heap_size);
     }
}