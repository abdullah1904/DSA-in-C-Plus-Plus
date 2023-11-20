#ifndef InsertionSort
#define InsertionSort

template <class t>
void aInsertionSort(t arr[], int size){
    for(int i = 1;i<size;i++){
        t temp = arr[i];
        int j = i - 1;
        while(j>=0 && temp<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

template <class t>
void dInsertionSort(t arr[], int size){
    for(int i = 1;i<size;i++){
        t temp = arr[i];
        int j = i - 1;
        while(j>=0 && temp>arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}







#endif