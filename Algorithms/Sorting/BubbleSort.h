#ifndef BubbleSort
#define BubbleSort

template <class t>
void aBubbleSort(t arr[], int size){
    for(int i =0; i<size-1;i++){
        for(int j =0; j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                t temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <class t>
void dBubbleSort(t arr[], int size){
    for(int i =0; i<size-1;i++){
        for(int j =0; j<size-i-1;j++){
            if(arr[j]<arr[j+1]){
                t temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

#endif