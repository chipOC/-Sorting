/********************************************************************************************
 **    Project: Sort
 **  Programmer: Kainalu Estrella
 **  Course:        cs2420
 **    Section:    001
 **    Assignment: 5
 **    Data:        Sept 12, 2018
 **
 **    I certify that I wrote all code in this project except that which was
 **    provided by the instructor.
 **
 ***********************************************************************************************/

#include <iostream>
#include "Sort.hpp"
#include "Timer.hpp"
#include <algorithm>


using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;



    
    



int main()
{
    Sort sort(100000);
    sort.InitArray();
    Timer ti;
    sort.InitArray();
    
    cout<<"starting SelectionSort"<<endl;
    ti.Start();
    sort.SelectionSort();
    ti.End();
    unsigned ssTimer = ti.DurationInMicroSeconds();
    cout<<"Selection Sort duration: "<<ssTimer<<endl;
    
    cout<<"starting InsertionSort"<<endl;
    sort.InitArray();
    ti.Start();
    sort.InsertionSort();
    ti.End();
    unsigned isTimer = ti.DurationInMicroSeconds();
    cout<<"Insertion Sort duration: "<<isTimer<<endl;
    
    cout<<"starting MergeSort"<<endl;
    sort.InitArray();
    ti.Start();
    sort.MergeSort();
    ti.End();
    unsigned msTimer = ti.DurationInMicroSeconds();
    cout<<"Insertion Sort duration: "<<msTimer<<endl;

    cout<<"starting QuickSort"<<endl;
    ti.Start();
    sort.QuickSort();
    ti.End();
    unsigned qsTimer = ti.DurationInMicroSeconds();
    cout<<"Quick Sort duration: "<<qsTimer<<endl;
    
    cout<<"starting std:: sort()"<<endl;
    ti.Start();
    sort.AlgorithmSort();
    ti.End();
    unsigned asTimer = ti.DurationInMicroSeconds();
    cout<<"Algorithm Sort duration: "<<asTimer<<endl;
    
   
    
    
    
   
    
 return 0;
}


