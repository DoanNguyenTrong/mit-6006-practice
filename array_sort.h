#ifndef SEARCH_H_
#define SEARCH_H_

class Search{
     public:
     const int N_;
     
     int arr_[];

     void printArray();

     void swap(int i, int j);
     void insertionSort();

     void mergeSort();
     void merge_sort(int l, int r);
     void merge(int l, int m, int r);

     void maxHeapify(int i, int heap_size);
     void buildMaxHeap();
     void heapSort();
     // Constructor
     Search(int arr[], int N);
};

#endif // SEARCH_H_