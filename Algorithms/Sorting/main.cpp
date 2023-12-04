#include <iostream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
using namespace std;
int main(){
    const int size = 10;
    int arr[size] = {1980,17523,425,947,463,130,901,1905,2215,100};
    dMergeSort(arr,size);
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<"\t";
    } 
    return 0;
}