#include <random>
#include <algorithm>
#include "Sort.hpp"
#include <iostream>


using namespace std;



Sort::Sort(int size)
{
    this->size = size;
    data = new int [size];
}


Sort::~Sort()
{
    delete [] data;
}

void Sort:: AlgorithmSort()
{
    sort(data, data + size);
   
}


void Sort::InitArray() //Function to initialize the array unsorted random data
{
    srand(0); //call srand(0) before initializing to get the same data each time
    
    for (int i = 0; i < size; i++)
    {
        data[i] = rand()%50;
    }
    
    
}

void Sort:: SelectionSort()
{
    int current = 0; // current number
    int next = 0; // next number
    int temp = 0;// temp value for swap
    int size= GetSize();
    int* data = GetDataArray();
    //InitArray();
    
    for (current = 0; (current < size); ++current) // for the size of the array
    {
        int smallest = current; // smallest number = current to start
        for (next = current +1; next< size; ++next)// // for from the second
        {
            if (data[next] < data[smallest] ) { //if the next is smaller that the current
                smallest = next;  //set smallest to next
            }
        }
        temp = data[current];//
        data[current] = data[smallest];
        data[smallest] = temp;
        
    }
    //printarray();
}

void Sort::InsertionSort()
{
    int counter = 0;
    int eval = 0;
    int temp = 0;
    int size= GetSize();
    int* data = GetDataArray();
    for (counter =0; counter<size; counter++)
    {
        eval = counter;
        while (eval>0 and data[eval]<data[eval-1])
        {
            temp = data[eval];
            data[eval] = data[eval - 1];
            data[eval - 1] = temp;
            --eval;
        }
        
    }
    //printarray();
}

void Sort:: MergeSort()
{
    int size= GetSize();
    MergeSortRecursionHelper(0,size-1);
    //printarray();
    
}
void Sort::MergeSortRecursionHelper(int low, int high)
{
    RecursionCounter rcTmp;    // used for Unit Testing. DO NOT REMOVE
    if (low< high) //find midpoint
    {
        int mid = (high+low)/2; //find midpoint
        MergeSortRecursionHelper(low, mid);// splits first half
        MergeSortRecursionHelper(mid+1 ,high); //splots second hAlF
        
        Merge(low,mid,high);//calls merge to sort and merge data
    }

}

void Sort:: Merge(int low,int mid,int high)
{
    int mergedSize = high-low+1;
    int *temp = new int[mergedSize];
    int counter = 0;
    
    
    int firstlow = low;
    int secondlow = mid + 1;
 
    
    
    // Add smallest element from left or right partition to merged data
    while (firstlow <= mid && secondlow <= high) {
        if (data[firstlow] <= data[secondlow]) {
            temp[counter] = data[firstlow];
            ++firstlow;
        }
        else {
            temp[counter] = data[secondlow];
            ++secondlow;
            
        }
        ++counter;
    }
    
    // If left partition is not empty, add remaining elements to merged data
    while (firstlow <= mid) {
        temp[counter] = data[firstlow];
        ++firstlow;
        ++counter;
    }
    
    // If right partition is not empty, add remaining elements to merged data
    while (secondlow <= high) {
        temp[counter] = data[secondlow];
        ++secondlow;
        ++counter;
    }
    
    // Copy merge number back to data
    for (counter = 0; counter < mergedSize; ++counter) {
        data[low + counter] = temp[counter];
    }
}
   


int Sort:: Partition(int low, int high)
{
    int mid = (high+low)/2; // find middle element
    swap(data[mid],data[high]);
    int temp = data[high];
    data[high]= data[mid];
    data[mid]= temp;
    int pivot = data[high];
    int next=(low-1);
    for (int i = low; i<high; i++)
    {
        //int next = low;
        if (data[i] < pivot)
        {
            next++;

            swap(data[next], data[i]);
        }


    }
    swap(data[next+1], data[high]);


    return next+1;
}


void Sort::QuickSort()
{
    int size = GetSize();
    QuickSortRecursionHelper(0,size-1);
    //printarray();
}


void Sort::QuickSortRecursionHelper(int low, int high)
{
    RecursionCounter rcTmp;    // used for Unit Testing. DO NOT REMOVE
    if (low >= high)
    {
        return;
    }
    // add more code here
    int p =Partition(low, high);
    QuickSortRecursionHelper(low,p-1);
    QuickSortRecursionHelper(p+1,high);
    
}

void Sort::printarray()
{
    for (int i =0; i<size; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

