#ifndef SelectionSort
#define SelectionSort

template <class t>
void aSelectionSort(t arr[], int size){
    for(int i = 0;i<size-1;i++){
        int index = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        t temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

template <class t>
void dSelectionSort(t arr[], int size){
    for(int i = 0;i<size-1;i++){
        int index = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]>arr[index]){
                index = j;
            }
        }
        t temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

#endif