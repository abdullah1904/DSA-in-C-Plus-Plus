#include <iostream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
using namespace std;
int main(){
    const int size = 5;
    int arr[size] = {425,947,463,130,901};
    dSelectionSort(arr,size);
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<"\t";
    } 
    return 0;
}