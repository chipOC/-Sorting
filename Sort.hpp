#ifndef __SORT__
#define __SORT__

#include "RecursionCounter.hpp"
class Sort
{
public:
    // add code here
    Sort(int size);
    ~Sort();
    void InitArray();
    
    void SelectionSort();
    void InsertionSort();
    void AlgorithmSort();
    void MergeSort();
    void Merge(int low,int mid,int high);
    void QuickSort();
    int Partition(int high, int low);
    
    int GetSize() const
    {
        return size;
    };
    
    int *GetDataArray() const
    {
        return data;
    };
    
    void printarray();

private:
    // add code here
    
    void MergeSortRecursionHelper(int indexI, int indexK);
    void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
    int size;
    int * data;
};

#endif
