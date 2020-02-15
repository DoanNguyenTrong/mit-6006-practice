#ifndef ArraySort_H_
#define ArraySort_H_

template <class T>
class ArraySort{
     public:
     // Constructor
     ArraySort(T *, int N);
     ~ArraySort();
     
     void printArray();
     void insertionSort();
     void mergeSort();
     void heapSort();

     private:
     const int N_;
     T *arr_;

     // 1. Insertion Sort
     void swap(T i, T j);

     // 2. Merge Sort
     void merge_sort(int l, int r);
     void merge(int l, int m, int r);

     // 3. Heap Sort
     void maxHeapify(int, int);
     void buildMaxHeap();
};

#endif // ArraySort_H_